// Interface to check the output of a task.
// Copyright 2016 Hieu Le.

#ifndef CONTEST_WIZARD_CHECKERS_CHECKER_H__
#define CONTEST_WIZARD_CHECKERS_CHECKER_H__

#include <string>

namespace contest_wizard {

// Result of a match.
enum class Verdict { kUndecided, kAccepted, kRejected };

// Base interface.
class Checker {
 public:
  virtual ~Checker() {}

  virtual Verdict Check(const std::string& input,
                        const std::string& expected_output,
                        const std::string& actual_output) = 0;
};

}  // namespace contest_wizard

#endif  // CONTEST_WIZARD_CHECKERS_CHECKER_H__
