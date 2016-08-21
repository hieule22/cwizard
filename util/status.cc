// Copyright 2016 Hieu le.

#include "util/status.h"

namespace contest_wizard {

Status::Status() : code_(error::Code::OK) {}

Status::Status(error::Code code, const std::string& message)
    : code_(code), message_(message) {}

bool Status::ok() const {
  return code_ == error::Code::OK;
}

const std::string& Status::error_message() const {
  return message_;
}

}  // namespace contest_wizard
