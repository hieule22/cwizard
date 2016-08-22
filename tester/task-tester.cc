// Copyright 2016 Hieu Le.

#include "tester/task-tester.h"

#include <utility>
#include <vector>

namespace contest_wizard {
namespace {

const char kSmallSeparator[] = "-------------------------";
const char kBigSeparator[] = "=========================";

}  // namespace

TaskTester::TaskTester(const Task& task, std::unique_ptr<Checker> checker)
    : task_(task), checker_(std::move(checker)) {}

bool TaskTester::Test(const std::string& result,
                      std::ostream* out_stream) const {
  std::ostream& out = *out_stream;
  out << "Task: " << task_.GetName() << std::endl;
  out << kSmallSeparator << std::endl;
  bool ok = true;
  std::vector<Verdict> verdicts;

  for (const auto& test : task_.GetTests()) {
    if (!test.IsActive()) {
      out << "Test #" << test.GetIndex() << ": SKIPPED" << std::endl;
      out << kSmallSeparator << std::endl;
      continue;
    }
    out << "Test #" << test.GetIndex() << ":" << std::endl;
    out << "Input:" << std::endl << test.GetInput() << std::endl;
    out << "Expected output:" << std::endl << test.GetOutput() << std::endl;
    out << "Execution result:" << std::endl << result << std::endl;
    Verdict verdict =
        checker_->Check(test.GetInput(), test.GetOutput(), result);
    if (verdict.GetOutcome() != Outcome::kAccepted ||
        verdict.GetOutcome() != Outcome::kUndecided) {
      ok = false;
    }
    verdicts.emplace_back(std::move(verdict));
    out << kSmallSeparator << std::endl;
  }
  out << kBigSeparator << std::endl;
  if (ok) {
    out << "All test passed input." << std::endl;
  } else {
    for (int i = 0; i < verdicts.size(); ++i) {
      out << "Test #" << i << ": " << verdicts[i].GetMessage();
    }
  }
  return ok;
}

}  // namespace contest_wizard
