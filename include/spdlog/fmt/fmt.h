//
// Copyright(c) 2016-2018 Gabi Melman.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//

#pragma once

//
// Include a bundled header-only copy of fmtlib or an external one.
// By default spdlog include its own copy.
//
#include <spdlog/tweakme.h>

#if defined(SPDLOG_MODULE_BUILD) && !defined(SPDLOG_USE_STD_FORMAT)
// The C++20 module gets fmt from `import fmt;` (see src/spdlog.cppm). Including fmt's
// headers here would attach a second copy of fmt to module spdlog.
//
// An import carries no macros, so the handful of fmt macros the spdlog headers test have
// to be supplied here. FMT_VERSION cannot be read without fmt's headers; a module build
// requires fmt >= 11, so the floor is used, and the version tests below are all for much
// older fmt releases.
#ifndef FMT_VERSION
#define FMT_VERSION 110000
#endif
#ifndef FMT_USE_CONSTEXPR
#define FMT_USE_CONSTEXPR 1
#endif
#ifndef FMT_CONSTEXPR
#define FMT_CONSTEXPR constexpr
#endif
#elif defined(SPDLOG_USE_STD_FORMAT)  // SPDLOG_USE_STD_FORMAT is defined - use std::format
#include <format>
#elif !defined(SPDLOG_FMT_EXTERNAL)
#if !defined(SPDLOG_COMPILED_LIB) && !defined(FMT_HEADER_ONLY)
#define FMT_HEADER_ONLY
#endif
#ifndef FMT_USE_WINDOWS_H
#define FMT_USE_WINDOWS_H 0
#endif
#include <spdlog/fmt/bundled/format.h>
#else  // SPDLOG_FMT_EXTERNAL is defined - use external fmtlib
#include <fmt/format.h>
#endif
