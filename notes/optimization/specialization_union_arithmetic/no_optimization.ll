; ModuleID = 'scratch_module'
source_filename = "test/scratch.ty"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Object.0 = type { ptr, ptr, i32 }
%SpecializationType.2 = type { i32, i64 }
%Object.TypeObject.1 = type { ptr, ptr, i32, ptr, i64, i64, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }

@none_instance = external externally_initialized constant %Object.0
@c = internal global ptr zeroinitializer

declare ptr @int_create(i64 %0)

declare ptr @float_create(double %0)

declare ptr @string_create(ptr %0, i64 %1)

declare ptr @dict_create(i64 %0)

declare ptr @list_create(i64 %0)

declare ptr @tuple_create(i64 %0)

declare void @print(ptr %0)

declare ptr @range_create(ptr %0, ptr %1, ptr %2)

declare ptr @len(ptr %0)

declare ptr @slice(ptr %0, ptr %1, ptr %2)

declare ptr @list(ptr %0)

declare i32 @object_is_truthy(ptr %0)

declare ptr @resolve_builtin_method(ptr %0, ptr %1)

declare i64 @object_to_primitive(ptr %0, i32 %1)

define i64 @main() {
entry:
  %0 = alloca %SpecializationType.2, align 8
  store i32 0, ptr %0, align 4
  %1 = getelementptr inbounds %SpecializationType.2, ptr %0, i32 0, i32 1
  store i64 1, ptr %1, align 4
  %2 = alloca %SpecializationType.2, align 8
  store i32 0, ptr %2, align 4
  %3 = getelementptr inbounds %SpecializationType.2, ptr %2, i32 0, i32 1
  store i64 2, ptr %3, align 4
  %4 = bitcast ptr %0 to ptr
  %lhs_type_tag = load i32, ptr %4, align 4
  %5 = getelementptr inbounds %SpecializationType.2, ptr %0, i32 0, i32 1
  %lhs_value = load i64, ptr %5, align 4
  %rhs_type_tag14 = bitcast ptr %2 to ptr
  %6 = load i32, ptr %rhs_type_tag14, align 4
  %7 = getelementptr inbounds %SpecializationType.2, ptr %2, i32 0, i32 1
  %rhs_value = load i64, ptr %7, align 4
  %8 = alloca %SpecializationType.2, align 8
  switch i32 %lhs_type_tag, label %switch_exit_block [
    i32 0, label %lhs_int_block
    i32 1, label %lhs_float_block
    i32 2, label %lhs_object_block
  ]

lhs_int_block:                                    ; preds = %entry
  switch i32 %6, label %switch_exit_block [
    i32 0, label %rhs_int_block
    i32 2, label %rhs_object_block
  ]

lhs_float_block:                                  ; preds = %entry
  switch i32 %6, label %switch_exit_block [
    i32 2, label %rhs_object_block4
    i32 1, label %rhs_float_block3
  ]

lhs_object_block:                                 ; preds = %entry
  switch i32 %6, label %switch_exit_block [
    i32 0, label %rhs_int_block8
    i32 1, label %rhs_float_block9
    i32 2, label %rhs_object_block10
  ]

switch_exit_block:                                ; preds = %entry, %lhs_int_block, %lhs_float_block, %lhs_object_block, %rhs_object_block10, %rhs_float_block9, %rhs_int_block8, %rhs_object_block4, %rhs_float_block3, %rhs_object_block, %rhs_int_block
  %9 = bitcast ptr %8 to ptr
  %10 = load i32, ptr %9, align 4
  %11 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  %12 = load i64, ptr %11, align 4
  store i32 %10, ptr @c, align 4
  store i64 %12, ptr getelementptr inbounds (%SpecializationType.2, ptr @c, i32 0, i32 1), align 4
  call void @print(ptr @c)
  ret i64 0

rhs_int_block:                                    ; preds = %lhs_int_block
  %sum = add i64 %lhs_value, %rhs_value
  store i32 0, ptr %8, align 4
  %13 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  store i64 %sum, ptr %13, align 4
  br label %switch_exit_block

rhs_object_block:                                 ; preds = %lhs_int_block
  %14 = inttoptr i64 %rhs_value to ptr
  %rhs_primitive = call i64 @object_to_primitive(ptr %14, i32 0)
  %sum1 = add i64 %lhs_value, %rhs_primitive
  store i32 0, ptr %8, align 4
  %15 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  store i64 %sum1, ptr %15, align 4
  br label %switch_exit_block

rhs_float_block3:                                 ; preds = %lhs_float_block
  %16 = bitcast i64 %rhs_value to double
  %17 = bitcast i64 %lhs_value to double
  %sum5 = fadd double %17, %16
  store i32 1, ptr %8, align 4
  %18 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  %19 = bitcast double %sum5 to i64
  store i64 %19, ptr %18, align 4
  br label %switch_exit_block

rhs_object_block4:                                ; preds = %lhs_float_block
  %20 = inttoptr i64 %rhs_value to ptr
  %rhs_primitive6 = call i64 @object_to_primitive(ptr %20, i32 1)
  %21 = bitcast i64 %rhs_primitive6 to double
  %22 = bitcast i64 %lhs_value to double
  %sum7 = fadd double %22, %21
  store i32 1, ptr %8, align 4
  %23 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  %24 = bitcast double %sum7 to i64
  store i64 %24, ptr %23, align 4
  br label %switch_exit_block

rhs_int_block8:                                   ; preds = %lhs_object_block
  %25 = inttoptr i64 %lhs_value to ptr
  %lhs_primitive = call i64 @object_to_primitive(ptr %25, i32 0)
  %sum11 = add i64 %lhs_primitive, %rhs_value
  store i32 0, ptr %8, align 4
  %26 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  store i64 %sum11, ptr %26, align 4
  br label %switch_exit_block

rhs_float_block9:                                 ; preds = %lhs_object_block
  %27 = inttoptr i64 %lhs_value to ptr
  %lhs_primitive12 = call i64 @object_to_primitive(ptr %27, i32 1)
  %28 = bitcast i64 %rhs_value to double
  %29 = bitcast i64 %lhs_primitive12 to double
  %sum13 = fadd double %29, %28
  store i32 1, ptr %8, align 4
  %30 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  %31 = bitcast double %sum13 to i64
  store i64 %31, ptr %30, align 4
  br label %switch_exit_block

rhs_object_block10:                               ; preds = %lhs_object_block
  %32 = inttoptr i64 %lhs_value to ptr
  %33 = inttoptr i64 %rhs_value to ptr
  %34 = getelementptr inbounds %Object.0, ptr %32, i32 0, i32 1
  %35 = load ptr, ptr %34, align 8
  %36 = getelementptr %Object.TypeObject.1, ptr %35, i32 0, i32 11
  %37 = load ptr, ptr %36, align 8
  %38 = getelementptr <{ ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }>, ptr %37, i32 0, i32 3
  %number_function_ref = load ptr, ptr %38, align 8
  %number_function_call = call ptr %number_function_ref(ptr %32, ptr %33)
  store i64 2, ptr %8, align 4
  %39 = getelementptr inbounds %SpecializationType.2, ptr %8, i32 0, i32 1
  %40 = bitcast ptr %number_function_call to i64
  store i64 %40, ptr %39, align 4
  br label %switch_exit_block
}
