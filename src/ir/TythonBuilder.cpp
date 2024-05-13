#include "../../include/ir/TythonBuilder.h"
#include "../../include/exception/CompileException.h"
#include "type.h"
#include "api/api.h"
#include "object/dictobject.h"
#include "object/listobject.h"
#include "object/tupleobject.h"
#include "../../config.h"
#include <cstddef>

void TythonBuilder::init() {

    // create global scope
    this->current_context = new class Context();

    initFirstClassTypes();
}

void TythonBuilder::initFirstClassTypes() {

    llvm::Type* int32_t = llvm::Type::getInt32Ty(this->getContext());
    llvm::Type* int64_t = llvm::Type::getInt64Ty(this->getContext());
    llvm::Type* ptr_t = llvm::PointerType::get(this->getContext(), 0);

    // object and typeobject scaffolding

    llvm::ArrayRef<llvm::Type*> object_types = {
        ptr_t,      // identity
        ptr_t,      // type object reference
        int32_t,    // reference counter
    };

    this->object_type = llvm::StructType::create(this->getContext(), object_types, "Object");

    llvm::ArrayRef<llvm::Type*> number_functions_types = {
        ptr_t,      // to_bool  (function ptr)
        ptr_t,      // to_int   (function ptr)
        ptr_t,      // to_float (function ptr)

        ptr_t,      // add      (function ptr)
        ptr_t,      // sub      (function ptr)
        ptr_t,      // mult     (function ptr)
        ptr_t,      // div      (function ptr)
        ptr_t,      // exp      (function ptr)
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
        int32_t,    // reference counter
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
        ptr_t,      // sequence functions

        ptr_t,      // create iterator (unary function pointer)
        ptr_t,      // iterator next (unary function pointer)

        ptr_t,      // methods

        ptr_t,      // grab (inc. reference function pointer)
        ptr_t,      // release (dec. reference function pointer)
    };

    this->typeobject_type = llvm::StructType::create(this->getContext(), typeobject_types, "Object.TypeObject");

    llvm::ArrayRef<llvm::Type*> specialization_type_types = {

        int32_t,    // type enumerator

        int64_t,    // this is a lie; it is a one-register wide value that will be bitcast depending on the type enumerator
    };

    this->specialization_type = llvm::StructType::create(this->getContext(), specialization_type_types, "SpecializationType");

    // external symbols (fields)
    this->none_object_instance = new llvm::GlobalVariable(*this->module, this->object_type, true, llvm::GlobalValue::ExternalLinkage, nullptr, "none_instance", nullptr, llvm::GlobalValue::NotThreadLocal, llvm::None, true);
}

Context *TythonBuilder::nestContext(unsigned int flags) {
    return this->current_context = new class Context(this->current_context, flags);
}

Context *TythonBuilder::popContext(bool free) {

    if (free) {

        // free objects bound to variables that were declared in this scope
        for (auto &e: this->current_context->variable_shadow_symbol_table) {

            const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

            const auto load = this->CreateLoad(ptr_t, e.second);
            this->CreateReleaseObject(load);
        }
    }

    return this->current_context = this->current_context->parent;
}

llvm::Value *TythonBuilder::CreateGetTypeObject(llvm::Value* object_instance) {
    return this->CreateStructGEP(this->object_type, object_instance, 1);
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

llvm::Value *TythonBuilder::CreateAssign(llvm::Value *assignee, llvm::Value *value) {

    /*
     * LHS is (globally) allocated to hold a specialization union.
     * Assignment is not only value assignment, but also tag assignment.
     * I.e. let LHS = { 0, 42 }, RHS = { 2, 0xABBA }
     * Then LHS := RHS -> LHS = { 2, 0xABBA }
     */

    auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());

    const auto assignee_tag_ref = this->CreateStructGEP(this->specialization_type, assignee, 0);
    const auto addignee_content_ref = this->CreateStructGEP(this->specialization_type, assignee, 1);

    const auto value_tag_ref = this->CreateStructGEP(this->specialization_type, value, 0);
    const auto value_tag = this->CreateLoad(int32_t, value_tag_ref);
    const auto value_content_ref = this->CreateStructGEP(this->specialization_type, value, 1);
    const auto value_content = this->CreateLoad(int64_t, value_content_ref);

    this->CreateStore(value_tag, assignee_tag_ref);
    this->CreateStore(value_content, addignee_content_ref);

    return assignee;
}

