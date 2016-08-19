// Class representation of a single test case.

#ifndef CONTEST_WIZARD_TASK_TEST_H__
#define CONTEST_WIZARD_TASK_TEST_H__

#include <iostream>
#include <memory>
#include <string>

namespace contest_wizard {

class Test {
 public:
  explicit Test(const std::string& input, const std::string& output = "",
                int index = -1);

  // Returns a human-friendly representation of the test instance.
  std::string DebugString() const;

  // Saves test to output stream.
  void Save(std::ostream* out) const;

  // Loads test from input stream.
  static std::unique_ptr<Test> Load(std::istream* in);

  // Accessors
  const std::string& GetInput() const;
  const std::string& GetOutput() const;
  int GetIndex() const;

 private:
  const std::string input_;
  const std::string output_;
  const int index_;
};

}  // namespace contest_wizard

#endif  // CONTEST_WIZARD_TASK_TEST_H__
