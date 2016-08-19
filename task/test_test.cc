#include "task/test.h"

#include <sstream>

#include "gtest/gtest.h"

namespace {

TEST(TestTest, Accessor) {
  ::contest_wizard::Test test("Foo", "Bar", 12345);
  EXPECT_EQ(test.GetInput(), "Foo");
  EXPECT_EQ(test.GetOutput(), "Bar");
  EXPECT_EQ(test.GetIndex(), 12345);
}

TEST(TestTest, DebugString) {
  ::contest_wizard::Test test("Foo", "", 12345);
  EXPECT_EQ(test.DebugString(), "Test #12345: Foo");

  ::contest_wizard::Test test_with_newline("Foo\nBar", "", 12345);
  EXPECT_EQ(test_with_newline.DebugString(), "Test #12345: Foo Bar");

  ::contest_wizard::Test test_with_long_input(
      "qwertyuiopasdfgh", "", 12345);
  EXPECT_EQ(test_with_long_input.DebugString(),
            "Test #12345: qwertyuiopas...");
}

TEST(TestTest, Save) {
  ::contest_wizard::Test test("Foo", "Bar", 12345);
  std::stringstream out;
  test.Save(&out);
  EXPECT_EQ(out.str(), "12345\nFoo\nBar");
}

TEST(TestTest, Load) {
  std::stringstream in;
  in.str("1 Foo Bar");
  auto test = ::contest_wizard::Test::Load(&in);
  ASSERT_TRUE(test != nullptr);
  EXPECT_EQ(test->GetInput(), "Foo");
  EXPECT_EQ(test->GetOutput(), "Bar");
  EXPECT_EQ(test->GetIndex(), 1);
}

}  // namespace
