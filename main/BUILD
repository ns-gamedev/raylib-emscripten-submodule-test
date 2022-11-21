load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")
load("@rules_pkg//:pkg.bzl", "pkg_zip")

cc_library(
    name = "archcore-lib",
    srcs = ["entry.cc"],
    deps = ["//raylib:libraylib-wasm"],
    copts = ["-Iraylib/raylib/src"],
)

cc_binary(
    name = "archcore-bin",
    visibility = ["//archcore:__pkg__"],  
    deps = [":archcore-lib"],
    linkopts = [ "-s USE_GLFW=3" , "-sASYNCIFY" , "-sEXPORTED_FUNCTIONS=_set_size,_main", "-sEXPORTED_RUNTIME_METHODS=ccall,cwrap", "-sALLOW_MEMORY_GROWTH"]

)