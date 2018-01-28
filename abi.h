//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief C++ ABI detection macros.
 *
 *  Most compilers will use Itanium's C++ ABI, or Windows's ABI.
 *  However, other compilers, including SUNPRO, VisualAge, and HP's
 *  aCC compiler on PA-RISC use other ABIs. This attempts to simplify
 *  ABI detection, however, since many compilers not using Itanium or
 *  the Windows ABI do not support C++11, we are unlikely to encounter
 *  them.
 *
 *  \synopsis
 *      #define PYCPP_CXXABI                    implementation-defined
 *      #define PYCPP_CXXABI_DETECTED           implementation-defined
 *      #define PYCPP_CXXABI_VERSION(a, b, c)   implementation-defined
 *      #define PYCPP_CXXABI_VERSION_CODE       implementation-defined
 *      #define PYCPP_CXXABI_MAJOR_VERSION      implementation-defined
 *      #define PYCPP_CXXABI_MINOR_VERSION      implementation-defined
 *      #define PYCPP_CXXABI_PATCH_VERSION      implementation-defined
 *      #define PYCPP_GLIBCXX                   implementation-defined
 *      #define PYCPP_LIBCXX                    implementation-defined
 *      #define PYCPP_CXXABI_MICROSOFT          implementation-defined
 *      #define PYCPP_CXXABI_ITANIUM            implementation-defined
 */

#pragma once

#include <pycpp/preprocessor/compiler_traits.h>
#include <pycpp/preprocessor/os.h>

// PYCPP_CXXABI
// ------------

// Have <cxxabi.h> header for macros.
#if defined(PYCPP_CLANG)
#   if PYCPP_HAS_INCLUDE(<cxxabi.h>)
#       define PYCPP_CXXABI 1
#   endif
#elif defined(__GLIBCXX__) || defined(__GLIBCPP__)
#   define PYCPP_CXXABI 1
#endif

// PYCPP_GLIBCXX
// ------------

// Have libstdc++ ABI.
#if defined(__GLIBCXX__)
#   define PYCPP_GLIBCXX 1
#   define PYCPP_CXXABI_ITANIUM 1
#   define PYCPP_CXXABI_DETECTED PYCPP_GLIBCXX
    // The version is defined by _GLIBCXX_RELEASE, when present,
    // and is the same as __GNUC__. Old macros with different
    // versioning schemes existed in GCC 3.x, and are not used.
    // Those macros include `__GLIBCPP__`, `_GLIBCPP_VERSION`,
    // and `_GLIBCXX_VERSION`.
#   if defined(_GLIBCXX_RELEASE)
#       define PYCPP_CXXABI_MAJOR_VERSION _GLIBCXX_RELEASE
#   else
#       define PYCPP_CXXABI_MAJOR_VERSION __GNUC__
#   endif
#   define PYCPP_CXXABI_MINOR_VERSION 0
#   define PYCPP_CXXABI_PATCH_VERSION 0
#endif

// PYCPP_CXXABI_MICROSOFT
// ---------------------

// Detect Windows ABI
#if !defined(PYCPP_CXXABI_DETECTED) && defined(PYCPP_WINDOWS)
#   define PYCPP_CXXABI_MICROSOFT 1
#   define PYCPP_CXXABI_DETECTED PYCPP_CXXABI_MICROSOFT
    // We're using the C ABI, so lie.
    // The C ABI is compatible between all major C++ releases.
#   define PYCPP_CXXABI_MAJOR_VERSION 1
#   define PYCPP_CXXABI_MINOR_VERSION 0
#   define PYCPP_CXXABI_PATCH_VERSION 0
#endif

// PYCPP_LIBCXX
// -----------

// Have libc++ ABI. Clang defines _LIBCPP_VERSION for any include,
// and may include more than one actual ABI, so use this as a fallback.
#if !defined(PYCPP_CXXABI_DETECTED) && defined(_LIBCPP_VERSION)
#   define PYCPP_LIBCXX 1
#   define PYCPP_CXXABI_ITANIUM 1
#   define PYCPP_CXXABI_DETECTED PYCPP_LIBCXX
#   define PYCPP_CXXABI_MAJOR_VERSION _LIBCPP_ABI_VERSION
#   define PYCPP_CXXABI_MINOR_VERSION 0
#   define PYCPP_CXXABI_PATCH_VERSION 0
// libc++ uses an internal ABI version for exception handling.
// Documemnt it for internal use.
#   define CXXABI_INTERNAL_VERSION _LIBCPPABI_VERSION
#endif

// VERSION
// -------

#define PYCPP_CXXABI_VERSION(major, minor, patch)     \
    ((major << 16) + (minor << 8) + patch)

#define PYCPP_CXXABI_VERSION_CODE                     \
    PYCPP_CXXABI_VERSION(PYCPP_CXXABI_MAJOR_VERSION,        \
                   PYCPP_CXXABI_MINOR_VERSION,        \
                   PYCPP_CXXABI_PATCH_VERSION)
