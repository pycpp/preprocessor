//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Detect processor for build.
 *
 *  Detect the processor architecture, such as an ARM, SPARC, or Itanium
 *  processor, using preprocessor macros.
 *
 *  Most of these macros can be found from:
 *      https://sourceforge.net/p/predef/wiki/Architectures/
 *      https://people.csail.mit.edu/jaffer/scm/Automatic-C-Preprocessor-Definitions.html
 *
 *  \synopsis
 *      #define PYCPP_PROCESSOR_DETECTED    implementation-defined
 *      #define PYCPP_ITANIUM               implementation-defined
 *      #define PYCPP_ITANIUM_64            implementation-defined
 *      #define PYCPP_POWERPC               implementation-defined
 *      #define PYCPP_POWERPC_32            implementation-defined
 *      #define PYCPP_POWERPC_64            implementation-defined
 *      #define PYCPP_SPARC                 implementation-defined
 *      #define PYCPP_SPARC_64              implementation-defined
 *      #define PYCPP_SPARC_32              implementation-defined
 *      #define PYCPP_X86                   implementation-defined
 *      #define PYCPP_X86_32                implementation-defined
 *      #define PYCPP_X86_64                implementation-defined
 *      #define PYCPP_ALPHA                 implementation-defined
 *      #define PYCPP_ALPHA_64              implementation-defined
 *      #define PYCPP_ARM                   implementation-defined
 *      #define PYCPP_ARM_V2                implementation-defined
 *      #define PYCPP_ARM_V3                implementation-defined
 *      #define PYCPP_ARM_V4T               implementation-defined
 *      #define PYCPP_ARM_V5                implementation-defined
 *      #define PYCPP_ARM_V5T               implementation-defined
 *      #define PYCPP_ARM_V6                implementation-defined
 *      #define PYCPP_ARM_V6T2              implementation-defined
 *      #define PYCPP_ARM_V7                implementation-defined
 *      #define PYCPP_ARM32                 implementation-defined
 *      #define PYCPP_ARM64                 implementation-defined
 *      #define PYCPP_BLACKFIN              implementation-defined
 *      #define PYCPP_BLACKFIN_32           implementation-defined
 *      #define PYCPP_CONVEX                implementation-defined
 *      #define PYCPP_CONVEX_32             implementation-defined
 *      #define PYCPP_CONVEX_64             implementation-defined
 *      #define PYCPP_EPIPHANY              implementation-defined
 *      #define PYCPP_EPIPHANY_32           implementation-defined
 *      #define PYCPP_EPIPHANY_64           implementation-defined
 *      #define PYCPP_HPPA                  implementation-defined
 *      #define PYCPP_HPPA_32               implementation-defined
 *      #define PYCPP_HPPA_64               implementation-defined
 *      #define PYCPP_68K                   implementation-defined
 *      #define PYCPP_68K_32                implementation-defined
 *      #define PYCPP_MIPS                  implementation-defined
 *      #define PYCPP_MIPS_32               implementation-defined
 *      #define PYCPP_MIPS_64               implementation-defined
 *      #define PYCPP_SUPERH                implementation-defined
 *      #define PYCPP_SUPERH_32             implementation-defined
 *      #define PYCPP_SUPERH_64             implementation-defined
 *      #define PYCPP_SYSTEMZ               implementation-defined
 *      #define PYCPP_SYSTEMZ_32            implementation-defined
 *      #define PYCPP_SYSTEMZ_64            implementation-defined
 *      #define PYCPP_TAHOE                 implementation-defined
 *      #define PYCPP_TAHOE_32              implementation-defined
 *      #define PYCPP_VAX                   implementation-defined
 *      #define PYCPP_VAX_32                implementation-defined
 */

#pragma once

// MACROS
// ------

// ITANIUM
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
#      define PYCPP_ITANIUM
#      define PYCPP_ITANIUM_64
#      define PYCPP_PROCESSOR_DETECTED
#   endif
#endif

// POWERPC
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(ppc) || defined(__powerpc__) || defined(__ppc__) || defined(__PPC__)
#      define PYCPP_POWERPC
#      define PYCPP_PROCESSOR_DETECTED
#       if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(__64BIT__) || defined(_LP64) || defined(__LP64__)
#           define PYCPP_POWERPC_64
#       else
#           define PYCPP_POWERPC_32
#       endif
#   endif
#endif

// SPARC
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__sparc)
#       define PYCPP_SPARC
#       define PYCPP_PROCESSOR_DETECTED
#       if defined(__sparc_v9__) || defined(__sparcv9) || defined(__arch64__)
#          define PYCPP_SPARC_64
#       else
#          define PYCPP_SPARC_32
#       endif
#   endif
#endif


