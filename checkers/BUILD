package(default_visibility = ["//visibility:public"])

cc_library(
  name = "checker",
  hdrs = ["checker.h"],
)

cc_library(
  name = "strict-checker",
  srcs = ["strict-checker.cc"],
  hdrs = ["strict-checker.h"],
  deps = [":checker"],
)

cc_test(
  name = "strict-checker_test",
  srcs = ["strict-checker_test.cc"],
  size = "small",
  copts = ["--std=c++14"],
  deps = [
       ":strict-checker",
       "//third_party/gtest:gtest_main",
  ],
)

cc_library(
  name = "token-checker",
  srcs = ["token-checker.cc"],
  hdrs = ["token-checker.h"],
  deps = [
       ":checker",
       "//third_party/easyloggingpp:easyloggingpp",
  ],
)

cc_test(
  name = "token-checker_test",
  srcs = ["token-checker_test.cc"],
  copts = ["--std=c++14"],
  deps = [
       ":token-checker",
       "//third_party/gtest:gtest_main",
  ],
)