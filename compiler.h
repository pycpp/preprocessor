//  :copyright: (c) 2000-2017 Kitware, Inc. and Contributors.
//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: BSD 3-Clause, see licenses/bsd-3.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Compiler detection macros.
 *
 *  Macros to detect the compiler type, version, and the C++ ISO standard
 *  supported by the compiler. To check a given compiler version against
 *  a desired version, use the `COMPILER_VERSION` macro against
 *  `COMPILER_VERSION_CODE`.
 *
 *  The only compilers considered are those with C++11 support,
 *  which may be determined here:
 *      http://en.cppreference.com/w/cpp/compiler_support#C.2B.2B11_features
 *
 *  \synopsis
 *      #define COMPILER_DETECTED           implementation-defined
 *      #define COMPILER_NAME               implementation-defined
 *      #define COMPILER_MAJOR_VERSION      implementation-defined
 *      #define COMPILER_MINOR_VERSION      implementation-defined
 *      #define COMPILER_PATCH_VERSION      implementation-defined
 *      #define COMPILER_VERSION(a, b, c)   implementation-defined
 *      #define COMPILER_VERSION_CODE       implementation-defined
 *      #define HAVE_GNUC                   implementation-defined
 *      #define GNUC_MAJOR_VERSION          implementation-defined
 *      #define GNUC_MINOR_VERSION          implementation-defined
 *      #define GNUC_PATCH_VERSION          implementation-defined
 *      #define HAVE_CLANG                  implementation-defined
 *      #define HAVE_CLANG_2                implementation-defined
 *      #define HAVE_CLANG_3                implementation-defined
 *      #define HAVE_CLANG_4                implementation-defined
 *      #define HAVE_CLANG_5                implementation-defined
 *      #define HAVE_CPP11                  implementation-defined
 *      #define HAVE_CPP14                  implementation-defined
 *      #define HAVE_CPP17                  implementation-defined
 *      #define HAVE_CPP20                  implementation-defined
 *      #define HAVE_GCC                    implementation-defined
 *      #define HAVE_GCC_3                  implementation-defined
 *      #define HAVE_GCC_4                  implementation-defined
 *      #define HAVE_GCC_5                  implementation-defined
 *      #define HAVE_GCC_6                  implementation-defined
 *      #define HAVE_GCC_7                  implementation-defined
 *      #define HAVE_GCC_8                  implementation-defined
 *      #define HAVE_INTEL                  implementation-defined
 *      #define INTEL_MAJOR_VERSION         implementation-defined
 *      #define INTEL_MINOR_VERSION         implementation-defined
 *      #define INTEL_PATCH_VERSION         implementation-defined
 *      #define HAVE_MSVC                   implementation-defined
 *      #define HAVE_MSVC_10                implementation-defined
 *      #define HAVE_MSVC_11                implementation-defined
 *      #define HAVE_MSVC_12                implementation-defined
 *      #define HAVE_MSVC_14                implementation-defined
 *      #define HAVE_MSVC_5                 implementation-defined
 *      #define HAVE_MSVC_6                 implementation-defined
 *      #define HAVE_MSVC_7                 implementation-defined
 *      #define HAVE_MSVC_7                 implementation-defined
 *      #define HAVE_MSVC_8                 implementation-defined
 *      #define HAVE_MSVC_9                 implementation-defined
 *      #define HAVE_SUNPRO                 implementation-defined
 *      #define HAVE_EDG                    implementation-defined
 *      #define HAVE_CRAY                   implementation-defined
 *      #define HAVE_PGI                    implementation-defined
 *      #define HAVE_EMBARCADERO            implementation-defined
 *      #define HAVE_XL                     implementation-defined
 *      #define HAVE_IAR                    implementation-defined
 */

#pragma once

// INTEL
// -----

// Detect presence of one of Intel C++'s optimizing compilers.
#if defined(__INTEL_COMPILER) || defined(__ICC)
// Intel compilers can use different compatibility modes,
// such as GCC, Clang, or Visual Studio compatibility,
// so define the presence of the Intel compiler, but don't
// treat it as a compiler.
#   define HAVE_INTEL 1
    // VERSION = VRP
    // Intel simulates other compilers, use the other compilers
    // version information, but also export Intel C++ compiler
    // version information under `INTEL_*_VERSION`.
