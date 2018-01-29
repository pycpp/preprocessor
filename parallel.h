//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PySTD
 *  \brief Parallel STL detection and execution macros.
 *
 *  Conditional parallel execution policy tags for compilers with C++17
 *  support. These macros will use the desired execution policy on C++17
 *  support, or fall-back to the standard overload for C++11 or C++14
 *  compilers.
 *
 *  \code
 *      #include <algorithm>
 *      #include <vector>
 *      #include <pycpp/preprocessor/parallel.h>
 *
 *      int main()
 *      {
 *          std::vector<int> v = {5, 6, 3, 7, 8, 2, 9};
 *          std::sort(PARALLEL_EXECUTION v.begin(), v.end());
 *          return 0;
 *      }
 *
 *  \synopsis
 *      #define SEQUENTIAL_EXECUTION            implementation-defined
 *      #define PARALLEL_EXECUTION              implementation-defined
 *      #define PARALLEL_UNSEQUENCED_EXECUTION  implementation-defined
 */

#pragma once

#include <pycpp/config.h>
#include <pycpp/preprocessor/compiler_traits.h>
#if defined(HAVE_CPP17)
// TODO(ahuszagh): Wish list.
// None of the STL implements have implemented the parallel execution
// algorithms.
// Annotate when `execution_policy` becomes available.
#   if PYCPP_HAS_INCLUDE(<execution>)
#       define PYCPP_HAVE_EXECUTION 1
#       include <execution>
#   endif
#endif

// MACROS
// ------

#if defined(PYCPP_HAVE_EXECUTION)
#   define SEQUENTIAL_EXECUTION std::execution::seq,
#   define PARALLEL_EXECUTION std::execution::par,
#   define PARALLEL_UNSEQUENCED_EXECUTION std::execution::par_unseq,
#else
#   define SEQUENTIAL_EXECUTION
#   define PARALLEL_EXECUTION
#   define PARALLEL_UNSEQUENCED_EXECUTION
#endif
