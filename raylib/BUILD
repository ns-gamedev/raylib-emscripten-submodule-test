load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "libraylib-wasm",
    deps = [ ":raylib-internals-wasm",
             ":raylib-internals-opengl-wasm"],      
    visibility = ["//main:__pkg__"],
)

RAYLIB_WARNINGS_TO_IGNORE = [
    "-Wno-unused-function",
    "-Wno-implicit-const-int-float-conversion",
    "-Wno-unused-but-set-variable",
    "-Wno-unknown-warning-option"]

cc_library(
    name = "raylib-internals-wasm",
    srcs = ["raylib/src/raudio.c",
            "raylib/src/utils.c"],
    hdrs = glob(["raylib/src/*.h"]) + glob(["raylib/src/external/*.h"]),
    copts = ["-Os -DPLATFORM_WEB"] + RAYLIB_WARNINGS_TO_IGNORE,
)

cc_library(
    name = "raylib-internals-opengl-wasm",
    srcs = ["raylib/src/rcore.c",
            "raylib/src/rshapes.c",
            "raylib/src/rtextures.c",
            "raylib/src/rtext.c",
            "raylib/src/rmodels.c"],
    hdrs = glob(["raylib/src/*.h"]) + glob(["raylib/src/external/*.h"]),
    copts = ["-Os -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2"] + RAYLIB_WARNINGS_TO_IGNORE,
)