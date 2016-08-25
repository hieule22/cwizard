package(default_visibility = ["//visibility:public"])

cc_library(
  name = "task-tester",
  srcs = ["task-tester.cc"],
  hdrs = ["task-tester.h"],
  copts = ["-std=c++14"],
  deps = [
       "//checkers:checker",
       "//checkers:strict-checker",
       "//task:task",
       "//third_party/easyloggingpp:easyloggingpp",
  ],
)