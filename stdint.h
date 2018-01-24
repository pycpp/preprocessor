//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Compile-time integer width detection.
 *
 *  Detect the processor (system) architecture and memory (maximum size
 *  of a given memory segment) architecture. Also includes macros
 *  to determine if a given type is aligned to a given byte boundary.
 *
 *  \synopsis
 *      #define INT8_WIDTH          implementation-defined
 *      #define INT16_WIDTH         implementation-defined
 *      #define INT32_WIDTH         implementation-defined
 *      #define INT64_WIDTH         implementation-defined
 *      #define UINT8_WIDTH         implementation-defined
 *      #define UINT16_WIDTH        implementation-defined
 *      #define UINT32_WIDTH        implementation-defined
 *      #define UINT64_WIDTH        implementation-defined
 *      #define INT_FAST8_WIDTH     implementation-defined
 *      #define INT_FAST16_WIDTH    implementation-defined
 *      #define INT_FAST32_WIDTH    implementation-defined
 *      #define INT_FAST64_WIDTH    implementation-defined
 *      #define INT_LEAST8_WIDTH    implementation-defined
 *      #define INT_LEAST16_WIDTH   implementation-defined
 *      #define INT_LEAST32_WIDTH   implementation-defined
 *      #define INT_LEAST64_WIDTH   implementation-defined
 *      #define UINT_FAST8_WIDTH    implementation-defined
 *      #define UINT_FAST16_WIDTH   implementation-defined
 *      #define UINT_FAST32_WIDTH   implementation-defined
 *      #define UINT_FAST64_WIDTH   implementation-defined
 *      #define UINT_LEAST8_WIDTH   implementation-defined
 *      #define UINT_LEAST16_WIDTH  implementation-defined
 *      #define UINT_LEAST32_WIDTH  implementation-defined
 *      #define UINT_LEAST64_WIDTH  implementation-defined
 *      #define INTPTR_WIDTH        implementation-defined
 *      #define INTMAX_WIDTH        implementation-defined
 *      #define UINTPTR_WIDTH       implementation-defined
 *      #define UINTMAX_WIDTH       implementation-defined
 */

#pragma once

#include <cstdint>
#include <climits>

// MACROS
// ------

#ifndef INT128_MAX
#   define INT128_MAX 0x7fffffffffffffffffffffffffffffff
#endif

#ifndef UINT128_MAX
#   define UINT128_MAX 0xffffffffffffffffffffffffffffffff
#endif

// INT8_WIDTH
#ifndef INT8_WIDTH
#   define INT8_WIDTH 8
#endif

// INT16_WIDTH
#ifndef INT16_WIDTH
#   define INT16_WIDTH 16
#endif

// INT32_WIDTH
#ifndef INT32_WIDTH
#   define INT32_WIDTH 32
#endif

// INT64_WIDTH
#ifndef INT64_WIDTH
#   define INT64_WIDTH 64
#endif

// UINT8_WIDTH
#ifndef UINT8_WIDTH
#   define UINT8_WIDTH 8
#endif

// UINT16_WIDTH
#ifndef UINT16_WIDTH
#   define UINT16_WIDTH 16
#endif

// UINT32_WIDTH
#ifndef UINT32_WIDTH
#   define UINT32_WIDTH 32
#endif

// UINT64_WIDTH
#ifndef UINT64_WIDTH
#   define UINT64_WIDTH 64
#endif

// INT_FAST8_WIDTH
#ifndef INT_FAST8_WIDTH
#   if INT_FAST8_MAX == INT8_MAX
#       define INT_FAST8_WIDTH 8
#   endif
#endif
#ifndef INT_FAST8_WIDTH
#   if INT_FAST8_MAX == INT16_MAX
#       define INT_FAST8_WIDTH 16
#   endif
#endif
#ifndef INT_FAST8_WIDTH
#   if INT_FAST8_MAX == INT32_MAX
#       define INT_FAST8_WIDTH 32
#   endif
#endif
#ifndef INT_FAST8_WIDTH
#   if INT_FAST8_MAX == INT64_MAX
#       define INT_FAST8_WIDTH 64
#   endif
#endif
#ifndef INT_FAST8_WIDTH
#   if INT_FAST8_MAX == INT128_MAX
#       define INT_FAST8_WIDTH 128
#   endif
#endif
#ifndef INT_FAST8_WIDTH
#   error "INT_FAST8_WIDTH"
#endif

