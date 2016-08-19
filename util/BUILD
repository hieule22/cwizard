package(default_visibility = ["//visibility:public"])

cc_library(
  name = "string_util",
  srcs = ["string_util.cc"],
  hdrs = ["string_util.h"],
  deps = ["//third_party/boost:filesystem"],
)

cc_test(
  name = "string_util_test",
  srcs = ["string_util_test.cc"],
  deps  = [
  	"//third_party/gtest:gtest_main",
        ":string_util",
  ],	
)