llvm::Value *TythonBuilder::CreateObjectIsTruthy(llvm::Value *object_instance) {
    return (llvm::Value*)this->CreateCall(*this->module->object_is_truthy_func, { object_instance }, "object_is_truthy");
}

llvm::Value *TythonBuilder::CreateResolveBuiltinMethod(llvm::Value *object, llvm::Value *name) {
    return (llvm::Value*)this->CreateCall(*this->module->resolve_builtin_method_func, { object, name }, "resolve_builtin_method");
}

llvm::Value* TythonBuilder::CreateBinop(llvm::Value* lhs, llvm::Value* rhs,
                                        const std::function<llvm::Value*(llvm::Value *, llvm::Value *)>& specialized_int_case_handler,
                                        const std::function<llvm::Value*(llvm::Value *, llvm::Value *)>& specialized_float_case_handler,
                                        const std::function<llvm::Value *(llvm::Value *, llvm::Value *)>& dynamic_runtime_handler) {

    // todo: insert GC operations where appropriate (when LHS is object, grab and release it; same for RHS; also grab any result objects)

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());

    const auto lhs_type_tag_ref= this->CreateStructGEP(this->specialization_type, lhs, 0);
    const auto lhs_type_tag = this->CreateLoad(int32_t, lhs_type_tag_ref, "lhs_type_tag");

    const auto lhs_value_ref = this->CreateStructGEP(this->specialization_type, lhs, 1);
    const auto lhs_value = this->CreateLoad(int64_t, lhs_value_ref, "lhs_value");

    const auto rhs_type_tag_ref = this->CreateStructGEP(this->specialization_type, rhs, 0, "rhs_type_tag");
    const auto rhs_type_tag = this->CreateLoad(int32_t, rhs_type_tag_ref);

    const auto rhs_value_ref = this->CreateStructGEP(this->specialization_type, rhs, 1);
    const auto rhs_value = this->CreateLoad(int64_t, rhs_value_ref, "rhs_value");

    llvm::Value* result_spec = this->CreateAlloca(this->specialization_type);

    /*
     * The LHS is dictating in the Python language spec, where the type of the RHS of the binop must convert to the type of the LHS (or a type error occurs).
     * The type of the result of the operation is the type of the LHS operand.
     */

    // SWITCH on lhs type enumerator
    const auto exit_block = llvm::BasicBlock::Create(this->getContext(), "switch_exit_block", this->GetInsertBlock()->getParent());
    const auto catchall_block = llvm::BasicBlock::Create(this->getContext(), "catchall_block", this->GetInsertBlock()->getParent(), exit_block);
    const auto lhs_object_block = llvm::BasicBlock::Create(this->getContext(), "lhs_object_block",
                                                          this->GetInsertBlock()->getParent(), catchall_block);
    const auto lhs_float_block = llvm::BasicBlock::Create(this->getContext(), "lhs_float_block",
                                                          this->GetInsertBlock()->getParent(), lhs_object_block);
    const auto lhs_int_block = llvm::BasicBlock::Create(this->getContext(), "lhs_int_block",
                                                        this->GetInsertBlock()->getParent(), lhs_float_block);

    const auto switch_value = this->CreateSwitch(lhs_type_tag, catchall_block, 4);

    const auto int_type_tag_value = llvm::ConstantInt::get(int32_t, SPEC_INT);
    const auto float_type_tag_value = llvm::ConstantInt::get(int32_t, SPEC_FLOAT);
    const auto obj_type_tag_value = llvm::ConstantInt::get(int32_t, SPEC_OBJECT);

    switch_value->addCase(int_type_tag_value, lhs_int_block);
    switch_value->addCase(float_type_tag_value, lhs_float_block);
    switch_value->addCase(obj_type_tag_value, lhs_object_block);

    const auto same_type_handler = [this, lhs_value, rhs_value, specialized_int_case_handler, specialized_float_case_handler, result_spec](std::int32_t type_tag) -> void {

        const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
        const auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
        const auto float_t = llvm::Type::getDoubleTy(this->getContext());

        // we know lhs and rhs are of the same type, so let's do a simple binop instruction on their contents
        llvm::Value* result;

        switch (type_tag) {
            case SPEC_INT:
                result = specialized_int_case_handler(lhs_value, rhs_value);
                break;
            case SPEC_FLOAT:
                result = specialized_float_case_handler(this->CreateBitCast(lhs_value, float_t), this->CreateBitCast(rhs_value, float_t));
                break;
            default:
                throw CompileException("Encountered unexpected specialization type!");
        }

        // initialize the result spec struct (result type matches LHS type)
        const auto type_tag_value = llvm::ConstantInt::get(int32_t, type_tag);
        this->CreateStore(type_tag_value, result_spec);
        const auto ref = this->CreateStructGEP(this->specialization_type, result_spec, 1);
        const auto bitcast = this->CreateBitCast(result, int64_t);
        this->CreateStore(bitcast, ref);
    };

    const auto type_error_handler = []() -> void {

        // todo: throw type error

    };

    const auto object_dynamic_type_resolution_handler = [this, lhs_value, rhs_value, specialized_int_case_handler, specialized_float_case_handler, result_spec](std::int32_t type_tag) -> void {

        const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
        const auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
        const auto float_t = llvm::Type::getDoubleTy(this->getContext());
        const auto ptr_t = llvm::PointerType::get(this->getContext(), 0);

        const auto type_tag_value = llvm::ConstantInt::get(int32_t, type_tag);

        const auto rhs_value_cast = this->CreateIntToPtr(rhs_value, ptr_t);
        const auto rhs_primitive = this->CreateCall(*this->module->object_to_primitive, {rhs_value_cast, type_tag_value }, "rhs_primitive");

        // we can now assume the primitive is a valid reference. Runtime type assertion will abort the stack frame otherwise

        // from here on, follow the specialized strategy
        llvm::Value* result;

        switch (type_tag) {
            case SPEC_INT:
                result = specialized_int_case_handler(lhs_value, this->CreateBitCast(rhs_primitive, int64_t));
                break;
            case SPEC_FLOAT:
                result = specialized_float_case_handler(this->CreateBitCast(lhs_value, float_t), this->CreateBitCast(rhs_primitive, float_t));
                break;
            default:
                throw CompileException("Encountered unexpected specialization type!");
        }

        // initialize the result spec struct
        this->CreateStore(type_tag_value, result_spec);
        const auto ref = this->CreateStructGEP(this->specialization_type, result_spec, 1);
        const auto bitcast = this->CreateBitCast(result, int64_t);
        this->CreateStore(bitcast, ref);
    };

    { // CASE lhs is INT

        this->SetInsertPoint(lhs_int_block);

        const auto rhs_int_block = llvm::BasicBlock::Create(this->getContext(), "rhs_int_block",
                                                            this->GetInsertBlock()->getParent());

        const auto rhs_float_block = llvm::BasicBlock::Create(this->getContext(), "rhs_float_block",
                                                              this->GetInsertBlock()->getParent());

        const auto rhs_object_block = llvm::BasicBlock::Create(this->getContext(), "rhs_object_block",
                                                               this->GetInsertBlock()->getParent());

        const auto rhs_switch = this->CreateSwitch(rhs_type_tag, catchall_block, 3);
        rhs_switch->addCase(int_type_tag_value, rhs_int_block);
        rhs_switch->addCase(float_type_tag_value, rhs_float_block);
        rhs_switch->addCase(obj_type_tag_value, rhs_object_block);

        // if rhs is also INT, do simple binop instruction,
        // if it is FLOAT we have a type error,
        // if it is OBJECT we need to do a dynamic object type check.

        {
            this->SetInsertPoint(rhs_int_block);

            same_type_handler(SPEC_INT);

            this->CreateBr(exit_block);

        }

        {
            this->SetInsertPoint(rhs_float_block);

            type_error_handler();

            this->CreateBr(exit_block);
        }

        {
            // the RHS is of an object type. Dynamic object resolution should tell us if we can "cast" this to the right primitive type

            this->SetInsertPoint(rhs_object_block);

            object_dynamic_type_resolution_handler(SPEC_INT);

            this->CreateBr(exit_block);
        }
    }

    { // CASE lhs is float
        this->SetInsertPoint(lhs_float_block);

        const auto rhs_int_block = llvm::BasicBlock::Create(this->getContext(), "rhs_int_block",
                                                            this->GetInsertBlock()->getParent());

        const auto rhs_float_block = llvm::BasicBlock::Create(this->getContext(), "rhs_float_block",
                                                              this->GetInsertBlock()->getParent());

        const auto rhs_object_block = llvm::BasicBlock::Create(this->getContext(), "rhs_object_block",
                                                               this->GetInsertBlock()->getParent());

        const auto rhs_switch = this->CreateSwitch(rhs_type_tag, catchall_block, 3);
        rhs_switch->addCase(int_type_tag_value, rhs_int_block);
        rhs_switch->addCase(float_type_tag_value, rhs_float_block);
        rhs_switch->addCase(obj_type_tag_value, rhs_object_block);

        // if rhs is INT we have a type error
        // if it is also FLOAT, do simple binop instruction,
        // if it is OBJECT we need to do a dynamic object type check.

        {
            this->SetInsertPoint(rhs_int_block);

            type_error_handler();

            this->CreateBr(exit_block);

        }

        {
            this->SetInsertPoint(rhs_float_block);

            same_type_handler(SPEC_FLOAT);

            this->CreateBr(exit_block);
        }

        {
            // the RHS is of an object type. Dynamic object resolution should tell us if we can "cast" this to the right primitive type

            this->SetInsertPoint(rhs_object_block);

            object_dynamic_type_resolution_handler(SPEC_FLOAT);

            this->CreateBr(exit_block);
        }
    }

    { // CASE lhs is object
        this->SetInsertPoint(lhs_object_block);

        const auto rhs_int_block = llvm::BasicBlock::Create(this->getContext(), "rhs_int_block",
                                                            this->GetInsertBlock()->getParent());

        const auto rhs_float_block = llvm::BasicBlock::Create(this->getContext(), "rhs_float_block",
                                                              this->GetInsertBlock()->getParent());

        const auto rhs_object_block = llvm::BasicBlock::Create(this->getContext(), "rhs_object_block",
                                                               this->GetInsertBlock()->getParent());

        const auto rhs_switch = this->CreateSwitch(rhs_type_tag, catchall_block, 3);
        rhs_switch->addCase(int_type_tag_value, rhs_int_block);
        rhs_switch->addCase(float_type_tag_value, rhs_float_block);
        rhs_switch->addCase(obj_type_tag_value, rhs_object_block);

        // if rhs is INT, we need to do a dynamic object type check,
        // if it is also FLOAT, we need to do a dynamic object type check,
        // if it is OBJECT, we delegate to the dynamic runtime.

        const auto lhs_to_primitive_handler = [this, lhs_value, rhs_value, specialized_int_case_handler, specialized_float_case_handler, result_spec](std::int32_t type_tag) -> void {

            const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
            const auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
            const auto float_t = llvm::Type::getDoubleTy(this->getContext());

            const auto type_tag_value = llvm::ConstantInt::get(int32_t, type_tag);

            const auto ptr_t = llvm::PointerType::get(this->getContext(), 0);
            const auto lhs_value_cast = this->CreateIntToPtr(lhs_value, ptr_t);
            const auto lhs_primitive = this->CreateCall(*this->module->object_to_primitive, {lhs_value_cast, type_tag_value }, "lhs_primitive");

            // we can now assume this is a valid reference, runtime assertion will abort the stack frame otherwise

            // from here on, follow the specialized strategy
            llvm::Value* result;

            switch (type_tag) {
                case SPEC_INT:
                    result = specialized_int_case_handler(this->CreateBitCast(lhs_primitive, int64_t), rhs_value);
                    break;
                case SPEC_FLOAT:
                    result = specialized_float_case_handler(this->CreateBitCast(lhs_primitive, float_t), this->CreateBitCast(rhs_value, float_t));
                    break;
                default:
                    throw CompileException("Encountered unexpected specialization type!");
            }

            // initialize the result spec struct
            const auto type_tag_value2 = llvm::ConstantInt::get(int32_t, type_tag);
            this->CreateStore(type_tag_value2, result_spec);
            const auto ref = this->CreateStructGEP(this->specialization_type, result_spec, 1);
            const auto bitcast = this->CreateBitCast(result, int64_t);
            this->CreateStore(bitcast, ref);
        };

        { // RHS is INT

            this->SetInsertPoint(rhs_int_block);

            lhs_to_primitive_handler(SPEC_INT);

            this->CreateBr(exit_block);
        }

        { // RHS is FLOAT

            this->SetInsertPoint(rhs_float_block);

            lhs_to_primitive_handler(SPEC_FLOAT);

            this->CreateBr(exit_block);
        }

        { // RHS is OBJECT

            this->SetInsertPoint(rhs_object_block);

            // delegate to runtime handler
            const auto ptr_t = llvm::PointerType::get(this->getContext(), 0);
            const auto lhs_value_cast = this->CreateIntToPtr(lhs_value, ptr_t);
            const auto rhs_value_cast = this->CreateIntToPtr(rhs_value, ptr_t);
            const auto result = dynamic_runtime_handler(lhs_value_cast, rhs_value_cast);

            // initialize the result spec struct. The result is always of type OBJECT
            const auto int_type_tag_value2 = llvm::ConstantInt::get(int64_t, SPEC_OBJECT);

            this->CreateStore(int_type_tag_value2, result_spec);
            const auto ref = this->CreateStructGEP(this->specialization_type, result_spec, 1);
            const auto bitcast = this->CreateBitCast(result, int64_t);
            this->CreateStore(bitcast, ref);

            this->CreateBr(exit_block);
        }
    }

    // todo: populate catchall block
    this->SetInsertPoint(catchall_block);

    // delegate to some external API function that takes two spec structs as input

    this->CreateBr(exit_block);

    this->SetInsertPoint(exit_block);

    return result_spec;
}

