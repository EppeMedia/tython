#include "../../include/ir/TythonBuilder.h"
#include "../../include/exception/CompileException.h"

void TythonBuilder::init() {

    // create global scope
    this->current_namespace = new Namespace();

    initFirstClassTypes();
}

void TythonBuilder::initFirstClassTypes() {

    llvm::Type* int64_t = llvm::Type::getInt64Ty(this->getContext());
    llvm::Type* ptr_t = llvm::PointerType::get(this->getContext(), 0);

    // object and typeobject scaffolding

    llvm::ArrayRef<llvm::Type*> object_types = {
        ptr_t,      // identity
        ptr_t,      // type object reference
    };

    this->object_type = llvm::StructType::create(this->getContext(), object_types, "Object");

    llvm::ArrayRef<llvm::Type*> number_functions_types = {
        ptr_t,      // to_bool  (function ptr)
        ptr_t,      // to_int   (function ptr)
        ptr_t,      // to_float (function ptr)

        ptr_t,      // cmp_eq   (function ptr)
    };

    this->number_functions_type = llvm::StructType::get(this->getContext(), number_functions_types, "Object.Number.Functions");

    llvm::ArrayRef<llvm::Type*> mapping_functions_types = {
        ptr_t,      // length (function ptr)
        ptr_t,      // subscript (function ptr)
    };

    const auto mapping_functions_type = llvm::StructType::get(this->getContext(), mapping_functions_types, "Object.Mapping.Functions");

    llvm::ArrayRef<llvm::Type*> typeobject_types = {

        // ObjectHead
        ptr_t,      // identity
        ptr_t,      // type object reference
        // End ObjectHead

        ptr_t,      // base (parent type)
        int64_t,    // instance size
        int64_t,    // item size

        ptr_t,      // alloc (function pointer)
        ptr_t,      // seqalloc (function pointer)

        ptr_t,      // rich compare (function pointer)
        ptr_t,      // str (function pointer)

        llvm::PointerType::get(number_functions_type, 0),      // number functions (struct pointer)
        llvm::PointerType::get(mapping_functions_type, 0),      // mapping functions (struct pointer)
    };

    this->typeobject_type = llvm::StructType::create(this->getContext(), typeobject_types, "Object.TypeObject");
}

Namespace *TythonBuilder::nestNamespace() {
    return this->current_namespace = new Namespace(this->current_namespace);
}

Namespace *TythonBuilder::popNamespace() {
    return this->current_namespace = this->current_namespace->parent;
}

llvm::Value *TythonBuilder::CreateGetTypeObject(llvm::Value* object_instance) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    return this->CreateGEP(this->object_type, object_instance, {zero, one });
}

llvm::Value *TythonBuilder::CreateGetNumberFunctions(llvm::Value *type_object) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto eight = llvm::ConstantInt::get(int32_t, 8);

    return this->CreateGEP(this->typeobject_type, type_object, { zero, eight });
}

llvm::Value *TythonBuilder::CreateObjectIsTruthy(llvm::Value *object_instance) {
    return (llvm::Value*)this->CreateCall(*this->module->object_is_truthy_func, { object_instance }, "object_is_truthy");
}

llvm::Value *TythonBuilder::CreateGetNumberToBool(llvm::Value *number_functions_struct) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto otra = llvm::ConstantInt::get(int32_t, 0);

    return this->CreateGEP(this->number_functions_type, number_functions_struct, { zero, otra });
}

llvm::Value *TythonBuilder::CreateGetNumberToInt(llvm::Value *number_functions_struct) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto otra = llvm::ConstantInt::get(int32_t, 1);

    return this->CreateGEP(this->number_functions_type, number_functions_struct, { zero, otra });
}

llvm::Value *TythonBuilder::CreateGetNumberToFloat(llvm::Value *number_functions_struct) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto otra = llvm::ConstantInt::get(int32_t, 2);

    return this->CreateGEP(this->number_functions_type, number_functions_struct, { zero, otra });
}

llvm::Value *TythonBuilder::CreateGetNumberCmpEq(llvm::Value *number_functions_struct) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);

    return this->CreateGEP(this->number_functions_type, number_functions_struct, {zero, one});
}

static bool isNumberType(llvm::Value* v) {
    auto t = v->getType();
    return t->isIntegerTy() || t->isFloatTy() || t->isDoubleTy();
}

llvm::Value* TythonBuilder::CreateFloatObject(llvm::Value* content) {

    if (!isNumberType(content)) {
        throw CompileException("Cannot construct a number object with anything other than a first-order number parameter (integral of floating-point).");
    }

    return (llvm::Value*)this->CreateCall(*this->module->number_create_func, { content }, "floatobject");
}

llvm::Value *TythonBuilder::CreateStringObject(llvm::Value *cstr, llvm::Value *length) {
    return (llvm::Value*)this->CreateCall(*this->module->string_create_func, { cstr, length }, "stringobject");
}

llvm::Value *TythonBuilder::CreateObjectToString(llvm::Value *object) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto eight = llvm::ConstantInt::get(int32_t, 8);

    const auto typeobject = this->CreateGetTypeObject(object);
    // todo: we might need to load this
    auto function_ptr = this->CreateGEP(this->typeobject_type, typeobject, { zero, eight });

    // str is a unary function
    auto function_type = llvm::FunctionType::get(this->object_type, { this->object_type }, false);

    return (llvm::Value*)this->CreateCall(function_type, function_ptr, { object }, "str");
}

llvm::Value* TythonBuilder::CreateVariable(std::string &name) {

    if (this->current_namespace->findVariable(name)) {
        throw CompileException("Attempt to create variable with existing name in scope!");
    }

    llvm::Value* alloc;

    if (this->current_namespace->isGlobal()) {
        llvm::Constant *zeroInit = llvm::ConstantAggregateZero::get(this->getPtrTy());
        alloc = new llvm::GlobalVariable(*this->module, this->getPtrTy(), false, llvm::GlobalValue::InternalLinkage, zeroInit, name);
    } else {
        alloc = this->CreateAlloca(this->getPtrTy(), nullptr, name);
    }

    this->current_namespace->registerVariable(name, alloc);

    return this->current_namespace->findVariable(name);
}
