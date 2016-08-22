// Copyright 2016 Hieu Le.

#include "util/string_util.h"

#include <iostream>

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(StrCatTest, ConcatWithInitializerList) {
  EXPECT_EQ(StrCat({"Foo", "Bar", "Quoz"}), "FooBarQuoz");
  EXPECT_EQ(StrCat({"Foo", "Bar"}), "FooBar");
  EXPECT_EQ(StrCat({"Foo"}), "Foo");
  EXPECT_EQ(StrCat({}), "");
}

TEST(StrCatTest, ConcatWithMultipleArgs) {
  EXPECT_EQ(StrCat("Foo", "Bar"), "FooBar");
  EXPECT_EQ(StrCat("Foo", "Bar", "Quoz"), "FooBarQuoz");
}

TEST(ToLowerTest, Basic) {
  EXPECT_EQ(ToLower("FOO"), "foo");
  EXPECT_EQ(ToLower("Foo"), "foo");
  EXPECT_EQ(ToLower("FOO123"), "foo123");
  EXPECT_EQ(ToLower("FOO bar fooBAR123"), "foo bar foobar123");
}

TEST(ContainsTest, Basic) {
  EXPECT_TRUE(Contains("Foo", "F"));
  EXPECT_TRUE(Contains("Foo", "Foo"));
  EXPECT_TRUE(Contains("Foo", ""));
  EXPECT_FALSE(Contains("Foo", "Bar"));
}

}  // namespace
}  // namespace contest_wizard
