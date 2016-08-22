// Copyright 2016 Hieu Le.

#include "checkers/strict-checker.h"

#include <memory>

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(StrictCheckerTest, Basic) {
  std::unique_ptr<Checker> strict_checker = std::make_unique<StrictChecker>();
  EXPECT_EQ(strict_checker->Check("", "", "").GetOutcome(),
            Outcome::kUndecided);
  EXPECT_EQ(strict_checker->Check("", "Foo", "Foo").GetOutcome(),
            Outcome::kAccepted);
  EXPECT_EQ(strict_checker->Check("", "Foo", "Bar").GetOutcome(),
            Outcome::kRejected);
  EXPECT_EQ(strict_checker->Check("", "1", "1").GetOutcome(),
            Outcome::kAccepted);
  EXPECT_EQ(strict_checker->Check("", "Foo", "Foo Bar").GetOutcome(),
            Outcome::kRejected);
}

}  // namespace
}  // namespace contest_wizard
