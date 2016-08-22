// Copyright 2016 Hieu Le.

#include "checkers/token-checker.h"

#include <memory>

#include "gtest/gtest.h"
#include "util/string_util.h"

namespace contest_wizard {
namespace {

void Validate(const Checker& checker, const std::string& expected,
              const std::string& actual, const Outcome outcome,
              const std::string& message) {
  const Verdict verdict = checker.Check("", expected, actual);
  EXPECT_EQ(verdict.GetOutcome(), outcome);
  EXPECT_TRUE(Contains(verdict.GetMessage(), message));
}

TEST(TokenChecker, ExactMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0, false, false);
  Validate(*token_checker, "", "3.14", Outcome::kUndecided, "");
  Validate(*token_checker, "3.14", "", Outcome::kRejected, "");
  Validate(*token_checker, "3.14", "3.14", Outcome::kAccepted, "");
  Validate(*token_checker, "3.14", "3.00", Outcome::kRejected, "");
  Validate(*token_checker, "3.14", "3.140", Outcome::kRejected, "");
  Validate(*token_checker, "Foo", "Foo", Outcome::kAccepted, "");
  Validate(*token_checker, "Foo", "Bar", Outcome::kRejected, "");
  Validate(*token_checker, "3.14", "Foo", Outcome::kRejected, "");
  Validate(*token_checker, "Foo", "3.14", Outcome::kRejected, "");
  Validate(*token_checker, "Foo Bar", "Foo", Outcome::kRejected, "");
  Validate(*token_checker, "Foo", "Foo Bar", Outcome::kRejected, "");
}

TEST(TokenChecker, AbsoluteMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0.01, true, false);
  Validate(*token_checker, "3.14", "3.14", Outcome::kAccepted, "");
  Validate(*token_checker, "3.14", "3.15", Outcome::kAccepted, "");
  Validate(*token_checker, "3.15", "3.14", Outcome::kAccepted, "");
  Validate(*token_checker, "3.14 3.14", "3.14 3.15", Outcome::kAccepted, "");
  Validate(*token_checker, "3.14", "3.151", Outcome::kRejected, "");
  Validate(*token_checker, "3.151", "3.14", Outcome::kRejected, "");
  Validate(*token_checker, "3.14 3.14 3.14", "3.14 3.15 3.151",
           Outcome::kRejected, "");
}

TEST(TokenChecker, RelativeMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0.1, false, true);
  Validate(*token_checker, "100", "100", Outcome::kAccepted, "");
  Validate(*token_checker, "100", "110", Outcome::kAccepted, "");
  Validate(*token_checker, "100", "90", Outcome::kAccepted, "");
  Validate(*token_checker, "0", "0", Outcome::kAccepted, "");
  Validate(*token_checker, "0", "0.1", Outcome::kAccepted, "");
  Validate(*token_checker, "100 100 100", "100 110 90", Outcome::kAccepted, "");
  Validate(*token_checker, "100", "111", Outcome::kRejected, "");
  Validate(*token_checker, "100", "89", Outcome::kRejected, "");
  Validate(*token_checker, "0", "0.2", Outcome::kRejected, "");
  Validate(*token_checker, "100 100 100", "100 90 89", Outcome::kRejected, "");
}

TEST(TokenChecker, AbsoluteAndRelativeMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0.1, true, true);
  Validate(*token_checker, "3.14 100", "3.14 100", Outcome::kAccepted, "");
  Validate(*token_checker, "3.14 100", "3.15 110", Outcome::kAccepted, "");
  Validate(*token_checker, "3.14 100", "3.14 111", Outcome::kRejected, "");
  Validate(*token_checker, "100 0.14", "110 0.25", Outcome::kRejected, "");
}

}  // namespace
}  // namespace contest_wizard