// INT_FAST16_WIDTH
#ifndef INT_FAST16_WIDTH
#   if INT_FAST16_MAX == INT16_MAX
#       define INT_FAST16_WIDTH 16
#   endif
#endif
#ifndef INT_FAST16_WIDTH
#   if INT_FAST16_MAX == INT32_MAX
#       define INT_FAST16_WIDTH 32
#   endif
#endif
#ifndef INT_FAST16_WIDTH
#   if INT_FAST16_MAX == INT64_MAX
#       define INT_FAST16_WIDTH 64
#   endif
#endif
#ifndef INT_FAST16_WIDTH
#   if INT_FAST16_MAX == INT128_MAX
#       define INT_FAST16_WIDTH 128
#   endif
#endif
#ifndef INT_FAST16_WIDTH
#   error "INT_FAST16_WIDTH"
#endif

// INT_FAST32_WIDTH
#ifndef INT_FAST32_WIDTH
#   if INT_FAST32_MAX == INT32_MAX
#       define INT_FAST32_WIDTH 32
#   endif
#endif
#ifndef INT_FAST32_WIDTH
#   if INT_FAST32_MAX == INT64_MAX
#       define INT_FAST32_WIDTH 64
#   endif
#endif
#ifndef INT_FAST32_WIDTH
#   if INT_FAST32_MAX == INT128_MAX
#       define INT_FAST32_WIDTH 128
#   endif
#endif
#ifndef INT_FAST32_WIDTH
#   error "INT_FAST32_WIDTH"
#endif

// INT_FAST64_WIDTH
#ifndef INT_FAST64_WIDTH
#   if INT_FAST64_MAX == INT64_MAX
#       define INT_FAST64_WIDTH 64
#   endif
#endif
#ifndef INT_FAST64_WIDTH
#   if INT_FAST64_MAX == INT128_MAX
#       define INT_FAST64_WIDTH 128
#   endif
#endif
#ifndef INT_FAST64_WIDTH
#   error "INT_FAST64_WIDTH"
#endif

// INT_LEAST8_WIDTH
#ifndef INT_LEAST8_WIDTH
#   if INT_LEAST8_MAX == INT8_MAX
#       define INT_LEAST8_WIDTH 8
#   endif
#endif
#ifndef INT_LEAST8_WIDTH
#   if INT_LEAST8_MAX == INT16_MAX
#       define INT_LEAST8_WIDTH 16
#   endif
#endif
#ifndef INT_LEAST8_WIDTH
#   if INT_LEAST8_MAX == INT32_MAX
#       define INT_LEAST8_WIDTH 32
#   endif
#endif
#ifndef INT_LEAST8_WIDTH
#   if INT_LEAST8_MAX == INT64_MAX
#       define INT_LEAST8_WIDTH 64
#   endif
#endif
#ifndef INT_LEAST8_WIDTH
#   if INT_LEAST8_MAX == INT128_MAX
#       define INT_LEAST8_WIDTH 128
#   endif
#endif
#ifndef INT_LEAST8_WIDTH
#   error "INT_LEAST8_WIDTH"
#endif

// INT_LEAST16_WIDTH
#ifndef INT_LEAST16_WIDTH
#   if INT_LEAST16_MAX == INT16_MAX
#       define INT_LEAST16_WIDTH 16
#   endif
#endif
#ifndef INT_LEAST16_WIDTH
#   if INT_LEAST16_MAX == INT32_MAX
#       define INT_LEAST16_WIDTH 32
#   endif
#endif
#ifndef INT_LEAST16_WIDTH
#   if INT_LEAST16_MAX == INT64_MAX
#       define INT_LEAST16_WIDTH 64
#   endif
#endif
#ifndef INT_LEAST16_WIDTH
#   if INT_LEAST16_MAX == INT128_MAX
#       define INT_LEAST16_WIDTH 128
#   endif
#endif
#ifndef INT_LEAST16_WIDTH
#   error "INT_LEAST16_WIDTH"
#endif

// INT_LEAST32_WIDTH
#ifndef INT_LEAST32_WIDTH
#   if INT_LEAST32_MAX == INT32_MAX
#       define INT_LEAST32_WIDTH 32
#   endif
#endif
#ifndef INT_LEAST32_WIDTH
#   if INT_LEAST32_MAX == INT64_MAX
#       define INT_LEAST32_WIDTH 64
#   endif
#endif
#ifndef INT_LEAST32_WIDTH
#   if INT_LEAST32_MAX == INT128_MAX
#       define INT_LEAST32_WIDTH 128
#   endif
#endif
#ifndef INT_LEAST32_WIDTH
#   error "INT_LEAST32_WIDTH"
#endif

