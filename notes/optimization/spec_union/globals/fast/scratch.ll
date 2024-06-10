; ModuleID = 'scratch_module'
source_filename = "test/scratch.ty"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Object.1 = type { ptr, ptr, i32 }
%SpecializationType.0 = type { i32, i64 }
%Object.TypeObject.2 = type { ptr, ptr, i32, ptr, i64, i64, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }

@none_instance = external externally_initialized constant %Object.1

declare ptr @int_create(i64)

declare ptr @float_create(double)

declare ptr @string_create(ptr, i64)

declare ptr @dict_create(i64)

declare ptr @list_create(i64)

declare ptr @tuple_create(i64)

declare void @throw_type_error(%SpecializationType.0, i32)

declare void @print(%SpecializationType.0)

declare %SpecializationType.0 @range(%SpecializationType.0, %SpecializationType.0, %SpecializationType.0)

declare %SpecializationType.0 @__dict__(i64, ...)

declare %SpecializationType.0 @__list__(i64, ...)

declare %SpecializationType.0 @__tuple__(i64, ...)

declare void @__set__(%SpecializationType.0, %SpecializationType.0, %SpecializationType.0)

declare %SpecializationType.0 @len(%SpecializationType.0)

declare %SpecializationType.0 @slice(%SpecializationType.0, %SpecializationType.0, %SpecializationType.0)

declare %SpecializationType.0 @list(%SpecializationType.0)

declare i64 @object_is_truthy(ptr)

declare ptr @resolve_builtin_method(ptr, ptr)

declare i64 @object_to_primitive(ptr, i32)

define i64 @main() {
entry:
  %0 = call %SpecializationType.0 @foo()
  %content = extractvalue %SpecializationType.0 %0, 1
  %content1 = insertvalue %SpecializationType.0 { i32 2, i64 0 }, i64 %content, 1
  ret i64 0
}

