// Checker class that checks if actual output forms an exact match with expected
// output.
// Copyright 2016 Hieu Le.

#ifndef CHECKERS_STRICT_CHECKER_H__
#define CHECKERS_STRICT_CHECKER_H__

#include "checkers/checker.h"

namespace contest_wizard {

class StrictChecker : public Checker {
 public:
  // Accepts output if and only if it exactly matches expected output.
  Verdict Check(const std::string& input,
                const std::string& expected_output,
                const std::string& actual_output) override;
};

}  // namespace contest_wizard

#endif  // CHECKERS_STRICT_CHECKER_H__
