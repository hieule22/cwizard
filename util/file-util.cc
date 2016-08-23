// Copyright Hieu Le 2016.

#include "util/file-util.h"

#include <fstream>
#include <streambuf>

#include "boost/filesystem.hpp"
#include "third_party/easyloggingpp/src/easylogging++.h"
#include "util/string_util.h"

INITIALIZE_EASYLOGGINGPP

namespace contest_wizard {

bool IsDirectory(const std::string& pathname) {
  boost::filesystem::path path(pathname);
  return boost::filesystem::is_directory(path);
}

bool IsFile(const std::string& pathname) {
  boost::filesystem::path path(pathname);
  return boost::filesystem::is_regular_file(path);
}

Status MakeDirectory(const std::string& pathname) {
  boost::filesystem::path path(pathname);
  if (boost::filesystem::create_directories(path)) {
    return Status();
  }
  return Status(error::Code::NOT_FOUND,
                StrCat("Cannot create directory: ", pathname));
}

Status WriteTextFile(const std::string& pathname, const std::string& content) {
  if (!IsFile(pathname)) {
    return Status(error::Code::NOT_FOUND,
                  StrCat("Text file not found: ", pathname));
  }
  std::ofstream output(pathname);
  output << content;
  return Status();
}

Status ReadTextFile(const std::string& pathname, std::string* result) {
  if (!IsFile(pathname)) {
    return Status(error::Code::NOT_FOUND,
                  StrCat("Text file not found: ", pathname));
  }
  if (result == nullptr) {
    return Status(error::Code::INVALID_ARGUMENT,
                  "Result has not been initialized.");
  }

  std::ifstream input(pathname);
  // Allocates all the memory up front rather than relying on string class'
  // automatic reallocation.
  input.seekg(0, std::ios::end);
  result->reserve(input.tellg());
  input.seekg(0, std::ios::beg);

  result->assign((std::istreambuf_iterator<char>(input)),
                 std::istreambuf_iterator<char>());
  return Status();
}

}  // namespace contest_wizard
