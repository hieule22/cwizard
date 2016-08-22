// Copyright 2016 Hieu Le.

#include "checkers/token-checker.h"

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <sstream>

#include "third_party/easyloggingpp/src/easylogging++.h"
#include "util/string_util.h"

INITIALIZE_EASYLOGGINGPP

namespace contest_wizard {

// Utility functions
namespace {

bool IsExhausted(const std::ios& stream) {
  return stream.eof();
}

std::string ReadToken(std::istream* stream) {
  CHECK_NOTNULL(stream) << "Stream has not been initialized.";
  std::string token;
  *stream >> token;
  return token;
}

bool ParseDouble(const std::string& token, double* value) {
  CHECK_NOTNULL(value) << "Value has not been initialized.";
  std::stringstream stream(token);
  return !(stream >> *value).fail();
}

}  // namespace

TokenChecker::TokenChecker(double certainty, bool allow_absolute,
                           bool allow_relative)
    : certainty_(certainty), allow_absolute_(allow_absolute),
      allow_relative_(allow_relative) {}

Verdict TokenChecker::Check(const std::string& input,
                            const std::string& expected_output,
                            const std::string& actual_output) const {
  if (expected_output.empty()) {
    return Verdict(Outcome::kUndecided);
  }

  std::stringstream expected(expected_output);
  std::stringstream actual(actual_output);
  int token_count = -1;
  double max_delta = 0;

  while (!IsExhausted(expected) && !IsExhausted(actual)) {
    ++token_count;
    std::string expected_token = ReadToken(&expected);
    std::string actual_token = ReadToken(&actual);
    if (expected_token != actual_token) {
      if (allow_absolute_ || allow_relative_) {
        double expected_value;
        double actual_value;
        if (ParseDouble(expected_token, &expected_value) &&
            ParseDouble(actual_token, &actual_value)) {
          double absolute_diff = std::abs(expected_value - actual_value);
          double relative_diff = absolute_diff /
              (expected_value == 0 ? 1 : std::abs(expected_value));

          double diff = DBL_MAX;
          if (allow_absolute_) {
            diff = std::min(diff, absolute_diff);
          }
          if (allow_relative_) {
            diff = std::min(diff, relative_diff);
          }

          max_delta = std::max(max_delta, diff);
          if (diff <= certainty_) {
            continue;
          }
        }
      }
      return Verdict(Outcome::kRejected, StrCat(
          "Difference in token #", std::to_string(token_count), "."));
    }
  }

  if (IsExhausted(expected) && IsExhausted(actual)) {
    if (allow_absolute_ || allow_relative_) {
      return Verdict(Outcome::kAccepted, StrCat(
          "Maximal delta is ", std::to_string(max_delta), "."));
    }
    return Verdict(Outcome::kAccepted);
  }

  if (IsExhausted(expected)) {
    return Verdict(Outcome::kRejected, StrCat(
        "Only ", std::to_string(token_count), " token expected."));
  }

  return Verdict(Outcome::kRejected, StrCat(
      "More than ", std::to_string(token_count), " tokens expected."));
}

}  // namespace contest_wizard
