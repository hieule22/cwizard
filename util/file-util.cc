// Copyright Hieu Le 2016.

#include "util/file-util.h"

#include "boost/filesystem.hpp"
#include "util/string_util.h"

namespace contest_wizard {

bool IsDirectory(const std::string& pathname) {
  boost::filesystem::path path(pathname);
  return boost::filesystem::is_directory(pathname);
}

Status MakeDirectory(const std::string& pathname) {
  boost::filesystem::path path(pathname);
  if (boost::filesystem::create_directories(path)) {
    return Status();
  }
  return Status(error::Code::NOT_FOUND,
                StrCat({"Cannot create directory: ", pathname}));
}

}  // namespace contest_wizard
