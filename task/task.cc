// Copyright 2016 Hieu Le.

#include "task/task.h"

#include <utility>

#include "third_party/easyloggingpp/src/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

namespace contest_wizard {

Task::Task(const TaskConfig& config)
    : name_(config.name), tests_(config.tests) {}

Task::Task(TaskConfig&& config)
    : name_(std::move(config.name)), tests_(std::move(config.tests)) {}

std::unique_ptr<Task> Load(std::istream* in) {
  TaskConfig config;
  int test_count;
  *in >> config.name >> test_count;
  config.tests.reserve(test_count);
  for (int i = 0; i < test_count; ++i) {
    std::unique_ptr<Test> test = Test::Load(in);
    CHECK_NOTNULL(test) << "Cannot load test.";
    config.tests.push_back(std::move(*test));
  }
  auto task = std::make_unique<Task>(std::move(config));
  return task;
}

void Task::Save(std::ostream* out) {
  *out << name_ << std::endl;
  *out << tests_.size() << std::endl;
  for (const auto& test : tests_) {
    test.Save(out);
  }
}

const std::vector<Test>& Task::GetTests() const {
  return tests_;
}

const std::string& Task::GetName() const {
  return name_;
}

}  // namespace contest_wizard
