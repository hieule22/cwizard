#include "task/test.h"

#include <algorithm>
#include <sstream>

namespace contest_wizard {

Test::Test(const std::string& input, const std::string& output, int index)
    : input_(input), output_(output), index_(index) {}

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

void Test::Save(std::ostream* out) const {
  *out << index_ << std::endl << input_ << std::endl << output_;
}

std::unique_ptr<Test> Test::Load(std::istream* in) {
  int index;
  std::string input;
  std::string output;
  *in >> index >> input >> output;
  return std::make_unique<Test>(std::move(input), std::move(output), index);
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

}  // namespace contest_wizard
