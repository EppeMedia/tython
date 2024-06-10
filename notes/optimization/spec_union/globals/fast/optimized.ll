; ModuleID = 'build/ir/scratch.ll'
source_filename = "test/scratch.ty"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%Object.1 = type { ptr, ptr, i32 }
%SpecializationType.0 = type { i32, i64 }

@none_instance = external externally_initialized constant %Object.1

declare void @print(%SpecializationType.0) local_unnamed_addr

define i64 @main() local_unnamed_addr {
entry:
  tail call void @print(%SpecializationType.0 zeroinitializer)
  tail call void @print(%SpecializationType.0 { i32 0, i64 1 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 2 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 3 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 4 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 5 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 6 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 7 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 8 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 9 })
  ret i64 0
}

define %SpecializationType.0 @foo() local_unnamed_addr {
prologue:
  tail call void @print(%SpecializationType.0 zeroinitializer)
  tail call void @print(%SpecializationType.0 { i32 0, i64 1 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 2 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 3 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 4 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 5 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 6 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 7 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 8 })
  tail call void @print(%SpecializationType.0 { i32 0, i64 9 })
  ret %SpecializationType.0 { i32 2, i64 ptrtoint (ptr @none_instance to i64) }
}
