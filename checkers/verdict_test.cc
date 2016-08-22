// Copyright 2016 Hieu Le.

#include "checkers/verdict.h"

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(VerdictTest, Accessors) {
  {
    Verdict verdict(Outcome::kUndecided);
    EXPECT_EQ(verdict.GetOutcome(), Outcome::kUndecided);
  }
  {
    const std::string message = "Accepted outcome";
    Verdict verdict(Outcome::kAccepted, message);
    EXPECT_EQ(verdict.GetOutcome(), Outcome::kAccepted);
    EXPECT_EQ(verdict.GetMessage(), message);
  }
}

}  // namespace
}  // namespace contest_wizard
