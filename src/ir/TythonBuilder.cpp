#include "../../include/ir/TythonBuilder.h"
#include "../../include/exception/CompileException.h"
#include "type.h"
#include "object/dictobject.h"
#include "object/listobject.h"
#include <cstddef>

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

    this->mapping_functions_type = llvm::StructType::get(this->getContext(), mapping_functions_types, "Object.Mapping.Functions");

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
        ptr_t,      // hash (function pointer)

        llvm::PointerType::get(number_functions_type, 0),      // number functions (struct pointer)
        ptr_t,      // mapping functions (struct pointer)
    };

    this->typeobject_type = llvm::StructType::create(this->getContext(), typeobject_types, "Object.TypeObject");

    llvm::ArrayRef<llvm::Type*> dict_entry_types = {
        ptr_t,      // key reference
        ptr_t       // value reference
    };

    this->dict_entry_type = llvm::StructType::create(this->getContext(), dict_entry_types, "DictEntry");
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
    const auto slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_NUMBER_FUNCTIONS);

    return this->CreateGEP(this->typeobject_type, type_object, {zero, slot });
}

llvm::Value *TythonBuilder::CreateGetMappingFunctions(llvm::Value *type_object) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_MAPPING_FUNCTIONS);

    return this->CreateGEP(this->typeobject_type, type_object, {zero, slot });
}

llvm::Value *TythonBuilder::CreateObjectIsTruthy(llvm::Value *object_instance) {
    return (llvm::Value*)this->CreateCall(*this->module->object_is_truthy_func, { object_instance }, "object_is_truthy");
}

llvm::Value *TythonBuilder::CreateGetNumberToBool(llvm::Value *number_functions_struct) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, 0);

    return this->CreateGEP(this->number_functions_type, number_functions_struct, {zero, slot });
}

llvm::Value *TythonBuilder::CreateGetNumberToInt(llvm::Value *number_functions_struct) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, 1);

    return this->CreateGEP(this->number_functions_type, number_functions_struct, {zero, slot });
}

llvm::Value *TythonBuilder::CreateGetNumberToFloat(llvm::Value *number_functions_struct) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, 2);

    return this->CreateGEP(this->number_functions_type, number_functions_struct, {zero, slot });
}

llvm::Value *TythonBuilder::CreateRichCmp(llvm::Value *lhs, llvm::Value *rhs, int op) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    const auto lhs_type_ref = this->CreateGetTypeObject(lhs);
    const auto lhs_type = this->CreateLoad(ptr_t, lhs_type_ref);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_RICH_COMPARE);

    auto rich_cmp_ref = this->CreateGEP(this->typeobject_type, lhs_type, {zero, slot });

    auto rich_cmp_f = this->CreateLoad(ptr_t, rich_cmp_ref);
    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t, int32_t }, false);

    const auto op_value = llvm::ConstantInt::get(int32_t, op);

    return this->CreateCall(function_type, rich_cmp_f, { lhs, rhs, op_value }, "rich_cmp");
}

llvm::Value *TythonBuilder::CreateSubscript(llvm::Value *object, llvm::Value *key) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    const auto object_type_ref = this->CreateGetTypeObject(object);
    const auto object_type = this->CreateLoad(ptr_t, object_type_ref);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);
    const auto mapping_functions_slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_MAPPING_FUNCTIONS);

    auto mapping_functions_ref = this->CreateGEP(this->typeobject_type, object_type, { zero, mapping_functions_slot });
    auto mapping_functions = this->CreateLoad(ptr_t, mapping_functions_ref);

    auto subscript_ref = this->CreateGEP(this->mapping_functions_type, mapping_functions, { zero, one });
    auto subscript_f = this->CreateLoad(ptr_t, subscript_ref);

    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t }, false);

    return this->CreateCall(function_type, subscript_f, { object, key }, "subscript");
}

static bool isNumberType(llvm::Value* v) {
    auto t = v->getType();
    return t->isIntegerTy() || t->isFloatTy() || t->isDoubleTy();
}

llvm::Value *TythonBuilder::CreateIntObject(llvm::Value *content) {

    if (!isNumberType(content)) {
        throw CompileException("Cannot construct an integer object with anything other than a first-order integer.");
    }

    return this->CreateCall(*this->module->int_create_func, { content }, "integerobject");
}