// X86
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__x86_64__) || defined(_M_X64)
#       define PYCPP_X86
#       define PYCPP_X86_64
#       define PYCPP_PROCESSOR_DETECTED
#   elif defined(__i386) || defined(_M_IX86)
#       define PYCPP_X86
#       define PYCPP_X86_32
#       define PYCPP_PROCESSOR_DETECTED
#   endif
#endif

// DEC ALPHA
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
#       define PYCPP_ALPHA
#       define PYCPP_ALPHA_64
#       define PYCPP_PROCESSOR_DETECTED
#   endif
#endif

// ARM
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__arm__) || defined(__thumb__) || defined(__arm) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__aarch64__)
#       define PYCPP_ARM
        // 32-bit or 64-bit
#       if defined(__aarch64__)
#          define PYCPP_ARM64
#       else
#          define PYCPP_ARM32
#       endif
        // ARM version
#       if defined(__ARM_ARCH_2__)
#           define PYCPP_ARM_V2
#       elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
#           define PYCPP_ARM_V3
#       elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
#           define PYCPP_ARM_V4T
#       elif defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5E__)
#           define PYCPP_ARM_V5
#       elif defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) || defined(__ARM_ARCH_5TEJ__)
#           define PYCPP_ARM_V5T
#       elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
#           define PYCPP_ARM_V6
#       elif defined(__ARM_ARCH_6T2__)
#           define PYCPP_ARM_V6T2
#       elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
#           define PYCPP_ARM_V7
#       endif
#       define PYCPP_PROCESSOR_DETECTED
#   endif
#endif

// BLACKFIN
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__bfin) || defined(__BFIN__)
#       define PYCPP_BLACKFIN
#       define PYCPP_BLACKFIN_32
#       define PYCPP_PROCESSOR_DETECTED
#   endif
#endif

// CONVEX
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__bfin) || defined(__BFIN__)
#       define PYCPP_CONVEX
#       define PYCPP_PROCESSOR_DETECTED
#       include <architecture.h>
#       if PYCPP_SYSTEM_ARCHITECTURE == 32
#           define PYCPP_CONVEX_32
#       elif PYCPP_SYSTEM_ARCHITECTURE == 64
#          define PYCPP_CONVEX_64
#       endif
#   endif
#endif

// EPIPHANY
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__epiphany__)
#       define PYCPP_EPIPHANY
#       define PYCPP_PROCESSOR_DETECTED
#       include <architecture.h>
#       if PYCPP_SYSTEM_ARCHITECTURE == 32
#           define PYCPP_EPIPHANY_32
#       elif PYCPP_SYSTEM_ARCHITECTURE == 64
#          define PYCPP_EPIPHANY_64
#       endif
#   endif
#endif

// HPPA RISC
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
#       define PYCPP_HPPA
#       define PYCPP_PROCESSOR_DETECTED
#       include <architecture.h>
#       if PYCPP_SYSTEM_ARCHITECTURE == 32
#           define PYCPP_HPPA_32
#       elif PYCPP_SYSTEM_ARCHITECTURE == 64
#          define PYCPP_HPPA_64
#       endif
#   endif
#endif

// MOTOROLA 68K
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__m68k__) || defined(M68000) || defined(__MC68K__)
#       define PYCPP_68K
#       define PYCPP_68K_32
#       define PYCPP_PROCESSOR_DETECTED
#   endif
#endif

// MIPS
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
#       define PYCPP_MIPS
#       define PYCPP_PROCESSOR_DETECTED
#       include <architecture.h>
#       if PYCPP_SYSTEM_ARCHITECTURE == 32
#           define PYCPP_MIPS_32
#       elif PYCPP_SYSTEM_ARCHITECTURE == 64
#          define PYCPP_MIPS_64
#       endif
#   endif
#endif

// SUPERH
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__sh__)
#       define PYCPP_SUPERH
#       define PYCPP_PROCESSOR_DETECTED
#       if defined(__SH5__)
#           define PYCPP_SUPERH_64
#       else
#           define PYCPP_SUPERH_32
#       endif
#   endif
#endif

// SYSTEMZ
#if !defined (PYCPP_PROCESSOR_DETECTED)
#   if defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#       define PYCPP_SYSTEMZ
#       define PYCPP_PROCESSOR_DETECTED
#       if defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#           define PYCPP_SYSTEMZ_64
#       else
#           define PYCPP_SYSTEMZ_32
#       endif
#   endif
#endif

// TAHOE
#if !defined(PYCPP_PROCESSOR_DETECTED)
#   if defined(tahoe)
#       define PYCPP_TAHOE
#       define PYCPP_TAHOE_32
#       define PYCPP_PROCESSOR_DETECTED
#   endif
#endif

// VAX
#if !defined(PYCPP_PROCESSOR_DETECTED)
#   if defined(__vax__) || defined(vax) || defined(vaxc) || defined(VAXC) || defined(vax11c) || defined(VAX11)
#       define PYCPP_VAX
#       define PYCPP_VAX_32
#       define PYCPP_PROCESSOR_DETECTED
#   endif
#endif
