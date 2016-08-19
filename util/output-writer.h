#ifndef CONTEST_WIZARD_UTIL_OUTPUT_WRITER_H__
#define CONTEST_WIZARD_UTIL_OUTPUT_WRITER_H__

#include <memory>
#include <ostream>

namespace contest_wizard {

class OutputWriter {
 public:
  OutputWriter(std::unique_ptr<std::ostream> out);

  
 private:
  const std::unique_ptr<std::ostream> out_stream_;
};

}  // namespace contest_wizard

#endif  // CONTEST_WIZARD_UTIL_OUTPUT_WRITER_H__
