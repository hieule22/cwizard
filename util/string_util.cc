// Copyright 2016 Hieu Le.

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

std::string StrCat(const std::string& a0, const std::string& a1) {
  return StrCat({a0, a1});
}

std::string StrCat(const std::string& a0, const std::string& a1,
                   const std::string& a2) {
  return StrCat({a0, a1, a2});
}

std::string ToLower(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

}  // namespace contest_wizard