// INT_LEAST64_WIDTH
#ifndef INT_LEAST64_WIDTH
#   if INT_LEAST64_MAX == INT64_MAX
#       define INT_LEAST64_WIDTH 64
#   endif
#endif
#ifndef INT_LEAST64_WIDTH
#   if INT_LEAST64_MAX == INT128_MAX
#       define INT_LEAST64_WIDTH 128
#   endif
#endif
#ifndef INT_LEAST64_WIDTH
#   error "INT_LEAST64_WIDTH"
#endif

// UINT_FAST8_WIDTH
#ifndef UINT_FAST8_WIDTH
#   if UINT_FAST8_MAX == UINT8_MAX
#       define UINT_FAST8_WIDTH 8
#   endif
#endif
#ifndef UINT_FAST8_WIDTH
#   if UINT_FAST8_MAX == UINT16_MAX
#       define UINT_FAST8_WIDTH 16
#   endif
#endif
#ifndef UINT_FAST8_WIDTH
#   if UINT_FAST8_MAX == UINT32_MAX
#       define UINT_FAST8_WIDTH 32
#   endif
#endif
#ifndef UINT_FAST8_WIDTH
#   if UINT_FAST8_MAX == UINT64_MAX
#       define UINT_FAST8_WIDTH 64
#   endif
#endif
#ifndef UINT_FAST8_WIDTH
#   if UINT_FAST8_MAX == UINT128_MAX
#       define UINT_FAST8_WIDTH 128
#   endif
#endif
#ifndef UINT_FAST8_WIDTH
#   error "UINT_FAST8_WIDTH"
#endif

// UINT_FAST16_WIDTH
#ifndef UINT_FAST16_WIDTH
#   if UINT_FAST16_MAX == UINT16_MAX
#       define UINT_FAST16_WIDTH 16
#   endif
#endif
#ifndef UINT_FAST16_WIDTH
#   if UINT_FAST16_MAX == UINT32_MAX
#       define UINT_FAST16_WIDTH 32
#   endif
#endif
#ifndef UINT_FAST16_WIDTH
#   if UINT_FAST16_MAX == UINT64_MAX
#       define UINT_FAST16_WIDTH 64
#   endif
#endif
#ifndef UINT_FAST16_WIDTH
#   if UINT_FAST16_MAX == UINT128_MAX
#       define UINT_FAST16_WIDTH 128
#   endif
#endif
#ifndef UINT_FAST16_WIDTH
#   error "UINT_FAST16_WIDTH"
#endif

// UINT_FAST32_WIDTH
#ifndef UINT_FAST32_WIDTH
#   if UINT_FAST32_MAX == UINT32_MAX
#       define UINT_FAST32_WIDTH 32
#   endif
#endif
#ifndef UINT_FAST32_WIDTH
#   if UINT_FAST32_MAX == UINT64_MAX
#       define UINT_FAST32_WIDTH 64
#   endif
#endif
#ifndef UINT_FAST32_WIDTH
#   if UINT_FAST32_MAX == UINT128_MAX
#       define UINT_FAST32_WIDTH 128
#   endif
#endif
#ifndef UINT_FAST32_WIDTH
#   error "UINT_FAST32_WIDTH"
#endif

// UINT_FAST64_WIDTH
#ifndef UINT_FAST64_WIDTH
#   if UINT_FAST64_MAX == UINT64_MAX
#       define UINT_FAST64_WIDTH 64
#   endif
#endif
#ifndef UINT_FAST64_WIDTH
#   if UINT_FAST64_MAX == UINT128_MAX
#       define UINT_FAST64_WIDTH 128
#   endif
#endif
#ifndef UINT_FAST64_WIDTH
#   error "UINT_FAST64_WIDTH"
#endif

// UINT_LEAST8_WIDTH
#ifndef UINT_LEAST8_WIDTH
#   if UINT_LEAST8_MAX == UINT8_MAX
#       define UINT_LEAST8_WIDTH 8
#   endif
#endif
#ifndef UINT_LEAST8_WIDTH
#   if UINT_LEAST8_MAX == UINT16_MAX
#       define UINT_LEAST8_WIDTH 16
#   endif
#endif
#ifndef UINT_LEAST8_WIDTH
#   if UINT_LEAST8_MAX == UINT32_MAX
#       define UINT_LEAST8_WIDTH 32
#   endif
#endif
#ifndef UINT_LEAST8_WIDTH
#   if UINT_LEAST8_MAX == UINT64_MAX
#       define UINT_LEAST8_WIDTH 64
#   endif
#endif
#ifndef UINT_LEAST8_WIDTH
#   if UINT_LEAST8_MAX == UINT128_MAX
#       define UINT_LEAST8_WIDTH 128
#   endif
#endif
#ifndef UINT_LEAST8_WIDTH
#   error "UINT_LEAST8_WIDTH"
#endif

