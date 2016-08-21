// Utility classes and functions to access, query and manipulate files and
// directories.
// Copyright 2016 Hieu Le.

#ifndef UTIL_FILE_UTIL_H__
#define UTIL_FILE_UTIL_H__

#include <memory>
#include <string>

#include "task/task.h"
#include "util/status.h"

namespace contest_wizard {

// Checks if the entity referenced by given pathname exists and is a directory.
bool IsDirectory(const std::string& pathname);

// Creates a directory referenced by given pathname.
Status MakeDirectory(const std::string& pathname);

bool WriteTextFile(const std::string& filename, const std::string& content);

std::string ReadTextFile(const std::string& filename);

std::unique_ptr<Task> ReadTask(const std::string& filename);

}  // namespace contest_wizard

#endif  // UTIL_FILE_UTIL_H__
