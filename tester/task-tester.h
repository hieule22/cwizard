// Testing engine for an individual task.
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
  // Constructs a tester from an input task and optional checker.
  // If unspecified, checker is defaulted to a strict checker.
  TaskTester(const Task& task, std::unique_ptr<Checker> checker =
             std::make_unique<StrictChecker>());

  // Tests an input string and logs to an output stream.
  bool Test(const std::string& result, std::ostream* out) const;

 private:
  const Task task_;
  const std::unique_ptr<Checker> checker_;
};

}  // namespace contest_wizard

#endif  // TESTER_TASK_TESTER_H__
