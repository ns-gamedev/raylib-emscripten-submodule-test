load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")
load("@rules_pkg//:pkg.bzl", "pkg_zip")

cc_binary(
    name = "archcore-bin",
    srcs = ["entry.cc"],
    deps = ["//raylib:libraylib-wasm"],
    copts = ["-Iraylib/raylib/src"],
    linkopts = [ "-s USE_GLFW=3" , "-sASYNCIFY" , "-sEXPORTED_FUNCTIONS=_set_size,_main", "-sEXPORTED_RUNTIME_METHODS=ccall,cwrap"]
)

wasm_cc_binary(
    name = "archcore-wasm",
    cc_target = ":archcore-bin",
    outputs = [
        "archcore.js",
        "archcore.wasm"
    ],
)

filegroup(
    name = "game-files",
    srcs = [":archcore-wasm",
            "index.html"]
)

pkg_zip(
    name = "package-game",
    srcs = [":game-files"]
)

genrule(
    name = "server",
    srcs = [":game-files"],
    outs = ["out/a"],
    cmd_ps = "echo $(SRCS) >> $(@D)/a ; $$files = Get-Content -Path $(@D)/a; foreach( $$file in $$files) { Copy-Item $$file -Destination $(@D) } "
)