llvm::Value* TythonBuilder::CreateBinaryNumberFunctionCall(size_t number_function_slot, llvm::Value* lhs, llvm::Value* rhs) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->getContext(), 0);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, number_function_slot);

    const auto lhs_type_ref = this->CreateGetTypeObject(lhs);
    const auto lhs_type = this->CreateLoad(ptr_t, lhs_type_ref);

    const auto lhs_number_functions_ref = this->CreateGetNumberFunctions(lhs_type);
    const auto lhs_number_functions = this->CreateLoad(ptr_t, lhs_number_functions_ref);

    auto nf_ref = this->CreateGEP(this->number_functions_type, lhs_number_functions, {zero, slot });
    auto nf = this->CreateLoad(ptr_t, nf_ref, "number_function_ref");

    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t }, false);

    return this->CreateCall(function_type, nf, {lhs, rhs }, "number_function_call");
}

llvm::Value *TythonBuilder::CreateTythonAdd(llvm::Value *lhs, llvm::Value *rhs) {

    const auto specialized_int_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateAdd(lhs_primitive, rhs_primitive, "sum");
    };

    const auto specialized_float_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateFAdd(lhs_primitive, rhs_primitive, "sum");
    };

    const auto runtime_handler = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return CreateBinaryNumberFunctionCall(3, lhs, rhs);
    };

    return this->CreateBinop(lhs, rhs, specialized_int_handler, specialized_float_handler, runtime_handler);
}

