// Copyright Hieu Le 2016.

#include "util/status.h"

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(StatusTest, DefaultConstructor) {
  Status status;
  EXPECT_TRUE(status.ok());
}

TEST(StatusTest, CustomConstructor) {
  Status status(error::Code::NOT_FOUND, "Not found status.");
  EXPECT_FALSE(status.ok());
  EXPECT_EQ(status.error_message(), "Not found status.");
}

}  // namespace
}  // namespace contest_wizard
