// Copyright 2016 Hieu Le.

#include "util/file-util.h"

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(FileUtilTest, IsDirectory) {
  EXPECT_FALSE(IsDirectory("foo/bar/baz"));
  EXPECT_TRUE(IsDirectory("/Users/hieule/workspace/contest_wizard/util"));
}

TEST(FileUtilTest, MakeDirectory) {
  EXPECT_FALSE(MakeDirectory("foo/bar/baz").ok());
  EXPECT_TRUE(MakeDirectory(
      "/Users/hieule/workspace/contest_wizard/util/foo").ok());
}

}  // namespace
}  // namespace contest_wizard
