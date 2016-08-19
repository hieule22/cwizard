// Copyright 2016 Hieu Le.

#include "checkers/strict-checker.h"

namespace contest_wizard {

Verdict StrictChecker::Check(const std::string& input,
                             const std::string& expected_output,
                             const std::string& actual_output) {
  if (expected_output.empty()) {
    return Verdict::kUndecided;
  }
  if (expected_output == actual_output) {
    return Verdict::kAccepted;
  }
  return Verdict::kRejected;
}

}  // namespace contest_wizard
