#include "util/string_util.h"

#include <algorithm>
#include <sstream>

namespace contest_wizard {

std::string StrCat(std::initializer_list<std::string> args) {
  std::ostringstream os;
  for (auto str = args.begin(); str != args.end(); ++str) {
    os << *str;
  }
  return os.str();
}

std::string ToLower(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

}
