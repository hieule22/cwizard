#include "util/output-writer.h"

namespace contest_wizard {

OutputWriter::OutputWriter(std::unique_ptr<std::ostream> out)
    : out_stream_(std::move(out)) {}

template <typename T>
void OutputWriter::PrintLine(const T& val) {
  *out_stream_ << val << std::endl;
}

void OutputWriter::PrintString(const std::string& val) {
  *out_stream_ << val << std::endl;
}

void OutputWriter::PrintBool(bool val) {
  *out_stream_ << val << std::endl;
}

void OutputWriter::Flush() {
  out_stream_->flush();
}

}  // namespace contest_wizard