#   define INTEL_MAJOR_VERSION __INTEL_COMPILER / 100
#   define INTEL_MINOR_VERSION (__INTEL_COMPILER / 10) % 10
#   if defined(__INTEL_COMPILER_UPDATE)
#       define INTEL_PATCH_VERSION __INTEL_COMPILER_UPDATE
#   else
#       define INTEL_PATCH_VERSION __INTEL_COMPILER % 10
#   endif
#endif

// COMEAU
// ------

// Detect presence of Comeau C++ compiler.
// Currently does not support C++11, disable.
#if !defined(COMPILER_DETECTED) && defined(__COMO__)
#   error "Comeau compiler does not have full C++11 support."
#   define HAVE_COMO 1
#   define COMPILER_DETECTED HAVE_COMO
#   define COMPILER_NAME = "Comeau"
    // VERSION = VRR
#   define COMPILER_MAJOR_VERSION (__COMO_VERSION__ / 100)
#   define COMPILER_MINOR_VERSION (__COMO_VERSION__ % 100)
#   define COMPILER_PATCH_VERSION 0
#endif

// MSVC
// ----

// Detect presence of an MSVC C++ compiler.
#if !defined(COMPILER_DETECTED) && defined(_MSC_VER)
#   define HAVE_MSVC 1
#   define COMPILER_DETECTED HAVE_MSVC
#   define COMPILER_NAME = "MSVC"
#   if _MSC_VER >= 1911
#      define HAVE_MSVC_14 1
#      define COMPILER_MAJOR_VERSION 15
#      define COMPILER_MINOR_VERSION 1
#      define COMPILER_PATCH_VERSION 3
#   elif _MSC_VER == 1910
#      define HAVE_MSVC_14 1
#      define COMPILER_MAJOR_VERSION 14
#      define COMPILER_MINOR_VERSION 1
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1900
#      define HAVE_MSVC_14 1
#      define COMPILER_MAJOR_VERSION 14
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1800
#      define HAVE_MSVC_12 1
#      define COMPILER_MAJOR_VERSION 12
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1700
#      define HAVE_MSVC_11 1
#      define COMPILER_MAJOR_VERSION 11
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1600
#      define HAVE_MSVC_10 1
#      define COMPILER_MAJOR_VERSION 10
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1500
#      define HAVE_MSVC_9 1
#      define COMPILER_MAJOR_VERSION 9
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1400
#      define HAVE_MSVC_8 1
#      define COMPILER_MAJOR_VERSION 8
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1310
#      define HAVE_MSVC_7 1
#      define COMPILER_MAJOR_VERSION 7
#      define COMPILER_MINOR_VERSION 1
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1300
#      define HAVE_MSVC_7 1
#      define COMPILER_MAJOR_VERSION 7
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1200
#      define HAVE_MSVC_6 1
#      define COMPILER_MAJOR_VERSION 6
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1100
#      define HAVE_MSVC_5 1
#      define COMPILER_MAJOR_VERSION 5
#      define COMPILER_MINOR_VERSION 0
#      define COMPILER_PATCH_VERSION 0
#   endif
#endif

// GNUC
// ----

// Detect presence of a compiler using GNU C's preprocessor, which
// should be GCC-like compiler.
#if defined(__GNUC__)
#   define HAVE_GNUC 1
#   define GNUC_MAJOR_VERSION __GNUC__
#   define GNUC_MINOR_VERSION __GNUC_MINOR__
#   if defined(__GNUC_PATCHLEVEL__)
    // Older compilers don't define __GNUC_PATCHLEVEL__
#       define GNUC_PATCH_VERSION __GNUC_PATCHLEVEL__
#   else
#       define GNUC_PATCH_VERSION 0
#   endif
#endif

// SUNPRO
// ------

// Detect presence of Sun/Oracle C++ compiler.
#if !defined(COMPILER_DETECTED) && defined(__SUNPRO_CC)
#   define HAVE_SUNPRO 1
#   define COMPILER_DETECTED HAVE_SUNPRO
#   define COMPILER_NAME "SunPro"
#   if __SUNPRO_CC < 0x590
        // VERSION = 0xVRP
#       define COMPILER_MAJOR_VERSION (__SUNPRO_CC & 0xF00) >> 8
#       define COMPILER_MINOR_VERSION (__SUNPRO_CC & 0x0F0) >> 4
#       define COMPILER_PATCH_VERSION __SUNPRO_CC & 0x00F
#   else
        // VERSION = 0xVRRP
