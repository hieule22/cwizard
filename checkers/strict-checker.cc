// Copyright 2016 Hieu Le.

#include "checkers/strict-checker.h"

namespace contest_wizard {

Verdict StrictChecker::Check(const std::string& input,
                             const std::string& expected_output,
                             const std::string& actual_output) const {
  if (expected_output.empty()) {
    return Verdict(Outcome::kUndecided);
  }
  if (expected_output == actual_output) {
    return Verdict(Outcome::kAccepted);
  }
  return Verdict(Outcome::kRejected);
}

}  // namespace contest_wizard
