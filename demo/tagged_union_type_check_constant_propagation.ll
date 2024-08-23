; ModuleID = 'scratch_module'
source_filename = "test/scratch.ty"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%SpecializationType.2 = type { i32, ptr }

define i64 @main() {
entry:
  %lhs = alloca %SpecializationType.2, align 8
  store i32 0, ptr %lhs, align 4
  %lhs_content = getelementptr inbounds %SpecializationType.2, ptr %lhs, i32 0, i32 1
  store i64 1, ptr %lhs_content, align 8
  %rhs = alloca %SpecializationType.2, align 8
  store i32 0, ptr %rhs, align 4
  %rhs_content = getelementptr inbounds %SpecializationType.2, ptr %rhs, i32 0, i32 1
  store i64 2, ptr %rhs_content, align 8
  %result = alloca %SpecializationType.2, align 8
  %lhs_type = load i32, ptr %lhs, align 4
  %cond = icmp eq i32 %lhs_type, 0
  br i1 %cond, label %int_spec_block, label %switch_exit_block

int_spec_block:                                   ; preds = %entry
  %rhs_type = load i32, ptr %rhs, align 4
  %cond2 = icmp eq i32 %rhs_type, 0
  br i1 %cond2, label %int_simple_block, label %switch_exit_block

int_simple_block:                                  ; preds = %int_spec_block
  %lhs_content_ref = getelementptr inbounds %SpecializationType.2, ptr %lhs, i32 0, i32 1
  %lhs_content1 = load i64, ptr %lhs_content_ref, align 8
  %rhs_content_ref = getelementptr inbounds %SpecializationType.2, ptr %rhs, i32 0, i32 1
  %rhs_content1 = load i64, ptr %rhs_content_ref, align 8
  %sum = add i64 %lhs_content1, %rhs_content1
  store i32 0, ptr %result, align 4
  %result_content = getelementptr inbounds %SpecializationType.2, ptr %result, i32 0, i32 1
  store i64 %sum, ptr %result_content, align 8
  br label %switch_exit_block

switch_exit_block:                                ; preds = %int_simple_block, %int_spec_block, %entry

  %result_content1 = getelementptr inbounds %SpecializationType.2, ptr %result, i32 0, i32 1
  %ret = load i64, ptr %result_content1, align 8
  ret i64 %ret
}
