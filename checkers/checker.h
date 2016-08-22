// Interface to check the output of a task.
// Copyright 2016 Hieu Le.

#ifndef CHECKERS_CHECKER_H__
#define CHECKERS_CHECKER_H__

#include <string>

#include "checkers/verdict.h"

namespace contest_wizard {

// Base interface. Concrete implementation should derive Check() function.
class Checker {
 public:
  virtual ~Checker() {}

  // Returns verdict by comparing actual with expected output.
  virtual Verdict Check(const std::string& input,
                        const std::string& expected_output,
                        const std::string& actual_output) const = 0;
};

}  // namespace contest_wizard

#endif  // CHECKERS_CHECKER_H__
