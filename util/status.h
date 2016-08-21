// Mechanism to report status or error from function call.
// Copyright 2016 Hieu Le.

#ifndef UTIL_STATUS_H__
#define UTIL_STATUS_H__

#include <string>

namespace contest_wizard {
namespace error {

// Error codes
enum class Code {
  OK = 0,
  CANCELLED = 1,
  UNKNOWN = 2,
  INVALID_ARGUMENT = 3,
  DEADLINE_EXCEEDED = 4,
    NOT_FOUND = 5,
};

}  // namespace error

class Status {
 public:
  // Constructs a default OK status.
  Status();

  // Constructs a status with the given code and message.
  Status(error::Code code, const std::string& message);

  // Determines if status is ok.
  bool ok() const;

  // Get explanation bound at construction.
  const std::string& error_message() const;

 private:
  error::Code code_;
  std::string message_;
};
}  // namespace contest_wizard

#endif  // UTIL_STATUS_H__
