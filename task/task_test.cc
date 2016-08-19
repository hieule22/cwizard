#include "task/task.h"

#include <sstream>

#include "gtest/gtest.h"

namespace contest_wizard {
namespace {

TEST(TaskTest, ConstructWithTaskConfig) {
  TaskConfig config;
  config.name = "Foo";
  Task task(config);
  EXPECT_EQ(task.GetName(), "Foo");
}

TEST(TaskTest, LoadAndSave) {
  std::stringstream stream;
  {
    ::contest_wizard::Test test("Foo", "Bar", 0);
    TaskConfig config;
    config.name = "Quoz";
    config.tests.emplace_back(std::move(test));
    Task task(std::move(config));
    task.Save(&stream);
    std::cout << stream.str() << std::endl;
  }
  EXPECT_TRUE(true);
  {
    auto task = Task::Load(&stream);
    ASSERT_TRUE(task != nullptr);
    EXPECT_EQ(task->GetName(), "Quoz");
  }
}

}  // namespace
}  // namespace contest_wizard
