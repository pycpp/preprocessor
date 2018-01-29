//  :copyright: (c) 2012 Petroules Corporation.
//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PySTD
 *  \brief System architecture detection macros.
 *
 *  Detect the processor (system) architecture and memory (maximum size
 *  of a given memory segment) architecture. Also includes macros
 *  to determine if a given type is aligned to a given byte boundary.
 *
 *  \synopsis
 *      #define PYCPP_SYSTEM_ARCHITECTURE   implementation-defined
 *      #define PYCPP_MEMORY_ARCHITECTURE   implementation-defined
 *      #define PYCPP_IS_ALIGNED_16(p)      implementation-defined
 *      #define PYCPP_IS_ALIGNED_32(p)      implementation-defined
 *      #define PYCPP_IS_ALIGNED_64(p)      implementation-defined
 *      #define PYCPP_IS_ALIGNED_128(p)     implementation-defined
 */

#pragma once

#include <cstdint>
#include <climits>

// WINDOWS
// -------

#if _WIN32 || _WIN64
#   if _WIN128
#       define PYCPP_SYSTEM_ARCHITECTURE 128
#   elif _WIN64
#       define PYCPP_SYSTEM_ARCHITECTURE 64
#   elif _WIN32
#       define PYCPP_SYSTEM_ARCHITECTURE 32
#   elif _WIN16
#       define PYCPP_SYSTEM_ARCHITECTURE 16
#   endif
#endif

// GCC
// ---

#if __GNUC__
#   if defined(__x86_64__) || defined(__ppc64__) || defined(__amd64__) || defined(__LP64__) || defined(_M_X64) || defined(__ia64) || defined(_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
#       define PYCPP_SYSTEM_ARCHITECTURE 64
#   elif defined(__i386__) || defined(_M_IX86) || defined(_M_PPC) || defined(__LP32__) || defined(__POWERPC__)
#       define PYCPP_SYSTEM_ARCHITECTURE 32
#   else
#       define PYCPP_SYSTEM_ARCHITECTURE 32
#   endif
#endif

// OTHER
// -----

#ifndef INT128_MAX
#   define INT128_MAX 0x7fffffffffffffffffffffffffffffff
#endif

#ifndef UINT128_MAX
#   define UINT128_MAX 0xffffffffffffffffffffffffffffffff
#endif

// Use uintptr_t rather than size_t, since we might be on a segmented
// architecture. Go smallest-to-largest, since we don't want
// to check values too large for type.
#ifndef PYCPP_SYSTEM_ARCHITECTURE
#   if UINTPTR_MAX == UINT16_MAX
#       define PYCPP_SYSTEM_ARCHITECTURE 16
#   endif
#endif
#ifndef PYCPP_SYSTEM_ARCHITECTURE
#   if UINTPTR_MAX == UINT32_MAX
#       define PYCPP_SYSTEM_ARCHITECTURE 32
#   endif
#endif
#ifndef PYCPP_SYSTEM_ARCHITECTURE
#   if UINTPTR_MAX == UINT64_MAX
#       define PYCPP_SYSTEM_ARCHITECTURE 64
#   endif
#endif
#ifndef PYCPP_SYSTEM_ARCHITECTURE
#   if UINTPTR_MAX == UINT128_MAX
#       define PYCPP_SYSTEM_ARCHITECTURE 128
#   endif
#endif
#ifndef PYCPP_SYSTEM_ARCHITECTURE
#   error "Unknown system architecture."
#endif

// MEMORY ARCHITECTURE
// -------------------

// We may be using multiple memory segments, so `sizeof(size_t) <
// sizeof(uintptr_t)`. For example, a 16-bit integer may the max
// object size, but there may be multiple 16-bit memory segments,
// requiring 32-bit pointers. Go smallest-to-largest, since we don't
// want to check values too large for type.
#ifndef PYCPP_MEMORY_ARCHITECTURE
#   if SIZE_MAX == UINT16_MAX
#       define PYCPP_MEMORY_ARCHITECTURE 16
#   endif
#endif
#ifndef PYCPP_MEMORY_ARCHITECTURE
#   if SIZE_MAX == UINT32_MAX
#       define PYCPP_MEMORY_ARCHITECTURE 32
#   endif
#endif
#ifndef PYCPP_MEMORY_ARCHITECTURE
#   if SIZE_MAX == UINT64_MAX
#       define PYCPP_MEMORY_ARCHITECTURE 64
#   endif
#endif
#ifndef PYCPP_MEMORY_ARCHITECTURE
#   if SIZE_MAX == UINT128_MAX
#       define PYCPP_MEMORY_ARCHITECTURE 128
#   endif
#endif
#ifndef PYCPP_MEMORY_ARCHITECTURE
#   error "Unknown memory architecture."
#endif

// ALIGNMENT
// ---------

// Detect if a given pointer is aligned to a certain
// memory boundary. For example, `PYCPP_IS_ALIGNED_16` will
// check if a type is aligned on a 16-bit boundary.
// Any type that is aligned to a stricter boundary
// (for example, 128 bits) will automatically be
// aligned to weaker boundaries (for example, 32
// or 64 bits).
#define PYCPP_IS_ALIGNED_16(p)    (0 == (((uintptr_t) p) & 1))
#define PYCPP_IS_ALIGNED_32(p)    (0 == (((uintptr_t) p) & 3))
#define PYCPP_IS_ALIGNED_64(p)    (0 == (((uintptr_t) p) & 7))
#define PYCPP_IS_ALIGNED_128(p)   (0 == (((uintptr_t) p) & 15))
