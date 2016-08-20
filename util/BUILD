package(default_visibility = ["//visibility:public"])

cc_library(
  name = "string_util",
  srcs = ["string_util.cc"],
  hdrs = ["string_util.h"],
)

cc_test(
  name = "string_util_test",
  srcs = ["string_util_test.cc"],
  deps  = [
  	"//third_party/gtest:gtest_main",
        ":string_util",
  ],	
)

cc_library(
  name = "output-writer",
  srcs = ["output-writer.cc"],
  hdrs = ["output-writer.h"],
)

cc_test(
  name = "output-writer_test",
  srcs = ["output-writer_test.cc"],
  copts = ["-std=c++14"],
  deps = [
       ":output-writer",
       "//third_party/gtest:gtest_main",
  ],
)