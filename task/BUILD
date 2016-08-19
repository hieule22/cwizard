package(default_visibility = ["//visibility:public"])

cc_library(
  name = "test",
  srcs = ["test.cc"],
  hdrs = ["test.h"],
  deps = [],
  copts = ["--std=c++14"],
)

cc_test(
  name = "test_test",
  srcs = ["test_test.cc"],
  size = "small",
  deps = [
       ":test",
       "//third_party/gtest:gtest_main",
  ],	
)

cc_library(
  name = "task",
  srcs = ["task.cc"],
  hdrs = ["task.h"],
  deps = [
       "//third_party/easyloggingpp:easyloggingpp",
       ":test",
  ],
  copts = [
  	"-std=c++14",
  	"-lstdc++",
  ],
)

cc_test(
  name = "task_test",
  srcs = ["task_test.cc"],
  size = "small",
  deps = [
       "//third_party/gtest:gtest_main",
       ":task",
  ],	
)