#       define COMPILER_MAJOR_VERSION (__SUNPRO_CC & 0xF000) >> 12
#       define COMPILER_MINOR_VERSION 10*((__SUNPRO_CC & 0x0F00) >> 8) + ((__SUNPRO_CC & 0x00F0) >> 4)
#       define COMPILER_PATCH_VERSION __SUNPRO_CC & 0x000F
#   endif
#endif

// EDG
// ---

// Detect presence of the EDG C++ compiler.
#if !defined(COMPILER_DETECTED) && defined(__EDG__)
#   define HAVE_EDG 1
#   define COMPILER_DETECTED HAVE_EDG
#   define COMPILER_NAME "EDG"
    // VERSION = VRR
#   define COMPILER_MAJOR_VERSION (__EDG_VERSION__ / 100)
#   define COMPILER_MINOR_VERSION (__EDG_VERSION__ % 100)
#   define COMPILER_PATCH_VERSION 0
#endif

// CRAY
// ----

// Detect presence of Cray C compiler.
#if !defined(COMPILER_DETECTED) && defined(_CRAYC)
#   define HAVE_CRAY 1
#   define COMPILER_DETECTED HAVE_CRAY
#   define COMPILER_NAME "Cray"
#   define COMPILER_MAJOR_VERSION _RELEASE_MAJOR
#   define COMPILER_MINOR_VERSION _RELEASE_MINOR
#   define COMPILER_PATCH_VERSION 0
#endif

// PGI
// ---

// Detect presence of the Portland Group C/C++ compiler.
#if !defined(COMPILER_DETECTED) && defined(__PGI)
#   define HAVE_PGI 1
#   define COMPILER_DETECTED HAVE_PGI
#   define COMPILER_NAME "PGI"
#   define COMPILER_MAJOR_VERSION __PGIC__
#   define COMPILER_MINOR_VERSION __PGIC_MINOR__
#   define COMPILER_PATCH_VERSION __PGIC_PATCHLEVEL__
#endif

// FUJITSU
// -------

// Detect presence of Fujitsu C++ compiler.
#if !defined(COMPILER_DETECTED) && (defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version))
#   error "Unknown ISO C++ support for Fujitsu."
#   define HAVE_FUJITSU 1
#   define COMPILER_DETECTED HAVE_FUJITSU
#   define COMPILER_NAME "Fujitsu"
#endif

// SCO
// ---

// Detect presence of the USL C (SCO) C++ compiler.
#if !defined(COMPILER_DETECTED) && (defined(__USLC__) || defined(__SCO_VERSION__))
#   error "Unknown ISO C++ support for USL C++ compiler."
#   define HAVE_SCO 1
#   define COMPILER_DETECTED HAVE_SCO
#   define COMPILER_NAME "SCO"
    // VERSION = VRRYYYYMM
#   define COMPILER_MAJOR_VERSION __SCO_VERSION__ / 100000000
#   define COMPILER_MINOR_VERSION (__SCO_VERSION__ / 1000000) % 100
#   define COMPILER_PATCH_VERSION 0
#endif

// PATHSCALE
// ---------

// Detect presence of PathScale C++ compiler.
#if !defined(COMPILER_DETECTED) && defined(__PATHCC__)
#   error "PathScale compiler does not have full C++11 support."
#   define HAVE_PATHSCALE 1
#   define COMPILER_DETECTED HAVE_PATHSCALE
#   define COMPILER_NAME "PathScale"
#   define COMPILER_MAJOR_VERSION __PATHCC__
#   define COMPILER_MINOR_VERSION __PATHCC_MINOR__
#   if defined(__PATHCC_PATCHLEVEL__)
#       define COMPILER_PATCH_VERSION __PATHCC_PATCHLEVEL__
#   endif
#endif

// EMBARCADERO
// -----------

// Detect the presence of C++ Builder, by Embarcadero Technologies,
// mostly used for Delphi applications.
#if !defined(COMPILER_DETECTED) && (defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__))
#   define HAVE_EMBARCADERO 1
#   define COMPILER_DETECTED HAVE_EMBARCADERO
#   define COMPILER_NAME "Embarcadero"
#   define COMPILER_MAJOR_VERSION ((__CODEGEARC_VERSION__ >> 24) & 0x00FF)
#   define COMPILER_MINOR_VERSION ((__CODEGEARC_VERSION__ >> 16) & 0x00FF)
#   define COMPILER_PATCH_VERSION (__CODEGEARC_VERSION__ & 0xFFFF)
#endif

