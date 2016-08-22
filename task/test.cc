// Copyright 2016 Hieu Le

#include "task/test.h"

#include <algorithm>
#include <sstream>
#include <utility>

namespace contest_wizard {

Test::Test(const std::string& input, const std::string& output,
           int index, bool active)
    : input_(input), output_(output), index_(index), active_(active) {}

std::string Test::DebugString() const {
  std::string input_rep = input_;
  std::replace(input_rep.begin(), input_rep.end(), '\n', ' ');
  if (input_rep.length() > 15) {
    input_rep = input_rep.substr(0, 12) + "...";
  }
  std::stringstream debug_stream;
  debug_stream << "Test #" << index_ << ": " << input_rep;
  return debug_stream.str();
}

Test Test::SetIndex(int index) {
  return Test(input_, output_, index, active_);
}

Test Test::SetActive(bool active) {
  return Test(input_, output_, index_, active);
}

void Test::Save(std::ostream* out) const {
  *out << index_ << std::endl;
  *out << input_ << std::endl;
  *out << output_ << std::endl;
  *out << active_ << std::endl;
}

std::unique_ptr<Test> Test::Load(std::istream* in) {
  int index;
  std::string input;
  std::string output;
  bool active;
  *in >> index >> input >> output >> active;
  return std::make_unique<Test>(
      std::move(input), std::move(output), index, active);
}

const std::string& Test::GetInput() const {
  return input_;
}

const std::string& Test::GetOutput() const {
  return output_;
}

int Test::GetIndex() const {
  return index_;
}

bool Test::IsActive() const {
  return active_;
}

}  // namespace contest_wizard