llvm::Value* TythonBuilder::CreateFloatObject(llvm::Value* content) {

    if (!isNumberType(content)) {
        throw CompileException("Cannot construct a floating-point object with anything other than a first-order floating-point.");
    }

    return (llvm::Value*)this->CreateCall(*this->module->float_create_func, { content }, "floatobject");
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

llvm::Value* TythonBuilder::CreateDictLiteral(llvm::Value *count, std::vector<std::pair<llvm::Value *, llvm::Value *>> &entries) {

    auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
    auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    auto f = this->module->dict_create_func;
    auto dict_ref = this->CreateCall((llvm::Function*)f->getCallee(), { count }, "dict_create");

    // steal the entries reference off of the dictionary object (todo: we could instead declare the struct type globally and use GEPs)
    size_t offset = offsetof(dict_object, entries);
    auto offset_value = llvm::ConstantInt::get(int64_t, offset);
    auto ptr_loc = this->CreatePtrToInt(dict_ref, int64_t);
    auto ptr_offset = this->CreateAdd(ptr_loc, offset_value, "entries_offset");
    auto entries_ref = this->CreateIntToPtr(ptr_offset, ptr_t, "entries_ref");

    auto entries_start = this->CreateLoad(ptr_t, entries_ref, "entry_start");
    auto entries_start_int = this->CreatePtrToInt(entries_start, int64_t, "entry_start_int");

    // stitch entries
    for (int i = 0; i < entries.size(); ++i) {

        // store the key and value
        auto entry = entries.at(i);

        size_t k_offset = (sizeof(dict_entry) * i) + offsetof(dict_entry, key);
        auto k_offset_value = llvm::ConstantInt::get(int64_t, k_offset);
        auto k_ptr_offset = this->CreateAdd(entries_start_int, k_offset_value, "key_offset");
        auto k_ref = this->CreateIntToPtr(k_ptr_offset, ptr_t, "key_ref");

        auto key_ptr = this->CreatePtrToInt(entry.first, int64_t, "key_ptr");
        this->CreateStore(key_ptr, k_ref);

        size_t v_offset = offsetof(dict_entry, value);
        auto v_offset_value = llvm::ConstantInt::get(int64_t, v_offset);
        auto v_ptr_offset = this->CreateAdd(k_ptr_offset, v_offset_value, "value_offset");
        auto v_ref = this->CreateIntToPtr(v_ptr_offset, ptr_t, "value_ref");

        auto value_ptr = this->CreatePtrToInt(entry.second, int64_t, "value_ptr");
        this->CreateStore(value_ptr, v_ref);
    }

    return dict_ref;
}


llvm::Value* TythonBuilder::CreateListLiteral(llvm::Value *count, std::vector<llvm::Value *> &elements) {

    auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
    auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    auto f = this->module->list_create_func;
    auto list_ref = this->CreateCall((llvm::Function*)f->getCallee(), {count }, "list_create");

    // steal the elements reference off of the list object
    size_t offset = offsetof(list_object, elements);
    auto offset_value = llvm::ConstantInt::get(int64_t, offset);
    auto ptr_loc = this->CreatePtrToInt(list_ref, int64_t);
    auto ptr_offset = this->CreateAdd(ptr_loc, offset_value, "elements_offset");
    auto entries_ref = this->CreateIntToPtr(ptr_offset, ptr_t, "elements_ref");

    auto elements_start = this->CreateLoad(ptr_t, entries_ref, "elements_start");
    auto elements_start_int = this->CreatePtrToInt(elements_start, int64_t, "elements_start_int");

    for (int i = 0; i < elements.size(); ++i) {

        // store the element
        auto element = elements.at(i);

        size_t e_offset = (sizeof(object*) * i);
        auto e_offset_value = llvm::ConstantInt::get(int64_t, e_offset);
        auto e_ptr_offset = this->CreateAdd(elements_start_int, e_offset_value, "element_offset");
        auto e_ref = this->CreateIntToPtr(e_ptr_offset, ptr_t, "element_ref");

        this->CreateStore(element, e_ref);
    }

    return list_ref;
}
