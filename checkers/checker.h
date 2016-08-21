// Interface to check the output of a task.
// Copyright 2016 Hieu Le.

#ifndef CHECKERS_CHECKER_H__
#define CHECKERS_CHECKER_H__

#include <string>

namespace contest_wizard {

// Result of a match.
enum class Verdict { kUndecided, kAccepted, kRejected };

// Base interface. Concrete implementation should derive Check() function.
class Checker {
 public:
  virtual ~Checker() {}

  // Returns verdict by comparing actual with expected output.
  virtual Verdict Check(const std::string& input,
                        const std::string& expected_output,
                        const std::string& actual_output) = 0;
};

}  // namespace contest_wizard

#endif  // CHECKERS_CHECKER_H__
