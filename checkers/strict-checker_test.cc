#include "checkers/strict-checker.h"

#include <memory>

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(StrictCheckerTest, Basic) {
  std::unique_ptr<Checker> strict_checker = std::make_unique<StrictChecker>();
  EXPECT_EQ(strict_checker->Check("", "", ""), Verdict::kUndecided);
  EXPECT_EQ(strict_checker->Check("", "Foo", "Foo"), Verdict::kAccepted);
  EXPECT_EQ(strict_checker->Check("", "Foo", "Bar"), Verdict::kRejected);
  EXPECT_EQ(strict_checker->Check("", "1", "1"), Verdict::kAccepted);
  EXPECT_EQ(strict_checker->Check("", "Foo", "Foo Bar"), Verdict::kRejected);
}

}  // namespace
}  // namespace contest_wizard
