// Class representation of a single test case.
// Test case is characterized by its input, output, index and active setting.
// Copyright 2016 Hieu Le.

#ifndef TASK_TEST_H__
#define TASK_TEST_H__

#include <iostream>
#include <memory>
#include <string>

namespace contest_wizard {

class Test {
 public:
  // Constructs a test from its parameters.
  // Input is required while other attributes are optional.
  explicit Test(const std::string& input, const std::string& output = "",
                int index = -1, bool active = true);

  // Returns a human-friendly representation of this instance.
  // Returned value is of the form "Test #$index: $input". Input exceeding 15
  // characters will be truncated and prefixed with "...".
  std::string DebugString() const;

  // Returns a test constructed from this instance but with a different index.
  Test SetIndex(int index);

  // Returns a test constructed from this instance but with a different active
  // setting.
  Test SetActive(bool active);

  // Saves test to output stream.
  void Save(std::ostream* out) const;

  // Loads test from input stream. Returns nullptr if test cannot be loaded.
  static std::unique_ptr<Test> Load(std::istream* in);

  // Returns input and output associated with this instance.
  // Returned values are destroyed when test is destroyed.
  const std::string& GetInput() const;
  const std::string& GetOutput() const;

  // Returns index and active setting associated with this instance.
  int GetIndex() const;
  bool IsActive() const;

 private:
  const std::string input_;
  const std::string output_;
  const int index_;
  const bool active_;
};

}  // namespace contest_wizard

#endif  // TASK_TEST_H__
