#include "util/output-writer.h"

#include <memory>
#include <sstream>

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(OutputWriterTest, PrintLine) {
  std::stringstream buffer;
  std::unique_ptr<std::ostream> out =
      std::make_unique<std::ostream>(buffer.rdbuf());
  OutputWriter writer(std::move(out));
  writer.PrintLine(1);
  EXPECT_EQ(buffer.str(), "1\n");
}

TEST(OutputWriterTest, PrintString) {
  std::stringstream buffer;
  std::unique_ptr<std::ostream> out =
      std::make_unique<std::ostream>(buffer.rdbuf());
  OutputWriter writer(std::move(out));
  writer.PrintString("foo");
  EXPECT_EQ(buffer.str(), "foo\n");
}

TEST(OutputWriterTest, PrintBoolTrue) {
  std::stringstream buffer;
  std::unique_ptr<std::ostream> out =
      std::make_unique<std::ostream>(buffer.rdbuf());
  OutputWriter writer(std::move(out));
  writer.PrintBool(true);
  EXPECT_EQ(buffer.str(), "1\n");
}

TEST(OutputWriterTest, PrintBoolFalse) {
  std::stringstream buffer;
  std::unique_ptr<std::ostream> out =
      std::make_unique<std::ostream>(buffer.rdbuf());
  OutputWriter writer(std::move(out));
  writer.PrintBool(false);
  EXPECT_EQ(buffer.str(), "0\n");
}

}
}  // namespace contest_wizard
