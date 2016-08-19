// Checker class that checks if actual output forms an exact match with expected
// output.
// Copyright 2016 Hieu Le.

#ifndef CONTEST_WIZARD_CHECKERS_STRICT_CHECKER_H__
#define CONTEST_WIZARD_CHECKERS_STRICT_CHECKER_H__

#include "checkers/checker.h"

namespace contest_wizard {

class StrictChecker : public Checker {
 public:
  Verdict Check(const std::string& input,
                const std::string& expected_output,
                const std::string& actual_output) override;
};

}  // namespace contest_wizard

#endif  // CONTEST_WIZARD_CHECKERS_STRICT_CHECKER_H__
