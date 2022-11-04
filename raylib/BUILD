load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "libraylib-wasm",
    deps = [ ":raylib-internals-wasm",
             ":raylib-internals-opengl-wasm"],      
    visibility = ["//main:__pkg__"],
)

cc_library(
    name = "raylib-internals-wasm",
    srcs = ["raylib/src/raudio.c",
            "raylib/src/utils.c"],
    hdrs = glob(["raylib/src/*.h"]) + glob(["raylib/src/external/*.h"]),
    copts = ["-Iraylib/raylib/src/external/.", "-Os -DPLATFORM_WEB", "-Wno-unused-function"],
)

cc_library(
    name = "raylib-internals-opengl-wasm",
    srcs = ["raylib/src/rcore.c",
            "raylib/src/rshapes.c",
            "raylib/src/rtextures.c",
            "raylib/src/rtext.c",
            "raylib/src/rmodels.c"],
    hdrs = glob(["raylib/src/*.h"]) + glob(["raylib/src/external/*.h"]),
    copts = ["-Iraylib/raylib/src/external/.", "-Os -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2", "-Wno-unused-function"],
)