load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "emsdk",
    sha256 = "67d68f4ed47aa0b97ab4d40b70a55f068455bb6e5821c6b04c7d6089b6495d20",
    strip_prefix = "emsdk-e41b8c68a248da5f18ebd03bd0420953945d52ff/bazel",
    urls = ["https://github.com/emscripten-core/emsdk/archive/e41b8c68a248da5f18ebd03bd0420953945d52ff.tar.gz"],
)

http_archive(
    name = "rules_pkg",
    url = "https://github.com/bazelbuild/rules_pkg/releases/download/0.3.0/rules_pkg-0.3.0.tar.gz",
    sha256 = "6b5969a7acd7b60c02f816773b06fcf32fbe8ba0c7919ccdc2df4f8fb923804a",
)

load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")
rules_pkg_dependencies()

load("@emsdk//:deps.bzl", emsdk_deps = "deps")
emsdk_deps()

load("@emsdk//:emscripten_deps.bzl", emsdk_emscripten_deps = "emscripten_deps")
emsdk_emscripten_deps(emscripten_version = "3.1.24")