// Representation of a task result.
// Copyright 2016 Hieu Le.

#ifndef CHECKERS_VERDICT_H__
#define CHECKERS_VERDICT_H__

#include <string>

namespace contest_wizard {

// Outcome of a match.
enum class Outcome { kUndecided, kAccepted, kRejected };

class Verdict {
 public:
  // Constructs a verdict from given outcome.
  explicit Verdict(Outcome outcome);

  // Constructs a verdict with given outcome and message.
  Verdict(Outcome outcome, const std::string& message);

  // Returns outcome associated with this verdict.
  Outcome GetOutcome() const;

  // Returns any message associated with this verdict.
  const std::string& GetMessage() const;

 private:
  const Outcome outcome_;
  const std::string message_;
};

}  // namespace contest_wizard

#endif  // CHECKERS_VERDICT_H__