define %SpecializationType.0 @foo() {
prologue:
  %a = alloca %SpecializationType.0, align 8
  store ptr @none_instance, ptr %a, align 8
  %0 = bitcast ptr %a to ptr
  %1 = getelementptr inbounds %SpecializationType.0, ptr %a, i32 0, i32 1
  store i32 0, ptr %0, align 4
  store i64 0, ptr %1, align 4
  br label %pre_while

pre_while:                                        ; preds = %switch_exit_block59, %prologue
  %2 = load %SpecializationType.0, ptr %a, align 4
  %tag = extractvalue %SpecializationType.0 %2, 0
  %content = extractvalue %SpecializationType.0 %2, 1
  switch i32 %tag, label %catchall_block [
    i32 0, label %rhs_int_block
    i32 1, label %rhs_int_block7
    i32 2, label %rhs_int_block17
  ]

while:                                            ; preds = %switch_exit_block
  %3 = load %SpecializationType.0, ptr %a, align 4
  %tag46 = extractvalue %SpecializationType.0 %3, 0
  switch i32 %tag46, label %catchall_block48 [
    i32 0, label %int_handler_block51
    i32 1, label %float_handler_block50
    i32 2, label %object_handler_block49
  ]

end_while:                                        ; preds = %switch_exit_block
  %4 = load %SpecializationType.0, ptr %a, align 4
  %tag128 = extractvalue %SpecializationType.0 %4, 0
  switch i32 %tag128, label %catchall_block130 [
    i32 0, label %int_handler_block133
    i32 1, label %float_handler_block132
    i32 2, label %object_handler_block131
  ]

catchall_block:                                   ; preds = %pre_while
  call void @throw_type_error(%SpecializationType.0 %2, i32 -1)
  br label %switch_exit_block

switch_exit_block:                                ; preds = %catchall_block, %rhs_int_block17, %rhs_int_block7, %rhs_int_block
  %5 = phi i64 [ %content3, %rhs_int_block ], [ undef, %rhs_int_block7 ], [ %content21, %rhs_int_block17 ], [ undef, %catchall_block ]
  %content29 = insertvalue %SpecializationType.0 zeroinitializer, i64 %5, 1
  %content33 = extractvalue %SpecializationType.0 %content29, 1
  %content35 = extractvalue %SpecializationType.0 %content29, 1
  %content44 = insertvalue %SpecializationType.0 zeroinitializer, i64 %content35, 1
  %content45 = extractvalue %SpecializationType.0 %content44, 1
  %6 = trunc i64 %content45 to i1
  br i1 %6, label %while, label %end_while

rhs_int_block:                                    ; preds = %pre_while
  %7 = icmp ult i64 %content, 10
  %8 = zext i1 %7 to i64
  %content1 = insertvalue %SpecializationType.0 zeroinitializer, i64 %8, 1
  %content3 = extractvalue %SpecializationType.0 %content1, 1
  br label %switch_exit_block

rhs_int_block7:                                   ; preds = %pre_while
  call void @throw_type_error(%SpecializationType.0 { i32 0, i64 10 }, i32 1)
  br label %switch_exit_block

rhs_int_block17:                                  ; preds = %pre_while
  %9 = inttoptr i64 %content to ptr
  %lhs_primitive = call i64 @object_to_primitive(ptr %9, i32 0)
  %10 = icmp ult i64 %lhs_primitive, 10
  %11 = zext i1 %10 to i64
  %content20 = insertvalue %SpecializationType.0 zeroinitializer, i64 %11, 1
  %content21 = extractvalue %SpecializationType.0 %content20, 1
  br label %switch_exit_block

int_handler_block51:                              ; preds = %while
  %content52 = extractvalue %SpecializationType.0 %3, 1
  br label %switch_exit_block47

float_handler_block50:                            ; preds = %while
  %content53 = extractvalue %SpecializationType.0 %3, 1
  %12 = bitcast i64 %content53 to double
  br label %switch_exit_block47

object_handler_block49:                           ; preds = %while
  %content54 = extractvalue %SpecializationType.0 %3, 1
  %13 = inttoptr i64 %content54 to ptr
  %14 = getelementptr inbounds %Object.1, ptr %13, i32 0, i32 1
  %15 = load ptr, ptr %14, align 8
  %16 = getelementptr %Object.TypeObject.2, ptr %15, i32 0, i32 17
  %17 = load ptr, ptr %16, align 8
  %grab = call ptr %17(ptr %13)
  br label %switch_exit_block47

catchall_block48:                                 ; preds = %while
  call void @throw_type_error(%SpecializationType.0 %3, i32 -1)
  br label %switch_exit_block47

switch_exit_block47:                              ; preds = %catchall_block48, %object_handler_block49, %float_handler_block50, %int_handler_block51
  call void @print(%SpecializationType.0 %3)
  %18 = load %SpecializationType.0, ptr %a, align 4
  %tag57 = extractvalue %SpecializationType.0 %18, 0
  %content58 = extractvalue %SpecializationType.0 %18, 1
  switch i32 %tag57, label %catchall_block60 [
    i32 0, label %rhs_int_block64
    i32 1, label %rhs_int_block75
    i32 2, label %rhs_int_block87
  ]

catchall_block60:                                 ; preds = %switch_exit_block47
  call void @throw_type_error(%SpecializationType.0 %18, i32 -1)
  br label %switch_exit_block59

switch_exit_block59:                              ; preds = %catchall_block60, %rhs_int_block87, %rhs_int_block75, %rhs_int_block64
  %19 = phi i64 [ %content69, %rhs_int_block64 ], [ undef, %rhs_int_block75 ], [ %content93, %rhs_int_block87 ], [ undef, %catchall_block60 ]
  %content102 = insertvalue %SpecializationType.0 zeroinitializer, i64 %19, 1
  %content109 = extractvalue %SpecializationType.0 %content102, 1
  %content121 = extractvalue %SpecializationType.0 %content102, 1
  %20 = bitcast ptr %a to ptr
  %21 = getelementptr inbounds %SpecializationType.0, ptr %a, i32 0, i32 1
  %content127 = extractvalue %SpecializationType.0 %content102, 1
  store i32 0, ptr %20, align 4
  store i64 %content127, ptr %21, align 4
  br label %pre_while

rhs_int_block64:                                  ; preds = %switch_exit_block47
  %sum = add i64 %content58, 1
  %content67 = insertvalue %SpecializationType.0 zeroinitializer, i64 %sum, 1
  %content69 = extractvalue %SpecializationType.0 %content67, 1
  br label %switch_exit_block59

rhs_int_block75:                                  ; preds = %switch_exit_block47
  call void @throw_type_error(%SpecializationType.0 { i32 0, i64 1 }, i32 1)
  br label %switch_exit_block59

rhs_int_block87:                                  ; preds = %switch_exit_block47
  %22 = inttoptr i64 %content58 to ptr
  %lhs_primitive90 = call i64 @object_to_primitive(ptr %22, i32 0)
  %sum91 = add i64 %lhs_primitive90, 1
  %content92 = insertvalue %SpecializationType.0 zeroinitializer, i64 %sum91, 1
  %content93 = extractvalue %SpecializationType.0 %content92, 1
  br label %switch_exit_block59

int_handler_block133:                             ; preds = %end_while
  %content134 = extractvalue %SpecializationType.0 %4, 1
  br label %epilogue

float_handler_block132:                           ; preds = %end_while
  %content135 = extractvalue %SpecializationType.0 %4, 1
  %23 = bitcast i64 %content135 to double
  br label %epilogue

object_handler_block131:                          ; preds = %end_while
  %content136 = extractvalue %SpecializationType.0 %4, 1
  %24 = inttoptr i64 %content136 to ptr
  %25 = getelementptr inbounds %Object.1, ptr %24, i32 0, i32 1
  %26 = load ptr, ptr %25, align 8
  %27 = getelementptr %Object.TypeObject.2, ptr %26, i32 0, i32 18
  %28 = load ptr, ptr %27, align 8
  %release137 = call ptr %28(ptr %24)
  br label %epilogue

catchall_block130:                                ; preds = %end_while
  call void @throw_type_error(%SpecializationType.0 %4, i32 -1)
  br label %epilogue

epilogue:                                         ; preds = %int_handler_block133, %float_handler_block132, %object_handler_block131, %catchall_block130
  ret %SpecializationType.0 { i32 2, i64 ptrtoint (ptr @none_instance to i64) }
}