llvm::Value *TythonBuilder::CreateTythonSub(llvm::Value *lhs, llvm::Value *rhs) {

    const auto specialized_int_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateSub(lhs_primitive, rhs_primitive, "sub");
    };

    const auto specialized_float_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateFSub(lhs_primitive, rhs_primitive, "sub");
    };

    const auto runtime_handler = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return CreateBinaryNumberFunctionCall(4, lhs, rhs);
    };

    return this->CreateBinop(lhs, rhs, specialized_int_handler, specialized_float_handler, runtime_handler);
}

llvm::Value *TythonBuilder::CreateTythonMult(llvm::Value *lhs, llvm::Value *rhs) {

    const auto specialized_int_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateMul(lhs_primitive, rhs_primitive, "mult");
    };

    const auto specialized_float_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateFMul(lhs_primitive, rhs_primitive, "mult");
    };

    const auto runtime_handler = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return CreateBinaryNumberFunctionCall(5, lhs, rhs);
    };

    return this->CreateBinop(lhs, rhs, specialized_int_handler, specialized_float_handler, runtime_handler);
}

llvm::Value *TythonBuilder::CreateTythonDiv(llvm::Value *lhs, llvm::Value *rhs) {

    const auto specialized_int_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateFDiv(lhs_primitive, rhs_primitive, "div");
    };

    const auto specialized_float_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {
        return this->CreateFDiv(lhs_primitive, rhs_primitive, "div");
    };

    const auto runtime_handler = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return CreateBinaryNumberFunctionCall(6, lhs, rhs);
    };

    return this->CreateBinop(lhs, rhs, specialized_int_handler, specialized_float_handler, runtime_handler);
}

