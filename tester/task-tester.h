// Contest testing engine.
// Copyright 2016 Hieu Le.

#ifndef TESTER_TASK_TESTER_H__
#define TESTER_TASK_TESTER_H__

#include <memory>
#include <ostream>
#include <string>

#include "checkers/checker.h"
#include "checkers/strict-checker.h"
#include "task/task.h"

namespace contest_wizard {

class TaskTester {
 public:
  TaskTester(const Task& task, std::unique_ptr<Checker> checker =
             std::make_unique<StrictChecker>());

  bool Test(const std::string& result, std::ostream* out) const;

 private:
  const Task task_;
  const std::unique_ptr<Checker> checker_;
};

}  // namespace contest_wizard

#endif  // TESTER_TASK_TESTER_H__
