load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")
load("@rules_pkg//:pkg.bzl", "pkg_zip")

cc_binary(
    name = "entry-point",
    srcs = ["entry.cc"],
    deps = ["//raylib:libraylib-wasm"],
    copts = ["-Iraylib/raylib/src"],
    linkopts = [ "-s USE_GLFW=3" , "-sASYNCIFY" ]
)

wasm_cc_binary(
    name = "entry-point-wasm",
    cc_target = ":entry-point",
    outputs = [
        "entry-point.js",
        "entry-point.wasm"
    ],
)

pkg_zip(
    name = "package-game",
    srcs = [":entry-point-wasm",
            "index.html"]
)