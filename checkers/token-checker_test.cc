// Copyright 2016 Hieu Le.

#include "checkers/token-checker.h"

#include <memory>

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(TokenChecker, ExactMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0, false, false);
  EXPECT_EQ(token_checker->Check("", "", "3.14"), Verdict::kUndecided);
  EXPECT_EQ(token_checker->Check("", "3.14", ""), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "3.14", "3.14"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "3.14", "3.00"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "3.14", "3.140"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "Foo", "Foo"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "Foo", "Bar"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "3.14", "Foo"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "Foo", "3.14"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "Foo Bar", "Foo"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "Foo", "Foo Bar"), Verdict::kRejected);
}

TEST(TokenChecker, AbsoluteMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0.01, true, false);
  EXPECT_EQ(token_checker->Check("", "3.14", "3.14"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "3.14", "3.15"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "3.15", "3.14"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "3.14 3.14", "3.14 3.15"),
            Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "3.14", "3.151"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "3.151", "3.14"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "3.14 3.14 3.14", "3.14 3.15 3.151"),
            Verdict::kRejected);
}

TEST(TokenChecker, RelativeMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0.1, false, true);
  EXPECT_EQ(token_checker->Check("", "100", "100"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "100", "110"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "100", "90"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "0", "0"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "0", "0.1"), Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "100 100 100", "100 110 90"),
            Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "100", "111"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "100", "89"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "0", "0.2"), Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "100 100 100", "100 90 89"),
            Verdict::kRejected);
}

TEST(TokenChecker, AbsoluteAndRelativeMatch) {
  std::unique_ptr<Checker> token_checker =
      std::make_unique<TokenChecker>(0.1, true, true);
  EXPECT_EQ(token_checker->Check("", "3.14 100", "3.14 100"),
            Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "3.14 100", "3.15 110"),
            Verdict::kAccepted);
  EXPECT_EQ(token_checker->Check("", "3.14 100", "3.14 111"),
            Verdict::kRejected);
  EXPECT_EQ(token_checker->Check("", "100 0.14", "110 0.25"),
            Verdict::kRejected);
}

}  // namespace
}  // namespace contest_wizard
