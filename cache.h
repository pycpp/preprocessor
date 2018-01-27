//  :copyright: (c) 2014 Google Inc. All Rights Reserved.
//  :copyright: Modified (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief L1 cache line size detection.
 *
 *  Macros to determine the L1 cache line size.
 *  Based on P0154R1.
 *      http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0154r1.html
 *
 *  \synopsis
 *      #define CACHELINE_SIZE          implementation-defined
 *      #define CACHELINE_ALIGNED       implementation-defined
 */

#pragma once

#include <pycpp/preprocessor/processor.h>

// MACROS
// ------

// Cache line alignmentssss
#if defined(PROCESSOR_X86)
#   define CACHELINE_SIZE 64
#elif defined(PROCESSOR_POWERPC64)
#   define CACHELINE_SIZE 128
#elif defined(PROCESSOR_ARM)
// Cache line sizes for ARM: These values are not strictly correct since
// cache line sizes depend on implementations, not architectures.  There
// are even implementations with cache line sizes configurable at boot
// time.
#   if defined(PROCESSOR_ARM_V5T)
#       define CACHELINE_SIZE 32
#   elif defined(PROCESSOR_ARM_V7)
#       define CACHELINE_SIZE 64
#   endif
#endif

#ifndef CACHELINE_SIZE
// A reasonable default guess.  Note that overestimates tend to waste more
// space, while underestimates tend to waste more time.
#   define CACHELINE_SIZE 64
#endif

#ifndef CACHE_ALIGNMENT
// A reasonable default for the cache alignment.
#   define CACHE_ALIGNMENT 64
#endif

#ifndef PREFETCH_STRIDE
// Estimate lookahead size for prefetching.
#   define PREFETCH_STRIDE 4 * CACHELINE_SIZE
#endif

#define CACHELINE_ALIGNED __attribute__((aligned(CACHELINE_SIZE)))