// BORLAND
// -------

// Detect Borland C++ compiler.
#if !defined(COMPILER_DETECTED) && defined(__BORLANDC__)
#   error "Borland compiler does not have C++11 support."
#   define HAVE_BORLAND 1
#   define COMPILER_DETECTED HAVE_BORLAND
#   define COMPILER_NAME "Borland"
#   define COMPILER_MAJOR_VERSION (__BORLANDC__ >> 8)
#   define COMPILER_MINOR_VERSION (__BORLANDC__ & 0xFF)
#   define COMPILER_PATCH_VERSION 0
#endif

// WATCOM
// ------

// Detect the ancient proprietary Watcom C++ compiler.
#if !defined(COMPILER_DETECTED) && (defined(__WATCOMC__) && __WATCOMC__ < 1200)
#   error "Watcom compiler does not have C++11 support."
#   define HAVE_WATCOM 1
#   define COMPILER_DETECTED HAVE_WATCOM
#   define COMPILER_NAME "Watcom"
#   define COMPILER_MAJOR_VERSION (__WATCOMC__ / 100)
#   define COMPILER_MINOR_VERSION ((__WATCOMC__ / 10) % 10)
#   define COMPILER_PATCH_VERSION (__WATCOMC__ % 10)
#endif

// Detect the open source Watcom C++ compiler (originally known as
// OpenWatcom, now known as Watcom C/C++ compiler).
// OpenWatcom should have C++11 support.
#if !defined(COMPILER_DETECTED) && defined(__WATCOMC__)
#   define HAVE_OPENWATCOM 1
#   define COMPILER_DETECTED HAVE_OPENWATCOM
#   define COMPILER_NAME "OpenWatcom"
    // VERSION = VVRP + 1100
#   define COMPILER_MAJOR_VERSION ((__WATCOMC__ - 1100) / 100)
#   define COMPILER_MINOR_VERSION ((__WATCOMC__ / 10) % 10)
#   define COMPILER_PATCH_VERSION (__WATCOMC__ % 10)
#endif

// HP
// --

#if !defined(COMPILER_DETECTED) && defined(__HP_aCC)
#   error "HP aCC compiler does not have full C++11 support."
#   define HAVE_HP 1
#   define COMPILER_DETECTED HAVE_HP
#   define COMPILER_NAME "HP aCC"
    // VERSION = VVRRPP
#   define COMPILER_MAJOR_VERSION (__HP_aCC/10000)
#   define COMPILER_MINOR_VERSION (__HP_aCC/100 % 100)
#   define COMPILER_PATCH_VERSION (__HP_aCC % 100)
#endif

// COMPAQ
// ------

// Detect presence of Compaq C++ compiler, which stopped support
// before C++11.
#if !defined(COMPILER_DETECTED) && defined(__DECCXX)
#   error "Unknown ISO C++ support for COmpaq."
#   define HAVE_COMPAQ 1
#   define COMPILER_DETECTED HAVE_COMPAQ
#   define COMPILER_NAME "COmpaq"
    // VERSION = VVRRTPPPP
#   define COMPILER_MAJOR_VERSION (__DECCXX_VER / 10000000)
#   define COMPILER_MINOR_VERSION ((__DECCXX_VER / 100000) % 100)
#   define COMPILER_PATCH_VERSION (__DECCXX_VER % 10000)
#endif

// IBCPP
// -----

// Detect presence of z/OS C++ compiler, which dubiously has supported
// C++11 on Linux since 2008. Likely has partial C++11 support
#if !defined(COMPILER_DETECTED) && (defined(__IBMCPP__) && defined(__COMPILER_VER__))
#   define HAVE_ZOS 1
#   define COMPILER_DETECTED HAVE_ZOS
#   define COMPILER_NAME "zOS"
    // VERSION = VRP
#   define COMPILER_MAJOR_VERSION (__IBMCPP__ / 100)
#   define COMPILER_MINOR_VERSION ((__IBMCPP__ / 10) % 10)
#   define COMPILER_PATCH_VERSION (__IBMCPP__ % 10)
#endif

// Detect presence of XL C++ compiler, which supports C++11 on Linux.
#if !defined(COMPILER_DETECTED) && (defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800)
#   define HAVE_XL 1
#   define COMPILER_DETECTED HAVE_XL
#   define COMPILER_NAME "XL"
    // VERSION = VRP