llvm::Value *TythonBuilder::CreateTythonExp(llvm::Value *lhs, llvm::Value *rhs) {

    // There is no IR specialization for this binop.
    // All primitives must be wrapped in the appropriate object type and passed to the runtime!


    const auto specialized_int_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {

        // create wrapper integer objects around the primitives
        const auto lhs = this->CreateIntObject(lhs_primitive);
        const auto rhs = this->CreateIntObject(rhs_primitive);

        // invoke EXP on LHS
        return this->CreateBinaryNumberFunctionCall(7, lhs, rhs);
    };

    const auto specialized_float_handler = [this](llvm::Value* lhs_primitive, llvm::Value* rhs_primitive) -> llvm::Value* {

        // create wrapper float objects around the primitives
        const auto lhs = this->CreateFloatObject(lhs_primitive);
        const auto rhs = this->CreateFloatObject(rhs_primitive);

        // invoke EXP on LHS
        return this->CreateBinaryNumberFunctionCall(7, lhs, rhs);
    };

    const auto runtime_handler = [this](llvm::Value* lhs, llvm::Value* rhs) -> llvm::Value* {
        return this->CreateBinaryNumberFunctionCall(7, lhs, rhs);
    };

    return this->CreateBinop(lhs, rhs, specialized_int_handler, specialized_float_handler, runtime_handler);
}

