package(default_visibility = ["//visibility:public"])

cc_library(
  name = "status",
  srcs = ["status.cc"],
  hdrs = ["status.h"],
)

cc_test(
  name = "status_test",
  srcs = ["status_test.cc"],
  deps = [
       ":status",
       "//third_party/gtest:gtest_main"
  ],
)

cc_library(
  name = "string_util",
  srcs = ["string_util.cc"],
  hdrs = ["string_util.h"],
)

cc_test(
  name = "string_util_test",
  srcs = ["string_util_test.cc"],
  size = "small",
  deps  = [
  	"//third_party/gtest:gtest_main",
        ":string_util",
  ],	
)

cc_library(
  name = "file-util",
  srcs = ["file-util.cc"],
  hdrs = ["file-util.h"],
  deps = [
       ":status",
       ":string_util",
       "//task:task",
       "//third_party/boost:filesystem"
  ],
)

cc_test(
  name = "file-util_test",
  srcs = ["file-util_test.cc"],
  deps = [
       ":file-util",
       "//third_party/gtest:gtest_main",
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