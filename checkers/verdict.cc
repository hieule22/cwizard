// Copyright 2016 Hieu Le.

#include "checkers/verdict.h"

namespace contest_wizard {

Verdict::Verdict(Outcome outcome) : Verdict(outcome, "") {}

Verdict::Verdict(Outcome outcome, const std::string& message)
    : outcome_(outcome), message_(message) {}

Outcome Verdict::GetOutcome() const {
  return outcome_;
}

const std::string& Verdict::GetMessage() const {
  return message_;
}

}  // namespace contest_wizard
