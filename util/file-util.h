#ifndef CONTEST_WIZARD_FILE_UTIL_H__
#define CONTEST_WIZARD_FILE_UTIL_H__

#include <memory>
#include <istream>
#include <string>

namespace contest_wizard {

// Returns an input stream associated with the input file.
// Returned stream remains property of the factory and will
// be destroyed when the factory is destroyed.
std::istream* GetInputStream(const std::string& file);

}  // namespace contest_wizard

#endif  // CONTEST_WIZARD_FILE_UTIL_H__
