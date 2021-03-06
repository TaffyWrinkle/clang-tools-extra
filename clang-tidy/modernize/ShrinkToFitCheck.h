//===--- ShrinkToFitCheck.h - clang-tidy-------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MODERNIZE_SHRINKTOFITCHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MODERNIZE_SHRINKTOFITCHECK_H

#include "../ClangTidy.h"

namespace clang {
namespace tidy {
namespace modernize {

/// Replace copy and swap tricks on shrinkable containers with the
/// `shrink_to_fit()` method call.
///
/// The `shrink_to_fit()` method is more readable and more effective than
/// the copy and swap trick to reduce the capacity of a shrinkable container.
/// Note that, the `shrink_to_fit()` method is only available in C++11 and up.
class ShrinkToFitCheck : public ClangTidyCheck {
public:
  ShrinkToFitCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace modernize
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MODERNIZE_SHRINKTOFITCHECK_H
