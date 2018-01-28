//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Compiler-specific traits.
 *
 *  Contains workarounds for C++11 and C++14 compilers, as well as
 *  compiler versions with partial or incomplete C++11 support.
 *
 *  \synopsis
 *      #define PYCPP_CPP11_PARTIAL_ALLOCATOR_TRAITS    implementation-defined
 *      #define PYCPP_CPP11_PARTIAL_IOS                 implementation-defined
 *      #define PYCPP_CPP11_PARTIAL_TYPE_TRAITS         implementation-defined
 *      #define PYCPP_CPP14_CONSTEXPR                   implementation-defined
 *      #define PYCPP_CPP14_DEPRECATED                  implementation-defined
 *      #define PYCPP_CPP17_CONSTEXPR                   implementation-defined
 *      #define PYCPP_CPP17_FALLTHROUGH                 implementation-defined
 *      #define PYCPP_CPP17_INLINE_VARIABLES            implementation-defined
 *      #define PYCPP_CPP17_NODISCARD                   implementation-defined
 *      #define PYCPP_CPP17_UNUSED                      implementation-defined
 *      #define PYCPP_HAS_INCLUDE(T)                    implementation-defined
 *      #define PYCPP_HAS_BUILTIN(T)                    implementation-defined
 *      #define PYCPP_HAS_EXTENSION(T)                  implementation-defined
 *      #define PYCPP_IS_IDENTIFIER(T)                  implementation-defined
 */

#pragma once

#include <pycpp/preprocessor/compiler.h>

// CONSTEXPR
// ---------

// CPP14 allows non-const constexpr variables.
#if defined(PYCPP_CPP14)    // CPP14
#   define PYCPP_CPP14_CONSTEXPR constexpr
#else                       // !CPP14
#   define PYCPP_CPP14_CONSTEXPR
#endif                      // CPP14

// CPP17 constexpr implies inline.
#if defined(PYCPP_CPP17)    // CPP17
#   define PYCPP_CPP17_CONSTEXPR constexpr
#else                       // !CPP17
#   define PYCPP_CPP17_CONSTEXPR
#endif                      // CPP17

// INLINE
// ------

// CPP17 allows inline variables.
#if defined(PYCPP_CPP17)     // CPP17
#   define PYCPP_CPP17_INLINE_VARIABLES inline
#else                       // !CPP17
#   define PYCPP_CPP17_INLINE_VARIABLES
#endif                      // CPP17

// ATTRIBUTES
// ----------

// CPP14+ attributes.
#if defined(PYCPP_CPP14)                                    // CPP14
#   define PYCPP_CPP14_DEPRECATED [[deprecated]]
#elif defined(PYCPP_GCC) || defined(PYCPP_CLANG)            // PYCPP_GCC | PYCPP_CLANG
#   define PYCPP_CPP14_DEPRECATED __attribute__((deprecated))
#elif defined(PYCPP_MSVC)                                   // PYCPP_MSVC
#   define PYCPP_CPP14_DEPRECATED __declspec(deprecated)
#else                                                       // !CPP14
#   define PYCPP_CPP14_DEPRECATED
#endif                                                      // CPP14

// CPP17+ attributes.
#if defined(PYCPP_CPP17)            // CPP17
#   define PYCPP_CPP17_FALLTHROUGH [[fallthrough]]
#   define PYCPP_CPP17_NODISCARD [[nodiscard]]
#   define PYCPP_CPP17_UNUSED [[maybe_unused]]
#elif defined(PYCPP_GCC)            // PYCPP_GCC
#   define PYCPP_CPP17_FALLTHROUGH __attribute__((fallthrough))
#   define PYCPP_CPP17_NODISCARD __attribute__((warn_unused_result))
#   define PYCPP_CPP17_UNUSED __attribute__((unused))
#elif defined(PYCPP_CLANG)          // PYCPP_CLANG
#   define PYCPP_CPP17_FALLTHROUGH [[clang::fallthrough]]
#   define PYCPP_CPP17_NODISCARD __attribute__((warn_unused_result))
#   define PYCPP_CPP17_UNUSED __attribute__((unused))
#elif defined(PYCPP_MSVC)           // PYCPP_MSVC
#   define PYCPP_CPP17_FALLTHROUGH (void)0
#   define PYCPP_CPP17_NODISCARD _Check_return_
#   define PYCPP_CPP17_UNUSED
#else                               // !CPP17
#   define PYCPP_CPP17_FALLTHROUGH (void)0
#   define PYCPP_CPP17_NODISCARD
#   define PYCPP_CPP17_UNUSED
#endif                              // CPP17

