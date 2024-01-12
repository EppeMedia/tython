#include "../../include/ir/TythonBuilder.h"
#include "../../include/exception/CompileException.h"

void TythonBuilder::init() {

    // create global scope
    this->current_scope = new Scope();

    initFirstClassTypes();
    initBuiltinFunctions();
}

void TythonBuilder::initFirstClassTypes() {
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
            int8_t     // type
    };

    auto noneType = llvm::StructType::create(this->getContext(), none_types, "Value.None");
    this->typeMap.insert({ tython::Type::NONE, noneType });

    llvm::ArrayRef<llvm::Type*> unknown_types = {
            int8_t,     // type
            getLLVMType(tython::Type::UNKNOWN) // content
    };

    auto unknownType = llvm::StructType::create(this->getContext(), unknown_types, "Value.Unknown");
    this->typeMap.insert({ tython::Type::UNKNOWN, unknownType });
}

void TythonBuilder::initBuiltinFunctions() {

    // todo: this is only initializing the type(ptr) function at the moment

    // create a new scope for this function's arguments. The body scope of the function will be nested in this.
    this->nestScope();

    // function declarations are fully opaque; we only know that it may return something, and that it takes n variable arguments
    auto int8_type = llvm::IntegerType::getInt8Ty(this->getContext());
    const auto int64_type = llvm::IntegerType::getInt64Ty(this->getContext());
    auto ptr_type = llvm::PointerType::get(this->getContext(), 0);
    auto return_type = ptr_type;

    std::string name = "type";

    llvm::FunctionType* ft = llvm::FunctionType::get(return_type, { ptr_type }, false);
    auto fn = llvm::Function::Create(ft, llvm::GlobalValue::InternalLinkage, name, this->module);

    this->module->registerProcedure(fn, tython::INTEGER, name);

    auto old_bb = this->GetInsertBlock();

    auto prologue = llvm::BasicBlock::Create(this->getContext(), "prologue", fn);
    this->SetInsertPoint(prologue);

    // arguments
    auto arg = fn->getArg(0);

    auto body = llvm::BasicBlock::Create(this->getContext(), "body", fn);
    this->CreateBr(body);
    this->SetInsertPoint(body);

    this->nestScope();

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto zero = llvm::ConstantInt::get(int32_t, 0);

    // function body
    auto gep = this->CreateGEP(this->getValueStructType(tython::UNKNOWN), arg, { zero, zero });
    auto load = this->CreateLoad(int8_type, gep);
//    auto cast = this->CreateBitCast(load, int64_type);

    auto result = this->CreateValue(tython::INTEGER, load, true);

    this->popScope();

    auto epilogue = llvm::BasicBlock::Create(this->getContext(), "epilogue", fn);
    this->CreateBr(epilogue);
    this->SetInsertPoint(epilogue);

    // return the result
    this->CreateRet(result->content);

    // back to enclosing scope
    this->popScope();

    this->SetInsertPoint(old_bb);
}

Scope *TythonBuilder::nestScope() {
    return this->current_scope = new Scope(this->current_scope);
}

Scope *TythonBuilder::popScope() {
    return this->current_scope = this->current_scope->parent;
}

llvm::Type *TythonBuilder::getLLVMType(tython::Type type) {

    switch (type) {
        case tython::NONE:
            return llvm::Type::getVoidTy(this->getContext());
        case tython::INTEGER:
            return llvm::IntegerType::getInt64Ty(this->getContext());
        case tython::FP:
            return llvm::Type::getDoubleTy(this->getContext());
        case tython::STRING:
            return llvm::Type::getInt8PtrTy(this->getContext());
        case tython::AGGREGATE:
            return llvm::PointerType::get(this->getContext(), 0);
        case tython::UNKNOWN:
            return llvm::PointerType::get(this->getContext(), 0);
    }

    return llvm::Type::getVoidTy(this->getContext());
}

llvm::StructType *TythonBuilder::getValueStructType(tython::Type type) {
    return this->typeMap.at(type);
}

llvm::Value *TythonBuilder::CreateGetValuePtr(Variable *dataEntry) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    return this->CreateGEP(this->variableStructType, dataEntry->variable, { zero, one });
}

llvm::Value *TythonBuilder::CreateGetType(Variable *variable) {

    auto value_ptr = CreateGetValuePtr(variable);

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);

    auto gep = this->CreateGEP(this->getValueStructType(variable->value->type), value_ptr, { zero, zero });

    return this->CreateLoad(this->getLLVMType(variable->value->type), gep);
}

llvm::Value *TythonBuilder::CreateGetType(Value *value) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);

    auto gep = this->CreateGEP(this->getValueStructType(value->type), value->content, { zero, zero });

    return this->CreateLoad(this->getLLVMType(value->type), gep);
}

llvm::Value *TythonBuilder::CreateGetContent(Value *value) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    auto gep = this->CreateGEP(this->getValueStructType(value->type), value->content, { zero, one });

    return this->CreateLoad(this->getLLVMType(value->type), gep);
}

Value *TythonBuilder::CreateValue(tython::Type type, llvm::Value* content, bool forceHeap) {

    const auto ty = this->getValueStructType(type);

    llvm::Value* alloc;

    if (this->current_scope->parent && !forceHeap) {
        alloc = this->CreateAlloca(ty);
    } else {
        alloc = this->CreateMalloc(ty);
    }

    // store the content in the alloc
    const auto int8_t = llvm::IntegerType::getInt8Ty(this->getContext());
    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    auto type_ptr = this->CreateGEP(ty, alloc, { zero, zero });
    auto typeValue = llvm::ConstantInt::get(int8_t, type);
    this->CreateStore(typeValue, type_ptr);

    auto content_ptr = this->CreateGEP(ty, alloc, { zero, one });

    // if the size of what we are storing is smaller than the allocated size, we need to zero-initialize (reads of the memory are expecting the stated memory to be fully initialized)
    auto target_type = this->getLLVMType(type);

    if (target_type->getScalarSizeInBits() != content->getType()->getScalarSizeInBits()) {
        auto content_type_size = llvm::ConstantInt::get(int32_t, target_type->getScalarSizeInBits() / 8);
        this->CreateMemSetInline(content_ptr, llvm::MaybeAlign(0), zero, content_type_size, false);
    }

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

    // todo: set name
//    {
//        const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
//        const auto zero = llvm::ConstantInt::get(int32_t, 0);
//        auto name_ptr = this->CreateGEP(this->variableStructType, alloc, {zero, zero});
//        // create string literal character array
//        auto charVector = std::vector<char>(name.begin(), name.end());
//        charVector.push_back('\0'); // null-terminator
//        // populate allocated char*
//        auto bytes = llvm::ConstantDataArray::get(this->getContext(), charVector);
//        this->CreateStore(bytes, name_ptr);
//    }

    const auto variable = new Variable(name, alloc);

    this->current_scope->registerDataEntry(variable);

    return this->current_scope->findDataEntry(name);
}

llvm::Value* TythonBuilder::CreateMalloc(llvm::Type* type, unsigned int amount) {

    // get size of type
    auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    auto type_width = this->module->getDataLayout().getTypeAllocSize(type).getFixedSize();

    llvm::Value* reserve_size;

    if (amount > 1) {
        reserve_size = llvm::ConstantInt::get(int32_t, type_width * amount);
    } else {
        reserve_size = llvm::ConstantInt::get(int32_t, type_width);
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
