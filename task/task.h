#ifndef CONTEST_WIZARD_TASK_TASK_H__
#define CONTEST_WIZARD_TASK_TASK_H__

#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "task/test.h"

namespace contest_wizard {

struct TaskConfig {
  std::string name;
  std::vector<Test> tests;
};

class Task {
 public:
  Task(const TaskConfig& config);
  Task(TaskConfig&& config);

  // Loads task from input stream.
  // Returns nullptr if load fails.
  static std::unique_ptr<Task> Load(std::istream* in);

  // Saves task to output stream.
  void Save(std::ostream* out);

  // Accessor
  const std::string& GetName() const;
  
 private:
  const std::string name_;
  const std::vector<Test> tests_;
};

}  // namespace contest_wizard

#endif  // CONTEST_WIZARD_TASK_TASK_H__
