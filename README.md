# Preprocessor

**Table of Contents**

- [Introduction](#introduction)
- [ABI](#abi)
- [Architecture](#architecture)
- [Byte Order](#byte-order)
- [Cache](#cache)
- [Compiler](#compiler)
- [Compiler Traits](#compiler-traits)
- [Operating System](#operating-system)
- [Parallel](#parallel)
- [Processor](#processor)
- [Thread Local Storage](#thread-local-storage)

## Introduction

PyCPP builds upon a platform abstraction library for cross-compiler support, which depends upon the C preprocessor for platform-specific configurations. PyCPP extends these macros to define useful traits for the library user: macros for cross-compiler thread-local storage, parallel execution, C++ standard support and workarounds, and macros to detect the system operating system, byteorder, and processor/architecture.

## ABI

Macros to detect the C++ ABI. Defines the macro `HAVE_CXXABI` if the compiler has `cxxabi.h`, and uses the Itanium ABI.

## Architecture

Macros to determine the processor and memory architecture. `SYSTEM_ARCHITECTURE` is defined as `sizeof(uintptr_t)` in bits (16, 32, 64, etc.), or the size of a pointer sufficient to convert to and from a void pointer on the system. `MEMORY_ARCHITECTURE` is defined as `sizeof(size_t)` in bits (16, 32, 64, etc.), or the number of bits required to represent an object's size in a single memory segment. In segmented x86 memory models, such as the Intel 8086, these are not necessarily identical: the size of a pointer may be larger than the maximum object size.

Architecture also defines 4 macros to detect type alignment to a memory boundary: `IS_ALIGNED_16`, `IS_ALIGNED_32`, `IS_ALIGNED_64`, and `IS_ALIGNED_128`.

## Byte Order

Byte-order contains preprocessor macros and functions to detect and convert to and from the host byte-order. PyCPP defines `BYTE_ORDER` to either `LITTLE_ENDIAN` or `BIG_ENDIAN`, and add cross-platform function-like macros similar to Linux's `<endian.h>` definitions. See [byteorder.h](/byteorder.h) for more details.

## Cache

Cache attempts to determine the L1 cache line size, and writes the size to `CACHELINE_SIZE`. It also defines another macro, `CACHELINE_ALIGNED`, which aligns a variable to the cache size alignment.

## Compiler

Defines macros to simplify detection of the C++ ISO standard supported (`HAVE_CPP17`, etc.) and the compiler used (`HAVE_MSVC`, `HAVE_GCC`, etc.). See [compiler.h](/compiler.h) for more details.

## Compiler Traits

Defines workarounds for partial C++ standards support by known compilers, and workarounds for C++11 and C++14 compilers. See [compiler_traits.h](/compiler_traits.h) for more details.

## Operating System

If the operating system is successfully detected, defines `OS_DETECTED` and a macro for the operating system type. For example, if Linux is detected, PyCPP defines `OS_LINUX` and `OS_DETECTED`. On select platforms, such as macOS, macros for the operating system version (`OS_VERSION_MAJOR`, `OS_VERSION_MINOR`, and `OS_VERSION_PATCH`) are also defined. These macros therefore simplify designing platform-specific not covered by PyCPP. For the complete list of potential operating system defines, see [os.h](/os.h).

## Parallel

Parallel  execution polices for STL algorithms when supported by the compiler. Parallel defines 3 macros, `SEQUENTIAL_EXECUTION`,  `PARALLEL_EXECUTION`, and `PARALLEL_UNSEQUENCED_EXECUTION`, which expand to the desired execution policy if supported by the compiler. The following example use a parallel sort if supported by the compiler; otherwise, it uses a sequential sort:

```cpp
#include <algorithm>
#include <vector>
#include <pycpp/preprocessor/parallel.h>

int main()
{
    std::vector<int> v = {5, 6, 3, 7, 8, 2, 9};
    std::sort(PARALLEL_EXECUTION v.begin(), v.end());
    return 0;
}
```

## Processor

If the processor type is successfully detected, defines `PROCESSOR_DETECTED` and a macro for the processor type. For example, if a 32-bit ARM processor is detected, PyCPP defines `PROCESSOR_ARM32`, `PROCESSOR_ARM`, and `PROCESSOR_DETECTED`. For the complete list of potential processor defines, see [processor.h](/processor.h).

## Thread Local Storage

Various C++11-compatible compilers, including Clang on macOS, do not yet support the C++ keyword `thread_local`. PyCPP uses compiler intrinsics to create a keyword-like macro, `thread_local_storage`, that behaves identically to the C++11 keyword.