llvm::Value *TythonBuilder::CreateGetIterator(llvm::Value *sequence) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    const auto seq_type_ref = this->CreateGetTypeObject(sequence);
    const auto seq_type = this->CreateLoad(ptr_t, seq_type_ref);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_ITERATOR_CREATE);

    auto it_create_ref = this->CreateGEP(this->typeobject_type, seq_type, {zero, slot });

    auto it_create_f = this->CreateLoad(ptr_t, it_create_ref);
    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t, int32_t }, false);

    return this->CreateCall(function_type, it_create_f, { sequence }, "it_create");
}

llvm::Value *TythonBuilder::CallIteratorNext(llvm::Value *it) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    const auto it_type_ref = this->CreateGetTypeObject(it);
    const auto it_type = this->CreateLoad(ptr_t, it_type_ref);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_ITERATOR_NEXT);

    auto it_next_ref = this->CreateGEP(this->typeobject_type, it_type, {zero, slot });

    auto it_next_f = this->CreateLoad(ptr_t, it_next_ref);
    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t, int32_t }, false);

    return this->CreateCall(function_type, it_next_f, { it }, "it_next");
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

llvm::Value *TythonBuilder::CreateTakeSlice(llvm::Value *object, llvm::Value *slice) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    const auto object_type_ref = this->CreateGetTypeObject(object);
    const auto object_type = this->CreateLoad(ptr_t, object_type_ref);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto one = llvm::ConstantInt::get(int32_t, 1);
    const auto mapping_functions_slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_SEQUENCE_FUNCTIONS);

    auto mapping_functions_ref = this->CreateGEP(this->typeobject_type, object_type, { zero, mapping_functions_slot });
    auto mapping_functions = this->CreateLoad(ptr_t, mapping_functions_ref);

    auto take_slice_ref = this->CreateGEP(this->mapping_functions_type, mapping_functions, {zero, one });
    auto take_slice_f = this->CreateLoad(ptr_t, take_slice_ref);

    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t, ptr_t }, false);

    return this->CreateCall(function_type, take_slice_f, {object, slice }, "take_slice");
}

llvm::Value *TythonBuilder::CreateIntObject(llvm::Value *content) {

    if (!content->getType()->isIntegerTy()) {
        throw CompileException("Cannot construct an integer object with anything other than a first-order integer.");
    }

    return this->CreateCall(*this->module->int_create_func, { content }, "integerobject");
}

llvm::Value* TythonBuilder::CreateFloatObject(llvm::Value* content) {

    const auto t = content->getType();

    if (!(t->isFloatTy() || t->isDoubleTy())) {
        throw CompileException("Cannot construct a floating-point object with anything other than a first-order floating-point.");
    }

    return (llvm::Value*)this->CreateCall(*this->module->float_create_func, { content }, "floatobject");
}

llvm::Value *TythonBuilder::CreateStringObject(llvm::Value *cstr, llvm::Value *length) {
    return (llvm::Value*)this->CreateCall(*this->module->string_create_func, { cstr, length }, "stringobject");
}