#   define COMPILER_MAJOR_VERSION (__IBMCPP__ / 100)
#   define COMPILER_MINOR_VERSION ((__IBMCPP__ / 10) % 10)
#   define COMPILER_PATCH_VERSION (__IBMCPP__ % 10)
#endif

// Detect presence of VisualAge C++ compiler, which stopped support
// before C++11.
#if !defined(COMPILER_DETECTED) && (defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800)
#   error "Unknown ISO C++ support for VisualAge."
#   define HAVE_VISUALAGE 1
#   define COMPILER_DETECTED HAVE_VISUALAGE
#   define COMPILER_NAME "VisualAge"
    // VERSION = VRP
#   define COMPILER_MAJOR_VERSION (__IBMCPP__ / 100)
#   define COMPILER_MINOR_VERSION ((__IBMCPP__ / 10) % 10)
#   define COMPILER_PATCH_VERSION (__IBMCPP__ % 10)
#endif

// VISUALDSP
// ---------

// Detect presence of VisualDSP compiler, a compiler for Blackfin processors.
// I believe VisualDSP only has C++98 support.
#if !defined(COMPILER_DETECTED) && (defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__))
#   error "Unknown ISO C++ support for ADSP."
#   define HAVE_ADSP 1
#   define COMPILER_DETECTED HAVE_ADSP
#   define COMPILER_NAME "ADSP"
#   if defined(__VISUALDSPVERSION__)
        // VERSION = 0xVVRRPP00
#       define COMPILER_MAJOR_VERSION (__VISUALDSPVERSION__ >> 24)
#       define COMPILER_MINOR_VERSION ((__VISUALDSPVERSION__ >> 16) & 0xFF)
#       define COMPILER_PATCH_VERSION ((__VISUALDSPVERSION__ >> 8) & 0xFF)
#   endif
#endif

// IAR
// ---

// Detect presence of IAR compiler, a C++14-compiler for embedded systems.
#if !defined(COMPILER_DETECTED) && (defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC))
#   define HAVE_IAR 1
#   define COMPILER_DETECTED HAVE_IAR
#   define COMPILER_NAME "IAR"
#   if defined(__VER__)
#       define COMPILER_MAJOR_VERSION ((__VER__) / 1000000)
#       define COMPILER_MINOR_VERSION (((__VER__) / 1000) % 1000)
#       define COMPILER_PATCH_VERSION ((__VER__) % 1000)
#   endif
#endif

// ARMCC
// -----

// Detect presence of ARMCC compiler, a C++03-compiler for embedded systems.
// ARMCC has partial (and improving) C++11 support, add when
// C++11 support is complete.
#if !defined(COMPILER_DETECTED) && defined(__ARMCC_VERSION)
#   error "ARMCC compiler does not have full C++11 support."
#   define HAVE_ARMCC 1
#   define COMPILER_DETECTED HAVE_ARMCC
#   define COMPILER_NAME "ARMCC"
#   if __ARMCC_VERSION >= 1000000
        // VERSION = VRRPPPP
#       define COMPILER_MAJOR_VERSION (__ARMCC_VERSION / 1000000)
#       define COMPILER_MINOR_VERSION ((__ARMCC_VERSION / 10000) % 100)
#       define COMPILER_PATCH_VERSION (__ARMCC_VERSION % 10000)
#   else
        // VERSION = VRPPPP
#       define COMPILER_MAJOR_VERSION (__ARMCC_VERSION / 100000)
#       define COMPILER_MINOR_VERSION ((__ARMCC_VERSION / 10000) % 10)
#       define COMPILER_PATCH_VERSION (__ARMCC_VERSION % 10000)
#   endif
#endif

// MIPSPRO
// -------