// UINT_LEAST16_WIDTH
#ifndef UINT_LEAST16_WIDTH
#   if UINT_LEAST16_MAX == UINT16_MAX
#       define UINT_LEAST16_WIDTH 16
#   endif
#endif
#ifndef UINT_LEAST16_WIDTH
#   if UINT_LEAST16_MAX == UINT32_MAX
#       define UINT_LEAST16_WIDTH 32
#   endif
#endif
#ifndef UINT_LEAST16_WIDTH
#   if UINT_LEAST16_MAX == UINT64_MAX
#       define UINT_LEAST16_WIDTH 64
#   endif
#endif
#ifndef UINT_LEAST16_WIDTH
#   if UINT_LEAST16_MAX == UINT128_MAX
#       define UINT_LEAST16_WIDTH 128
#   endif
#endif
#ifndef UINT_LEAST16_WIDTH
#   error "UINT_LEAST16_WIDTH"
#endif

// UINT_LEAST32_WIDTH
#ifndef UINT_LEAST32_WIDTH
#   if UINT_LEAST32_MAX == UINT32_MAX
#       define UINT_LEAST32_WIDTH 32
#   endif
#endif
#ifndef UINT_LEAST32_WIDTH
#   if UINT_LEAST32_MAX == UINT64_MAX
#       define UINT_LEAST32_WIDTH 64
#   endif
#endif
#ifndef UINT_LEAST32_WIDTH
#   if UINT_LEAST32_MAX == UINT128_MAX
#       define UINT_LEAST32_WIDTH 128
#   endif
#endif
#ifndef UINT_LEAST32_WIDTH
#   error "UINT_LEAST32_WIDTH"
#endif

// UINT_LEAST64_WIDTH
#ifndef UINT_LEAST64_WIDTH
#   if UINT_LEAST64_MAX == UINT64_MAX
#       define UINT_LEAST64_WIDTH 64
#   endif
#endif
#ifndef UINT_LEAST64_WIDTH
#   if UINT_LEAST64_MAX == UINT128_MAX
#       define UINT_LEAST64_WIDTH 128
#   endif
#endif
#ifndef UINT_LEAST64_WIDTH
#   error "UINT_LEAST64_WIDTH"
#endif

// INTPTR_WIDTH
#ifndef INTPTR_WIDTH
#   if INTPTR_MAX == INT16_MAX
#       define INTPTR_WIDTH 16
#   endif
#endif
#ifndef INTPTR_WIDTH
#   if INTPTR_MAX == INT32_MAX
#       define INTPTR_WIDTH 32
#   endif
#endif
#ifndef INTPTR_WIDTH
#   if INTPTR_MAX == INT64_MAX
#       define INTPTR_WIDTH 64
#   endif
#endif
#ifndef INTPTR_WIDTH
#   if INTPTR_MAX == INT128_MAX
#       define INTPTR_WIDTH 128
#   endif
#endif
#ifndef INTPTR_WIDTH
#   error "INTPTR_WIDTH"
#endif

// INTMAX_WIDTH
#ifndef INTMAX_WIDTH
#   if INTMAX_MAX == INT64_MAX
#       define INTMAX_WIDTH 64
#   endif
#endif
#ifndef INTMAX_WIDTH
#   if INTMAX_MAX == INT128_MAX
#       define INTMAX_WIDTH 128
#   endif
#endif
#ifndef INTMAX_WIDTH
#   error "INTMAX_WIDTH"
#endif

// UINTPTR_WIDTH
#ifndef UINTPTR_WIDTH
#   if UINTPTR_MAX == UINT16_MAX
#       define UINTPTR_WIDTH 16
#   endif
#endif
#ifndef UINTPTR_WIDTH
#   if UINTPTR_MAX == UINT32_MAX
#       define UINTPTR_WIDTH 32
#   endif
#endif
#ifndef UINTPTR_WIDTH
#   if UINTPTR_MAX == UINT64_MAX
#       define UINTPTR_WIDTH 64
#   endif
#endif
#ifndef UINTPTR_WIDTH
#   if UINTPTR_MAX == UINT128_MAX
#       define UINTPTR_WIDTH 128
#   endif
#endif
#ifndef UINTPTR_WIDTH
#   error "UINTPTR_WIDTH"
#endif

// UINTMAX_WIDTH
#ifndef UINTMAX_WIDTH
#   if UINTMAX_MAX == UINT64_MAX
#       define UINTMAX_WIDTH 64
#   endif
#endif
#ifndef UINTMAX_WIDTH
#   if UINTMAX_MAX == UINT128_MAX
#       define UINTMAX_WIDTH 128
#   endif
#endif
#ifndef UINTMAX_WIDTH
#   error "UINTMAX_WIDTH"
#endif