llvm::Value* TythonBuilder::CreateVariable(const std::string &name) {

    if (this->current_context->findVariable(name)) {
        throw CompileException("Attempt to create variable with existing name in scope!");
    }

    llvm::Value* alloc;

    if (this->current_context->isGlobal()) {

        llvm::Constant *zeroInit = llvm::ConstantAggregateZero::get(this->getPtrTy());
        alloc = new llvm::GlobalVariable(*this->module, this->getPtrTy(), false, llvm::GlobalValue::InternalLinkage, zeroInit, name);

    } else {

        alloc = this->CreateAlloca(this->getPtrTy(), nullptr, name);
    }

#if GC_ENABLED
    // default value is None, otherwise the GC infrastructure would try to grab a reference on a garbage pointer (not an object instance)
    this->CreateStore(this->none_object_instance, alloc);
#endif

    // register and return reference
    this->current_context->registerVariable(name, alloc);
    return this->current_context->findVariable(name);
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

llvm::Value* TythonBuilder::CreateTupleLiteral(llvm::Value *count, std::vector<llvm::Value *> &elements) {

    auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
    auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    auto f = this->module->tuple_create_func;
    auto tuple_ref = this->CreateCall((llvm::Function*)f->getCallee(), {count }, "tuple_create");

    // steal the elements reference off of the tuple object
    size_t offset = offsetof(tuple_object, elements);
    auto offset_value = llvm::ConstantInt::get(int64_t, offset);
    auto ptr_loc = this->CreatePtrToInt(tuple_ref, int64_t);
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

    return tuple_ref;
}

void TythonBuilder::CreateGrabObject(llvm::Value *object) {

#if GC_ENABLED

    // todo: specialization type check (only attempt to GC heap allocated objects)

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    const auto typeobject_ref = this->CreateGetTypeObject(object);
    const auto typeobject = this->CreateLoad(ptr_t, typeobject_ref);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto grab_slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_GRAB);

    auto grab_ref = this->CreateGEP(this->typeobject_type, typeobject, {zero, grab_slot });
    auto grab_f = this->CreateLoad(ptr_t, grab_ref);

    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t }, false);

    this->CreateCall(function_type, grab_f, {object }, "grab");

#endif

}

void TythonBuilder::CreateReleaseObject(llvm::Value *object) {

#if GC_ENABLED

    // todo: specialization type check (only attempt to GC heap allocated objects)

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto ptr_t = llvm::PointerType::get(this->object_type, 0);

    const auto typeobject_ref = this->CreateGetTypeObject(object);
    const auto typeobject = this->CreateLoad(ptr_t, typeobject_ref);

    const auto zero = llvm::ConstantInt::get(int32_t, 0);
    const auto release_slot = llvm::ConstantInt::get(int32_t, TYTHON_TYPE_SLOT_RELEASE);

    auto release_ref = this->CreateGEP(this->typeobject_type, typeobject, {zero, release_slot });
    auto release_f = this->CreateLoad(ptr_t, release_ref);

    auto function_type = llvm::FunctionType::get(ptr_t, { ptr_t }, false);

    this->CreateCall(function_type, release_f, {object }, "release");

#endif

}

llvm::Value* TythonBuilder::CreateSpecInstance(int32_t type_tag, llvm::Value *value, bool isLocal, std::string name) {

    const auto int32_t = llvm::IntegerType::getInt32Ty(this->getContext());
    const auto type_tag_value = llvm::ConstantInt::get(int32_t, type_tag);

    llvm::Value* instance;

    if (isLocal) {
        instance = this->CreateAlloca(this->specialization_type);
    } else {
        llvm::Constant *zeroInit = llvm::ConstantAggregateZero::get(this->specialization_type);
        instance = new llvm::GlobalVariable(*this->module, this->specialization_type, false, llvm::GlobalValue::InternalLinkage, zeroInit, name);
    }

    this->CreateStore(type_tag_value, instance);

    // todo: cast value type to int64_t
    const auto int64_t = llvm::IntegerType::getInt64Ty(this->getContext());
    llvm::Value* bitcast;

    if (value->getType()->isPointerTy()) {
        // pointer cast must be explicit
        bitcast = this->CreatePtrToInt(value, int64_t);
    } else {
        bitcast = this->CreateBitCast(value, int64_t);
    }

    const auto ref = this->CreateStructGEP(this->specialization_type, instance, 1);

    this->CreateStore(bitcast, ref);

    return instance;
}