// COMPATABILITY
// -------------

// Define compatibility for partial `allocator_traits` support,
// where most STL types still use allocator methods rather
// than the `allocator_traits` wrapper. GCC did not update
// the STL containers to use `allocator_traits` until
// ~GCC 6.0.0. Clang supports these since before Clang
// 3.0.0, which is well before C++11 support (Clang 3.3).
#if (defined(PYCPP_GCC) && (PYCPP_COMPILER_VERSION_CODE < PYCPP_COMPILER_VERSION(6, 0, 0))) || \
    (defined(PYCPP_CLANG) && PYCPP_COMPILER_VERSION_CODE < PYCPP_COMPILER_VERSION(3, 0, 0))
#   define PYCPP_CPP11_PARTIAL_ALLOCATOR_TRAITS 1
#endif

// Define comaptibility for C++11 compilers with partial <type_traits>
// support. GCC did not support `is_trivially_copyable`,
// `is_trivially_constructible`, `is_trivially_default_constructible`,
// `is_trivially_assignable`, `is_trivially_copy_assignable`,
// and `is_trivially_move_assignable` until GCC 5.0.0. Clang
// implements these in terms of the underlying compiler,
// and has supported wrappers for these methods since before
// Clang 3.0.0, which is well before C++11 support (Clang 3.3).
#if (defined(PYCPP_GCC) && (PYCPP_COMPILER_VERSION_CODE < PYCPP_COMPILER_VERSION(5, 1, 0))) || \
    (defined(PYCPP_CLANG) && PYCPP_COMPILER_VERSION_CODE < PYCPP_COMPILER_VERSION(3, 0, 0))
#   define PYCPP_CPP11_PARTIAL_TYPE_TRAITS 1
#endif

// Define compatibility for C++11 compilers with partial <ios>
// support. GCC did not support `io_errc`, `is_error_code_enum`,
// `iostream_category`, `make_error_code`, `make_error_condition`,
// `hexfloat`, `defaultfloat` until  GCC 5.0.0. Clang supports
// these since before Clang 3.0.0, which is well before C++11
// support (Clang 3.3).
#if (defined(PYCPP_GCC) && (PYCPP_COMPILER_VERSION_CODE < PYCPP_COMPILER_VERSION(5, 1, 0))) || \
    (defined(PYCPP_CLANG) && PYCPP_COMPILER_VERSION_CODE < PYCPP_COMPILER_VERSION(3, 0, 0))
#   define PYCPP_CPP11_PARTIAL_IOS 1
#endif

// HAS FEATURES
// ------------

// Clang supports numerous `__has_xx` features, which are also sometimes
// supported by other compilers (like GCC). However, preprocessor
// operators are not guaranteed to short-circuit, and might error while
// processing statements like `if __has_builtin && __has_builtin(xx)`,
// even is `__has_builtin` is not defined.

#if defined(__has_builtin)
#   define PYCPP_HAS_BUILTIN(x) __has_builtin(x)
#else
#   define PYCPP_HAS_BUILTIN(x) 0
#endif

#if defined(__has_extension)
#   define PYCPP_HAS_EXTENSION(x) __has_extension(x)
#else
#   define PYCPP_HAS_EXTENSION(x) 0
#endif

#if defined(__has_include)
#   define PYCPP_HAS_INCLUDE(x) __has_include(x)
#else
#   define PYCPP_HAS_INCLUDE(x) 0
#endif

#if defined(__is_identifier)
#   define PYCPP_IS_IDENTIFIER(x) __is_identifier(x)
#else
    // Return 1 for the default, since it evaluates to 0 if the worst is
    // a reserved identifier and cannot be used for a variable name.
#   define PYCPP_IS_IDENTIFIER(x) 1
#endif
