// Checker class that matches expected and actual output to a specified extent
// of absolute and/or relative uncertainty.
// Copyright 2016 Hieu Le.

#ifndef CHECKERS_TOKEN_CHECKER_H__
#define CHECKERS_TOKEN_CHECKER_H__

#include <string>

#include "checkers/checker.h"

namespace contest_wizard {

class TokenChecker : public Checker {
 public:
  // Constructs a checker from the margin with which actual output can deviate
  // from expected output. Enables allow_absolute if the certainty is measured
  // in absolute difference. Enables allow_relative if it is measured in
  // relative difference.
  TokenChecker(double certainty, bool allow_absolute, bool allow_relative);

  // Accepts output if and only if only its numerical tokens are within the
  // certainly level from those of expected output.
  Verdict Check(const std::string& input,
                const std::string& expected_output,
                const std::string& actual_output) const override;

 private:
  double certainty_;
  bool allow_absolute_;
  bool allow_relative_;
};

}  // namespace contest_wizard

#endif  // CHECKERS_TOKEN_CHECKER_H__
