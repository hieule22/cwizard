// Representation of a problem task.
// Copyright 2016 Hieu Le.

#ifndef TASK_TASK_H__
#define TASK_TASK_H__

#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "task/test.h"

namespace contest_wizard {

// Information needed to set up a task.
struct TaskConfig {
  // Task name.
  std::string name;
  // Tests associated with this task.
  std::vector<Test> tests;
};

class Task {
 public:
  explicit Task(const TaskConfig& config);
  explicit Task(TaskConfig&& config);

  // Loads task from input stream.
  // Returns nullptr if load fails.
  static std::unique_ptr<Task> Load(std::istream* in);

  // Saves task to output stream.
  void Save(std::ostream* out);

  // Returns the tests associated with this task.
  const std::vector<Test>& GetTests() const;

  // Returns task name.
  const std::string& GetName() const;

 private:
  const std::string name_;
  const std::vector<Test> tests_;
};

}  // namespace contest_wizard

#endif  // TASK_TASK_H__
