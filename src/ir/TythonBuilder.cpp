#include <iostream>
#include "../../include/ir/TythonBuilder.h"
#include "../../include/utils/Utils.h"
#include "../../include/exception/CompileException.h"

void TythonBuilder::init() {

    // create global scope
    this->current_scope = new Scope();

    llvm::Type* int8_t = llvm::Type::getInt8Ty(this->getContext());
    llvm::Type* int8ptr_t = llvm::Type::getInt8PtrTy(this->getContext());
    llvm::Type* ptr_t = llvm::PointerType::get(this->getContext(), 0); // opaque pointer type

    // variable type

    llvm::ArrayRef<llvm::Type*> variable_types = {
            int8ptr_t,  //name
            ptr_t,      // value ptr
    };

    this->variableStructType = llvm::StructType::create(this->getContext(), variable_types, "Variable");

    // primitive value types

    llvm::ArrayRef<llvm::Type*> int_types = {
            int8_t,     // type
            getLLVMType(tython::Type::INTEGER),    // content
    };

    auto intType = llvm::StructType::create(this->getContext(), int_types, "Value.Int");
    this->typeMap.insert({ tython::Type::INTEGER, intType });

    llvm::ArrayRef<llvm::Type*> fp_types = {
            int8_t,     // type
            getLLVMType(tython::Type::FP),    // content
    };

    auto fpType = llvm::StructType::create(this->getContext(), fp_types, "Value.FP");
    this->typeMap.insert({ tython::Type::FP, fpType });

    llvm::ArrayRef<llvm::Type*> string_types = {
            int8_t,     // type
            getLLVMType(tython::Type::STRING),    // content
    };

    auto stringType = llvm::StructType::create(this->getContext(), string_types, "Value.String");
    this->typeMap.insert({ tython::Type::STRING, stringType });

    llvm::ArrayRef<llvm::Type*> none_types = {
            int8_t,     // type
    };

    auto noneType = llvm::StructType::create(this->getContext(), none_types, "Value.None");
    this->typeMap.insert({ tython::Type::NONE, noneType });

    this->typeMap.insert({ tython::Type::UNKNOWN, stringType });
}

llvm::Type *TythonBuilder::getLLVMType(tython::Type type) {

    switch (type) {
        case tython::INTEGER:
            return llvm::IntegerType::getInt64Ty(this->getContext());
        case tython::FP:
            return llvm::Type::getDoubleTy(this->getContext());
        case tython::UNKNOWN:
        case tython::NONE:
        case tython::STRING:
            return llvm::Type::getInt8PtrTy(this->getContext());
    }

    return llvm::Type::getVoidTy(this->getContext());
}

llvm::StructType *TythonBuilder::getValueStructType(tython::Type type) {
    return this->typeMap.at(type);
}

llvm::Value *TythonBuilder::getContent(Variable *dataEntry) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    return this->CreateGEP(this->variableStructType, dataEntry->variable, { zero, one });
}

llvm::Value *TythonBuilder::getContent(Value *value) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    return this->CreateGEP(this->getValueStructType(value->type), value->content, { zero, one });
}

llvm::Value *TythonBuilder::getValueContent(Variable *dataEntry) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    auto gep1 = this->CreateGEP(this->variableStructType, dataEntry->variable, { zero, one });
    return this->CreateGEP(this->getValueStructType(dataEntry->value->type), gep1, { zero, one });
}

Value *TythonBuilder::CreateValue(tython::Type type, llvm::Value* content) {

    const auto ty = this->getValueStructType(type);

    llvm::Value* alloc;

    if (this->current_scope->parent) {
        alloc = this->CreateAlloca(ty);
    } else {
        alloc = this->CreateMalloc(ty);
    }

    // store the content in the alloc
    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    auto content_ptr = this->CreateGEP(ty, alloc, { zero, one });

    this->CreateStore(content, content_ptr);

    return new Value(type, alloc);
}

Variable *TythonBuilder::CreateVariable(std::string &name) {

    if (this->current_scope->findDataEntry(name)) {
        throw CompileException("Attempt to create variable with existing name in scope!");
    }

    llvm::Value* alloc;

    if (this->current_scope->parent) {
        alloc = this->CreateAlloca(this->variableStructType, nullptr, name);
    } else {
        llvm::Constant *zeroInit = llvm::ConstantAggregateZero::get(this->variableStructType);
        alloc = new llvm::GlobalVariable(*this->module, this->variableStructType, false, llvm::GlobalValue::InternalLinkage, zeroInit, name);
    }

    // set name
    {
        const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
        const auto zero = llvm::ConstantInt::get(int32_t, 0);
        auto name_ptr = this->CreateGEP(this->variableStructType, alloc, {zero, zero});
        // create string literal character array
        auto charVector = std::vector<char>(name.begin(), name.end());
        charVector.push_back('\0'); // null-terminator
        // populate allocated char*
        auto bytes = llvm::ConstantDataArray::get(this->getContext(), charVector);
        this->CreateStore(bytes, name_ptr);
    }

    const auto variable = new Variable(name, alloc);

    this->current_scope->registerDataEntry(variable);

    return this->current_scope->findDataEntry(name);
}

llvm::Value* TythonBuilder::CreateMalloc(llvm::Type* type, unsigned int amount) {

    // get size of type
    auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
    auto type_width = this->module->getDataLayout().getTypeAllocSize(type).getFixedSize();

    llvm::Value* reserve_size;

    if (amount > 1) {
        reserve_size = llvm::ConstantInt::get(int64_t, type_width * amount);
    } else {
        reserve_size = llvm::ConstantInt::get(int64_t, type_width);
    }

    auto f = this->module->malloc_func;

    return this->CreateCall(*f, { reserve_size });
}


llvm::Value *TythonBuilder::CreateToString(Value *value) {
    return nullptr;
}

llvm::Value* TythonBuilder::CreatePrintF(Value *value) {
    return nullptr;
}
