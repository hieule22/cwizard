// Wrapper class for an output stream.

#ifndef CONTEST_WIZARD_UTIL_OUTPUT_WRITER_H__
#define CONTEST_WIZARD_UTIL_OUTPUT_WRITER_H__

#include <memory>
#include <ostream>
#include <string>

namespace contest_wizard {

class OutputWriter {
 public:
  OutputWriter(std::unique_ptr<std::ostream> out);

  template <typename T>
  void PrintLine(const T& val);

  void PrintString(const std::string& val);

  void PrintBool(bool val);

  void Flush();
  
 private:
  const std::unique_ptr<std::ostream> out_stream_;
};

}  // namespace contest_wizard

#endif  // CONTEST_WIZARD_UTIL_OUTPUT_WRITER_H__
