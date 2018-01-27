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
 *      #define HAVE_CXXABI                 implementation-defined
 *      #define CXXABI_DETECTED             implementation-defined
 *      #define CXXABI_VERSION(a, b, c)     implementation-defined
 *      #define CXXABI_VERSION_CODE         implementation-defined
 *      #define CXXABI_MAJOR_VERSION        implementation-defined
 *      #define CXXABI_MINOR_VERSION        implementation-defined
 *      #define CXXABI_PATCH_VERSION        implementation-defined
 *      #define HAVE_GLIBCXX                implementation-defined
 *      #define HAVE_LIBCXX                 implementation-defined
 *      #define HAVE_CXXABI_MICROSOFT       implementation-defined
 *      #define HAVE_CXXABI_ITANIUM         implementation-defined
 */

#pragma once

#include <pycpp/preprocessor/compiler_traits.h>
#include <pycpp/preprocessor/os.h>

// HAVE_CXXABI
// ------------

// Have <cxxabi.h> header for macros.
#if defined(HAVE_CLANG)
#   if HAS_INCLUDE(<cxxabi.h>)
#       define HAVE_CXXABI 1
#   endif
#elif defined(__GLIBCXX__) || defined(__GLIBCPP__)
#   define HAVE_CXXABI 1
#endif

// HAVE_GLIBCXX
// ------------

// Have libstdc++ ABI.
#if defined(__GLIBCXX__)
#   define HAVE_GLIBCXX 1
#   define HAVE_CXXABI_ITANIUM 1
#   define CXXABI_DETECTED HAVE_GLIBCXX
    // The version is defined by _GLIBCXX_RELEASE, when present,
    // and is the same as __GNUC__. Old macros with different
    // versioning schemes existed in GCC 3.x, and are not used.
    // Those macros include `__GLIBCPP__`, `_GLIBCPP_VERSION`,
    // and `_GLIBCXX_VERSION`.
#   if defined(_GLIBCXX_RELEASE)
#       define CXXABI_MAJOR_VERSION _GLIBCXX_RELEASE
#   else
#       define CXXABI_MAJOR_VERSION __GNUC__
#   endif
#   define CXXABI_MINOR_VERSION 0
#   define CXXABI_PATCH_VERSION 0
#endif

// HAVE_CXXABI_MICROSOFT
// ---------------------

// Detect Windows ABI
#if !defined(CXXABI_DETECTED) && defined(OS_WINDOWS)
#   define HAVE_CXXABI_MICROSOFT 1
#   define CXXABI_DETECTED HAVE_CXXABI_MICROSOFT
    // We're using the C ABI, so lie.
    // The C ABI is compatible between all major C++ releases.
#   define CXXABI_MAJOR_VERSION 1
#   define CXXABI_MINOR_VERSION 0
#   define CXXABI_PATCH_VERSION 0
#endif

// HAVE_LIBCXX
// -----------

// Have libc++ ABI. Clang defines _LIBCPP_VERSION for any include,
// and may include more than one actual ABI, so use this as a fallback.
#if !defined(CXXABI_DETECTED) && defined(_LIBCPP_VERSION)
#   define HAVE_LIBCXX 1
#   define HAVE_CXXABI_ITANIUM 1
#   define CXXABI_DETECTED HAVE_LIBCXX
#   define CXXABI_MAJOR_VERSION _LIBCPP_ABI_VERSION
#   define CXXABI_MINOR_VERSION 0
#   define CXXABI_PATCH_VERSION 0
// libc++ uses an internal ABI version for exception handling.
// Documemnt it for internal use.
#   define CXXABI_INTERNAL_VERSION _LIBCPPABI_VERSION
#endif

// VERSION
// -------

#define CXXABI_VERSION(major, minor, patch)     \
    ((major << 16) + (minor << 8) + patch)

#define CXXABI_VERSION_CODE                     \
    CXXABI_VERSION(CXXABI_MAJOR_VERSION,        \
                   CXXABI_MINOR_VERSION,        \
                   CXXABI_PATCH_VERSION)
