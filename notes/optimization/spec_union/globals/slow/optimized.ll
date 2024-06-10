; ModuleID = 'build/ir/scratch.ll'
source_filename = "test/scratch.ty"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Object.1 = type { ptr, ptr, i32 }
%SpecializationType.0 = type { i32, i64 }
%Object.TypeObject.2 = type { ptr, ptr, i32, ptr, i64, i64, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }

@none_instance = external externally_initialized constant %Object.1
@a = internal unnamed_addr global %SpecializationType.0 zeroinitializer

declare void @throw_type_error(%SpecializationType.0, i32) local_unnamed_addr

declare void @print(%SpecializationType.0) local_unnamed_addr

declare i64 @object_to_primitive(ptr, i32) local_unnamed_addr

define i64 @main() local_unnamed_addr {
entry:
  store ptr @none_instance, ptr @a, align 8
  br label %pre_while

pre_while:                                        ; preds = %pre_while.backedge, %entry
  %storemerge = phi i64 [ 0, %entry ], [ %storemerge.be, %pre_while.backedge ]
  store i32 0, ptr @a, align 8
  store i64 %storemerge, ptr getelementptr inbounds (%SpecializationType.0, ptr @a, i64 0, i32 1), align 8
  %0 = load %SpecializationType.0, ptr @a, align 8
  %tag = extractvalue %SpecializationType.0 %0, 0
  %content = extractvalue %SpecializationType.0 %0, 1
  switch i32 %tag, label %catchall_block [
    i32 0, label %rhs_int_block
    i32 1, label %rhs_int_block7
    i32 2, label %switch_exit_block
  ]

while:                                            ; preds = %catchall_block, %rhs_int_block7, %rhs_int_block, %switch_exit_block
  %1 = load %SpecializationType.0, ptr @a, align 8
  %tag46 = extractvalue %SpecializationType.0 %1, 0
  switch i32 %tag46, label %catchall_block48 [
    i32 0, label %switch_exit_block47
    i32 1, label %switch_exit_block47
    i32 2, label %object_handler_block49
  ]

end_while:                                        ; preds = %rhs_int_block, %switch_exit_block
  ret i64 0

catchall_block:                                   ; preds = %pre_while
  tail call void @throw_type_error(%SpecializationType.0 %0, i32 -1)
  br label %while

switch_exit_block:                                ; preds = %pre_while
  %2 = inttoptr i64 %content to ptr
  %lhs_primitive = tail call i64 @object_to_primitive(ptr %2, i32 0)
  %3 = icmp ult i64 %lhs_primitive, 10
  br i1 %3, label %while, label %end_while

rhs_int_block:                                    ; preds = %pre_while
  %4 = icmp ult i64 %content, 10
  br i1 %4, label %while, label %end_while

rhs_int_block7:                                   ; preds = %pre_while
  tail call void @throw_type_error(%SpecializationType.0 { i32 0, i64 10 }, i32 1)
  br label %while

object_handler_block49:                           ; preds = %while
  %content54 = extractvalue %SpecializationType.0 %1, 1
  %5 = inttoptr i64 %content54 to ptr
  %6 = getelementptr inbounds %Object.1, ptr %5, i64 0, i32 1
  %7 = load ptr, ptr %6, align 8
  %8 = getelementptr %Object.TypeObject.2, ptr %7, i64 0, i32 17
  %9 = load ptr, ptr %8, align 8
  %grab = tail call ptr %9(ptr %5)
  br label %switch_exit_block47

catchall_block48:                                 ; preds = %while
  tail call void @throw_type_error(%SpecializationType.0 %1, i32 -1)
  br label %switch_exit_block47

switch_exit_block47:                              ; preds = %while, %while, %catchall_block48, %object_handler_block49
  tail call void @print(%SpecializationType.0 %1)
  %10 = load %SpecializationType.0, ptr @a, align 8
  %tag57 = extractvalue %SpecializationType.0 %10, 0
  %content58 = extractvalue %SpecializationType.0 %10, 1
  switch i32 %tag57, label %catchall_block60 [
    i32 0, label %rhs_int_block64
    i32 1, label %rhs_int_block75
    i32 2, label %rhs_int_block87
  ]

catchall_block60:                                 ; preds = %switch_exit_block47
  tail call void @throw_type_error(%SpecializationType.0 %10, i32 -1)
  br label %pre_while.backedge

rhs_int_block64:                                  ; preds = %switch_exit_block47
  %sum = add i64 %content58, 1
  br label %pre_while.backedge

rhs_int_block75:                                  ; preds = %switch_exit_block47
  tail call void @throw_type_error(%SpecializationType.0 { i32 0, i64 1 }, i32 1)
  br label %pre_while.backedge

rhs_int_block87:                                  ; preds = %switch_exit_block47
  %11 = inttoptr i64 %content58 to ptr
  %lhs_primitive90 = tail call i64 @object_to_primitive(ptr %11, i32 0)
  %sum91 = add i64 %lhs_primitive90, 1
  br label %pre_while.backedge

pre_while.backedge:                               ; preds = %rhs_int_block87, %rhs_int_block75, %rhs_int_block64, %catchall_block60
  %storemerge.be = phi i64 [ %sum, %rhs_int_block64 ], [ undef, %rhs_int_block75 ], [ %sum91, %rhs_int_block87 ], [ undef, %catchall_block60 ]
  br label %pre_while
}