// Detect prescence of modern MIPSPro C++ compiler.
#if !defined(COMPILER_DETECTED) && (defined(_SGI_COMPILER_VERSION) || defined(_COMPILER_VERSION))
#   error "Unknown ISO C++ support for MIPSpro."
#   define HAVE_MIPSPRO 1
#   define COMPILER_DETECTED HAVE_MIPSPRO
#   define COMPILER_NAME "MIPSpro"
#   if defined(_SGI_COMPILER_VERSION)
#       define COMPILER_MAJOR_VERSION (_SGI_COMPILER_VERSION / 100)
#       define COMPILER_MINOR_VERSION ((_SGI_COMPILER_VERSION / 10) % 10)
#       define COMPILER_PATCH_VERSION (_SGI_COMPILER_VERSION % 10)
#   else
#       define COMPILER_MAJOR_VERSION (_COMPILER_VERSION / 100)
#       define COMPILER_MINOR_VERSION ((_COMPILER_VERSION / 10) % 10)
#       define COMPILER_PATCH_VERSION (_COMPILER_VERSION % 10)
#   endif
#endif

// Detect presence of ancient version of MIPSpro C++ compiler.
#if !defined(COMPILER_DETECTED) && defined(__sgi)
#   error "Unknown ISO C++ support for MIPSpro."
#   define HAVE_MIPSPRO 1
#   define COMPILER_DETECTED HAVE_MIPSPRO
#   define COMPILER_NAME "MIPSpro"
#endif

// HPUX/HPUA
// ---------

// Detect presence of HP/UX C++ compiler.
#if !defined(COMPILER_DETECTED) && (defined(__hpux) || defined(__hpua))
#   error "Unknown ISO C++ support for HP/UX."
#   define HAVE_HPUX 1
#   define COMPILER_DETECTED HAVE_HPUX
#   define COMPILER_NAME "HP/UX"
#endif

// CLANG
// -----

// Fallback, no other front-ends besides GNU C used for Clang.
// Detect presence of Clang compiler, using any LLVM or GNUC backend.
#if !defined(COMPILER_DETECTED) && defined(__clang__)
#   define HAVE_CLANG 1
#   define COMPILER_DETECTED HAVE_CLANG
#   define COMPILER_MAJOR_VERSION __clang_major__
#   define COMPILER_MINOR_VERSION __clang_minor__
#   define COMPILER_PATCH_VERSION __clang_patchlevel__
#   if COMPILER_MAJOR_VERSION == 5
#      define HAVE_CLANG_5 1
#   elif COMPILER_MAJOR_VERSION == 4
#      define HAVE_CLANG_4 1
#   elif COMPILER_MAJOR_VERSION == 3
#      define HAVE_CLANG_3 1
#   elif COMPILER_MAJOR_VERSION == 2
#      define HAVE_CLANG_2 1
#   endif
#endif

// GCC
// ---

// Fallback, no other GNU-like compilers possible,
// we have GCC.
#if !defined(COMPILER_DETECTED) && defined(HAVE_GNUC)
#   define HAVE_GCC 1
#   define COMPILER_DETECTED HAVE_GCC
#   define COMPILER_NAME "GCC"
#   define COMPILER_MAJOR_VERSION GNUC_MAJOR_VERSION
#   define COMPILER_MINOR_VERSION GNUC_MINOR_VERSION
#   define COMPILER_PATCH_VERSION GNUC_PATCH_VERSION
#   if COMPILER_MAJOR_VERSION == 8
#      define HAVE_GCC_8 1
#   elif COMPILER_MAJOR_VERSION == 7
#      define HAVE_GCC_7 1
#   elif COMPILER_MAJOR_VERSION == 6
#      define HAVE_GCC_6 1
#   elif COMPILER_MAJOR_VERSION == 5
#      define HAVE_GCC_5 1
#   elif COMPILER_MAJOR_VERSION == 4
#      define HAVE_GCC_4 1
#   elif COMPILER_MAJOR_VERSION == 3
#      define HAVE_GCC_3 1
#   endif
#endif

// C++
// ---

#if defined(__cplusplus)
// TODO: C++20 has not yet been standardized, refine when ratified.
#   if __cplusplus >= 202099L
#       define HAVE_CPP20 1
#   endif
#   if __cplusplus >= 201703L
#       define HAVE_CPP17 1
#   endif
#   if __cplusplus >= 201402L
#       define HAVE_CPP14 1
#   endif
#   if __cplusplus >= 201103L
#       define HAVE_CPP11 1
#   endif
#endif

// VERSION
// -------

#define COMPILER_VERSION(major, minor, patch)     \
    ((major << 16) + (minor << 8) + patch)

#define COMPILER_VERSION_CODE                     \
    COMPILER_VERSION(COMPILER_MAJOR_VERSION,      \
                     COMPILER_MINOR_VERSION,      \
                     COMPILER_PATCH_VERSION)
