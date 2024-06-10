; ModuleID = 'scratch_module'
source_filename = "test/scratch.ty"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Object.0 = type { ptr, ptr, i32 }
%SpecializationType.2 = type { i32, i64 }

@none_instance = external externally_initialized constant %Object.0
@a = internal global ptr zeroinitializer
@b = internal global ptr zeroinitializer
@c = internal global ptr zeroinitializer

declare ptr @int_create(i64)

declare ptr @float_create(double)

declare ptr @string_create(ptr, i64)

declare ptr @dict_create(i64)

declare ptr @list_create(i64)

declare ptr @tuple_create(i64)

declare void @print(ptr)

declare ptr @range_create(ptr, ptr, ptr)

declare ptr @len(ptr)

declare ptr @slice(ptr, ptr, ptr)

declare ptr @list(ptr)

declare i32 @object_is_truthy(ptr)

declare ptr @resolve_builtin_method(ptr, ptr)

declare i64 @int_object_to_primitive(ptr, i32)

define i64 @main() {
entry:
  store i32 0, ptr @a, align 4
  store i64 1, ptr getelementptr inbounds (%SpecializationType.2, ptr @a, i32 0, i32 1), align 4
  store i32 0, ptr @b, align 4
  store i64 2, ptr getelementptr inbounds (%SpecializationType.2, ptr @b, i32 0, i32 1), align 4
  %lhs_type_enum = load i32, ptr @a, align 4
  %cond = icmp eq i32 %lhs_type_enum, 0
  %0 = load i32, ptr @b, align 4
  %rhs_type_check = icmp eq i32 %0, 0
  %or.cond = select i1 %cond, i1 %rhs_type_check, i1 false
  br i1 %or.cond, label %simple_block, label %switch_exit_block

switch_exit_block:                                ; preds = %entry, %simple_block
  %.sroa.2.sroa.1.0 = phi i64 [ %sum, %simple_block ], [ undef, %entry ]
  store i32 0, ptr @c, align 4
  store i64 %.sroa.2.sroa.1.0, ptr getelementptr inbounds (%SpecializationType.2, ptr @c, i32 0, i32 1), align 4
  call void @print(ptr @c)
  ret i64 0

simple_block:                                     ; preds = %entry
  %lhs_value = load i64, ptr getelementptr inbounds (%SpecializationType.2, ptr @a, i32 0, i32 1), align 4
  %rhs_value = load i64, ptr getelementptr inbounds (%SpecializationType.2, ptr @b, i32 0, i32 1), align 4
  %sum = add i64 %lhs_value, %rhs_value
  br label %switch_exit_block
}
