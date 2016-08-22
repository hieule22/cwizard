// Utility functions to manipulate strings.
// Copyright 2016 Hieu Le.

#ifndef UTIL_STRING_UTIL_H__
#define UTIL_STRING_UTIL_H__

#include <initializer_list>
#include <string>

namespace contest_wizard {

// Returns the concatenation of an initializer list of strings.
std::string StrCat(std::initializer_list<std::string> args);

// Returns the concatenation of two strings.
std::string StrCat(const std::string& a0, const std::string& a1);

// Returns the concatenation of three strings.
std::string StrCat(const std::string& a0, const std::string& a1,
                   const std::string& a2);

// Converts an input string into its lowercase equivalent.
std::string ToLower(std::string str);

}  // namespace contest_wizard

#endif  // UTIL_STRING_UTIL_H__
