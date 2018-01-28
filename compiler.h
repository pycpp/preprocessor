//  :copyright: (c) 2000-2017 Kitware, Inc. and Contributors.
//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: BSD 3-Clause, see licenses/bsd-3.md for more details.
/**
 *  \addtogroup PyCPP
 *  \brief Compiler detection macros.
 *
 *  Macros to detect the compiler type, version, and the C++ ISO standard
 *  supported by the compiler. To check a given compiler version against
 *  a desired version, use the `PYCPP_COMPILER_VERSION` macro against
 *  `PYCPP_COMPILER_VERSION_CODE`.
 *
 *  The only compilers considered are those with C++11 support,
 *  which may be determined here:
 *      http://en.cppreference.com/w/cpp/compiler_support#C.2B.2B11_features
 *
 *  \synopsis
 *      #define PYCPP_COMPILER_DETECTED             implementation-defined
 *      #define PYCPP_COMPILER_NAME                 implementation-defined
 *      #define PYCPP_COMPILER_MAJOR_VERSION        implementation-defined
 *      #define PYCPP_COMPILER_MINOR_VERSION        implementation-defined
 *      #define PYCPP_COMPILER_PATCH_VERSION        implementation-defined
 *      #define PYCPP_COMPILER_VERSION(a, b, c)     implementation-defined
 *      #define PYCPP_COMPILER_VERSION_CODE         implementation-defined
 *      #define PYCPP_CPP11                         implementation-defined
 *      #define PYCPP_CPP14                         implementation-defined
 *      #define PYCPP_CPP17                         implementation-defined
 *      #define PYCPP_CPP20                         implementation-defined
 *      #define PYCPP_GNUC                          implementation-defined
 *      #define PYCPP_GNUC_MAJOR_VERSION            implementation-defined
 *      #define PYCPP_GNUC_MINOR_VERSION            implementation-defined
 *      #define PYCPP_GNUC_PATCH_VERSION            implementation-defined
 *      #define PYCPP_CLANG                         implementation-defined
 *      #define PYCPP_CLANG_2                       implementation-defined
 *      #define PYCPP_CLANG_3                       implementation-defined
 *      #define PYCPP_CLANG_4                       implementation-defined
 *      #define PYCPP_CLANG_5                       implementation-defined
 *      #define PYCPP_GCC                           implementation-defined
 *      #define PYCPP_GCC_3                         implementation-defined
 *      #define PYCPP_GCC_4                         implementation-defined
 *      #define PYCPP_GCC_5                         implementation-defined
 *      #define PYCPP_GCC_6                         implementation-defined
 *      #define PYCPP_GCC_7                         implementation-defined
 *      #define PYCPP_GCC_8                         implementation-defined
 *      #define PYCPP_INTEL                         implementation-defined
 *      #define PYCPP_INTEL_MAJOR_VERSION           implementation-defined
 *      #define PYCPP_INTEL_MINOR_VERSION           implementation-defined
 *      #define PYCPP_INTEL_PATCH_VERSION           implementation-defined
 *      #define PYCPP_MSVC                          implementation-defined
 *      #define PYCPP_MSVC_10                       implementation-defined
 *      #define PYCPP_MSVC_11                       implementation-defined
 *      #define PYCPP_MSVC_12                       implementation-defined
 *      #define PYCPP_MSVC_14                       implementation-defined
 *      #define PYCPP_MSVC_5                        implementation-defined
 *      #define PYCPP_MSVC_6                        implementation-defined
 *      #define PYCPP_MSVC_7                        implementation-defined
 *      #define PYCPP_MSVC_7                        implementation-defined
 *      #define PYCPP_MSVC_8                        implementation-defined
 *      #define PYCPP_MSVC_9                        implementation-defined
 *      #define PYCPP_SUNPRO                        implementation-defined
 *      #define PYCPP_EDG                           implementation-defined
 *      #define PYCPP_CRAY                          implementation-defined
 *      #define PYCPP_PGI                           implementation-defined
 *      #define PYCPP_EMBARCADERO                   implementation-defined
 *      #define PYCPP_XL                            implementation-defined
 *      #define PYCPP_IAR                           implementation-defined
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
#   define PYCPP_INTEL 1
    // VERSION = VRP
    // Intel simulates other compilers, use the other compilers
    // version information, but also export Intel C++ compiler
    // version information under `INTEL_*_VERSION`.
#   define PYCPP_INTEL_MAJOR_VERSION __INTEL_COMPILER / 100
#   define PYCPP_INTEL_MINOR_VERSION (__INTEL_COMPILER / 10) % 10
#   if defined(__INTEL_COMPILER_UPDATE)
#       define PYCPP_INTEL_PATCH_VERSION __INTEL_COMPILER_UPDATE
#   else
#       define PYCPP_INTEL_PATCH_VERSION __INTEL_COMPILER % 10
#   endif
#endif

// COMEAU
// ------

// Detect presence of Comeau C++ compiler.
// Currently does not support C++11, disable.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__COMO__)
#   error "Comeau compiler does not have full C++11 support."
#   define PYCPP_COMO 1
#   define PYCPP_COMPILER_DETECTED PYCPP_COMO
#   define PYCPP_COMPILER_NAME = "Comeau"
    // VERSION = VRR
#   define PYCPP_COMPILER_MAJOR_VERSION (__COMO_VERSION__ / 100)
#   define PYCPP_COMPILER_MINOR_VERSION (__COMO_VERSION__ % 100)
#   define PYCPP_COMPILER_PATCH_VERSION 0
#endif

// MSVC
// ----

// Detect presence of an MSVC C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(_MSC_VER)
#   define PYCPP_MSVC 1
#   define PYCPP_COMPILER_DETECTED PYCPP_MSVC
#   define PYCPP_COMPILER_NAME = "MSVC"
#   if _MSC_VER >= 1911
#      define PYCPP_MSVC_14 1
#      define PYCPP_COMPILER_MAJOR_VERSION 15
#      define PYCPP_COMPILER_MINOR_VERSION 1
#      define PYCPP_COMPILER_PATCH_VERSION 3
#   elif _MSC_VER == 1910
#      define PYCPP_MSVC_14 1
#      define PYCPP_COMPILER_MAJOR_VERSION 14
#      define PYCPP_COMPILER_MINOR_VERSION 1
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1900
#      define PYCPP_MSVC_14 1
#      define PYCPP_COMPILER_MAJOR_VERSION 14
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1800
#      define PYCPP_MSVC_12 1
#      define PYCPP_COMPILER_MAJOR_VERSION 12
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1700
#      define PYCPP_MSVC_11 1
#      define PYCPP_COMPILER_MAJOR_VERSION 11
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1600
#      define PYCPP_MSVC_10 1
#      define PYCPP_COMPILER_MAJOR_VERSION 10
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1500
#      define PYCPP_MSVC_9 1
#      define PYCPP_COMPILER_MAJOR_VERSION 9
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1400
#      define PYCPP_MSVC_8 1
#      define PYCPP_COMPILER_MAJOR_VERSION 8
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1310
#      define PYCPP_MSVC_7 1
#      define PYCPP_COMPILER_MAJOR_VERSION 7
#      define PYCPP_COMPILER_MINOR_VERSION 1
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1300
#      define PYCPP_MSVC_7 1
#      define PYCPP_COMPILER_MAJOR_VERSION 7
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1200
#      define PYCPP_MSVC_6 1
#      define PYCPP_COMPILER_MAJOR_VERSION 6
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   elif _MSC_VER == 1100
#      define PYCPP_MSVC_5 1
#      define PYCPP_COMPILER_MAJOR_VERSION 5
#      define PYCPP_COMPILER_MINOR_VERSION 0
#      define PYCPP_COMPILER_PATCH_VERSION 0
#   endif
#endif

// GNUC
// ----

// Detect presence of a compiler using GNU C's preprocessor, which
// should be GCC-like compiler.
#if defined(__GNUC__)
#   define PYCPP_GNUC 1
#   define PYCPP_GNUC_MAJOR_VERSION __GNUC__
#   define PYCPP_GNUC_MINOR_VERSION __GNUC_MINOR__
#   if defined(__GNUC_PATCHLEVEL__)
    // Older compilers don't define __GNUC_PATCHLEVEL__
#       define PYCPP_GNUC_PATCH_VERSION __GNUC_PATCHLEVEL__
#   else
#       define PYCPP_GNUC_PATCH_VERSION 0
#   endif
#endif

// SUNPRO
// ------

// Detect presence of Sun/Oracle C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__SUNPRO_CC)
#   define PYCPP_SUNPRO 1
#   define PYCPP_COMPILER_DETECTED PYCPP_SUNPRO
#   define PYCPP_COMPILER_NAME "SunPro"
#   if __SUNPRO_CC < 0x590
        // VERSION = 0xVRP
#       define PYCPP_COMPILER_MAJOR_VERSION (__SUNPRO_CC & 0xF00) >> 8
#       define PYCPP_COMPILER_MINOR_VERSION (__SUNPRO_CC & 0x0F0) >> 4
#       define PYCPP_COMPILER_PATCH_VERSION __SUNPRO_CC & 0x00F
#   else
        // VERSION = 0xVRRP
#       define PYCPP_COMPILER_MAJOR_VERSION (__SUNPRO_CC & 0xF000) >> 12
#       define PYCPP_COMPILER_MINOR_VERSION 10*((__SUNPRO_CC & 0x0F00) >> 8) + ((__SUNPRO_CC & 0x00F0) >> 4)
#       define PYCPP_COMPILER_PATCH_VERSION __SUNPRO_CC & 0x000F
#   endif
#endif

// EDG
// ---

// Detect presence of the EDG C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__EDG__)
#   define PYCPP_EDG 1
#   define PYCPP_COMPILER_DETECTED PYCPP_EDG
#   define PYCPP_COMPILER_NAME "EDG"
    // VERSION = VRR
#   define PYCPP_COMPILER_MAJOR_VERSION (__EDG_VERSION__ / 100)
#   define PYCPP_COMPILER_MINOR_VERSION (__EDG_VERSION__ % 100)
#   define PYCPP_COMPILER_PATCH_VERSION 0
#endif

// CRAY
// ----

// Detect presence of Cray C compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(_CRAYC)
#   define PYCPP_CRAY 1
#   define PYCPP_COMPILER_DETECTED PYCPP_CRAY
#   define PYCPP_COMPILER_NAME "Cray"
#   define PYCPP_COMPILER_MAJOR_VERSION _RELEASE_MAJOR
#   define PYCPP_COMPILER_MINOR_VERSION _RELEASE_MINOR
#   define PYCPP_COMPILER_PATCH_VERSION 0
#endif

// PGI
// ---

// Detect presence of the Portland Group C/C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__PGI)
#   define PYCPP_PGI 1
#   define PYCPP_COMPILER_DETECTED PYCPP_PGI
#   define PYCPP_COMPILER_NAME "PGI"
#   define PYCPP_COMPILER_MAJOR_VERSION __PGIC__
#   define PYCPP_COMPILER_MINOR_VERSION __PGIC_MINOR__
#   define PYCPP_COMPILER_PATCH_VERSION __PGIC_PATCHLEVEL__
#endif

// FUJITSU
// -------

// Detect presence of Fujitsu C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version))
#   error "Unknown ISO C++ support for Fujitsu."
#   define PYCPP_FUJITSU 1
#   define PYCPP_COMPILER_DETECTED PYCPP_FUJITSU
#   define PYCPP_COMPILER_NAME "Fujitsu"
#endif

// SCO
// ---

// Detect presence of the USL C (SCO) C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__USLC__) || defined(__SCO_VERSION__))
#   error "Unknown ISO C++ support for USL C++ compiler."
#   define PYCPP_SCO 1
#   define PYCPP_COMPILER_DETECTED PYCPP_SCO
#   define PYCPP_COMPILER_NAME "SCO"
    // VERSION = VRRYYYYMM
#   define PYCPP_COMPILER_MAJOR_VERSION __SCO_VERSION__ / 100000000
#   define PYCPP_COMPILER_MINOR_VERSION (__SCO_VERSION__ / 1000000) % 100
#   define PYCPP_COMPILER_PATCH_VERSION 0
#endif

// PATHSCALE
// ---------

// Detect presence of PathScale C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__PATHCC__)
#   error "PathScale compiler does not have full C++11 support."
#   define PYCPP_PATHSCALE 1
#   define PYCPP_COMPILER_DETECTED PYCPP_PATHSCALE
#   define PYCPP_COMPILER_NAME "PathScale"
#   define PYCPP_COMPILER_MAJOR_VERSION __PATHCC__
#   define PYCPP_COMPILER_MINOR_VERSION __PATHCC_MINOR__
#   if defined(__PATHCC_PATCHLEVEL__)
#       define PYCPP_COMPILER_PATCH_VERSION __PATHCC_PATCHLEVEL__
#   endif
#endif

// EMBARCADERO
// -----------

// Detect the presence of C++ Builder, by Embarcadero Technologies,
// mostly used for Delphi applications.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__))
#   define PYCPP_EMBARCADERO 1
#   define PYCPP_COMPILER_DETECTED PYCPP_EMBARCADERO
#   define PYCPP_COMPILER_NAME "Embarcadero"
#   define PYCPP_COMPILER_MAJOR_VERSION ((__CODEGEARC_VERSION__ >> 24) & 0x00FF)
#   define PYCPP_COMPILER_MINOR_VERSION ((__CODEGEARC_VERSION__ >> 16) & 0x00FF)
#   define PYCPP_COMPILER_PATCH_VERSION (__CODEGEARC_VERSION__ & 0xFFFF)
#endif

// BORLAND
// -------

// Detect Borland C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__BORLANDC__)
#   error "Borland compiler does not have C++11 support."
#   define PYCPP_BORLAND 1
#   define PYCPP_COMPILER_DETECTED PYCPP_BORLAND
#   define PYCPP_COMPILER_NAME "Borland"
#   define PYCPP_COMPILER_MAJOR_VERSION (__BORLANDC__ >> 8)
#   define PYCPP_COMPILER_MINOR_VERSION (__BORLANDC__ & 0xFF)
#   define PYCPP_COMPILER_PATCH_VERSION 0
#endif

// WATCOM
// ------

// Detect the ancient proprietary Watcom C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__WATCOMC__) && __WATCOMC__ < 1200)
#   error "Watcom compiler does not have C++11 support."
#   define PYCPP_WATCOM 1
#   define PYCPP_COMPILER_DETECTED PYCPP_WATCOM
#   define PYCPP_COMPILER_NAME "Watcom"
#   define PYCPP_COMPILER_MAJOR_VERSION (__WATCOMC__ / 100)
#   define PYCPP_COMPILER_MINOR_VERSION ((__WATCOMC__ / 10) % 10)
#   define PYCPP_COMPILER_PATCH_VERSION (__WATCOMC__ % 10)
#endif

// Detect the open source Watcom C++ compiler (originally known as
// OpenWatcom, now known as Watcom C/C++ compiler).
// OpenWatcom should have C++11 support.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__WATCOMC__)
#   define PYCPP_OPENWATCOM 1
#   define PYCPP_COMPILER_DETECTED PYCPP_OPENWATCOM
#   define PYCPP_COMPILER_NAME "OpenWatcom"
    // VERSION = VVRP + 1100
#   define PYCPP_COMPILER_MAJOR_VERSION ((__WATCOMC__ - 1100) / 100)
#   define PYCPP_COMPILER_MINOR_VERSION ((__WATCOMC__ / 10) % 10)
#   define PYCPP_COMPILER_PATCH_VERSION (__WATCOMC__ % 10)
#endif

// HP
// --

#if !defined(PYCPP_COMPILER_DETECTED) && defined(__HP_aCC)
#   error "HP aCC compiler does not have full C++11 support."
#   define PYCPP_HP 1
#   define PYCPP_COMPILER_DETECTED PYCPP_HP
#   define PYCPP_COMPILER_NAME "HP aCC"
    // VERSION = VVRRPP
#   define PYCPP_COMPILER_MAJOR_VERSION (__HP_aCC/10000)
#   define PYCPP_COMPILER_MINOR_VERSION (__HP_aCC/100 % 100)
#   define PYCPP_COMPILER_PATCH_VERSION (__HP_aCC % 100)
#endif

// COMPAQ
// ------

// Detect presence of Compaq C++ compiler, which stopped support
// before C++11.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__DECCXX)
#   error "Unknown ISO C++ support for COmpaq."
#   define PYCPP_COMPAQ 1
#   define PYCPP_COMPILER_DETECTED PYCPP_COMPAQ
#   define PYCPP_COMPILER_NAME "COmpaq"
    // VERSION = VVRRTPPPP
#   define PYCPP_COMPILER_MAJOR_VERSION (__DECCXX_VER / 10000000)
#   define PYCPP_COMPILER_MINOR_VERSION ((__DECCXX_VER / 100000) % 100)
#   define PYCPP_COMPILER_PATCH_VERSION (__DECCXX_VER % 10000)
#endif

// IBCPP
// -----

// Detect presence of z/OS C++ compiler, which dubiously has supported
// C++11 on Linux since 2008. Likely has partial C++11 support
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__IBMCPP__) && defined(__COMPILER_VER__))
#   define PYCPP_ZOS 1
#   define PYCPP_COMPILER_DETECTED PYCPP_ZOS
#   define PYCPP_COMPILER_NAME "zOS"
    // VERSION = VRP
#   define PYCPP_COMPILER_MAJOR_VERSION (__IBMCPP__ / 100)
#   define PYCPP_COMPILER_MINOR_VERSION ((__IBMCPP__ / 10) % 10)
#   define PYCPP_COMPILER_PATCH_VERSION (__IBMCPP__ % 10)
#endif

// Detect presence of XL C++ compiler, which supports C++11 on Linux.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800)
#   define PYCPP_XL 1
#   define PYCPP_COMPILER_DETECTED PYCPP_XL
#   define PYCPP_COMPILER_NAME "XL"
    // VERSION = VRP
#   define PYCPP_COMPILER_MAJOR_VERSION (__IBMCPP__ / 100)
#   define PYCPP_COMPILER_MINOR_VERSION ((__IBMCPP__ / 10) % 10)
#   define PYCPP_COMPILER_PATCH_VERSION (__IBMCPP__ % 10)
#endif

// Detect presence of VisualAge C++ compiler, which stopped support
// before C++11.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800)
#   error "Unknown ISO C++ support for VisualAge."
#   define PYCPP_VISUALAGE 1
#   define PYCPP_COMPILER_DETECTED PYCPP_VISUALAGE
#   define PYCPP_COMPILER_NAME "VisualAge"
    // VERSION = VRP
#   define PYCPP_COMPILER_MAJOR_VERSION (__IBMCPP__ / 100)
#   define PYCPP_COMPILER_MINOR_VERSION ((__IBMCPP__ / 10) % 10)
#   define PYCPP_COMPILER_PATCH_VERSION (__IBMCPP__ % 10)
#endif

// VISUALDSP
// ---------

// Detect presence of VisualDSP compiler, a compiler for Blackfin processors.
// I believe VisualDSP only has C++98 support.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__))
#   error "Unknown ISO C++ support for ADSP."
#   define PYCPP_ADSP 1
#   define PYCPP_COMPILER_DETECTED PYCPP_ADSP
#   define PYCPP_COMPILER_NAME "ADSP"
#   if defined(__VISUALDSPVERSION__)
        // VERSION = 0xVVRRPP00
#       define PYCPP_COMPILER_MAJOR_VERSION (__VISUALDSPVERSION__ >> 24)
#       define PYCPP_COMPILER_MINOR_VERSION ((__VISUALDSPVERSION__ >> 16) & 0xFF)
#       define PYCPP_COMPILER_PATCH_VERSION ((__VISUALDSPVERSION__ >> 8) & 0xFF)
#   endif
#endif

// IAR
// ---

// Detect presence of IAR compiler, a C++14-compiler for embedded systems.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC))
#   define PYCPP_IAR 1
#   define PYCPP_COMPILER_DETECTED PYCPP_IAR
#   define PYCPP_COMPILER_NAME "IAR"
#   if defined(__VER__)
#       define PYCPP_COMPILER_MAJOR_VERSION ((__VER__) / 1000000)
#       define PYCPP_COMPILER_MINOR_VERSION (((__VER__) / 1000) % 1000)
#       define PYCPP_COMPILER_PATCH_VERSION ((__VER__) % 1000)
#   endif
#endif

// ARMCC
// -----

// Detect presence of ARMCC compiler, a C++03-compiler for embedded systems.
// ARMCC has partial (and improving) C++11 support, add when
// C++11 support is complete.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__ARMCC_VERSION)
#   error "ARMCC compiler does not have full C++11 support."
#   define PYCPP_ARMCC 1
#   define PYCPP_COMPILER_DETECTED PYCPP_ARMCC
#   define PYCPP_COMPILER_NAME "ARMCC"
#   if __ARMCC_VERSION >= 1000000
        // VERSION = VRRPPPP
#       define PYCPP_COMPILER_MAJOR_VERSION (__ARMCC_VERSION / 1000000)
#       define PYCPP_COMPILER_MINOR_VERSION ((__ARMCC_VERSION / 10000) % 100)
#       define PYCPP_COMPILER_PATCH_VERSION (__ARMCC_VERSION % 10000)
#   else
        // VERSION = VRPPPP
#       define PYCPP_COMPILER_MAJOR_VERSION (__ARMCC_VERSION / 100000)
#       define PYCPP_COMPILER_MINOR_VERSION ((__ARMCC_VERSION / 10000) % 10)
#       define PYCPP_COMPILER_PATCH_VERSION (__ARMCC_VERSION % 10000)
#   endif
#endif

// MIPSPRO
// -------

// Detect prescence of modern MIPSPro C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(_SGI_COMPILER_VERSION) || defined(_COMPILER_VERSION))
#   error "Unknown ISO C++ support for MIPSpro."
#   define PYCPP_MIPSPRO 1
#   define PYCPP_COMPILER_DETECTED PYCPP_MIPSPRO
#   define PYCPP_COMPILER_NAME "MIPSpro"
#   if defined(_SGI_COMPILER_VERSION)
#       define PYCPP_COMPILER_MAJOR_VERSION (_SGI_COMPILER_VERSION / 100)
#       define PYCPP_COMPILER_MINOR_VERSION ((_SGI_COMPILER_VERSION / 10) % 10)
#       define PYCPP_COMPILER_PATCH_VERSION (_SGI_COMPILER_VERSION % 10)
#   else
#       define PYCPP_COMPILER_MAJOR_VERSION (_COMPILER_VERSION / 100)
#       define PYCPP_COMPILER_MINOR_VERSION ((_COMPILER_VERSION / 10) % 10)
#       define PYCPP_COMPILER_PATCH_VERSION (_COMPILER_VERSION % 10)
#   endif
#endif

// Detect presence of ancient version of MIPSpro C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__sgi)
#   error "Unknown ISO C++ support for MIPSpro."
#   define PYCPP_MIPSPRO 1
#   define PYCPP_COMPILER_DETECTED PYCPP_MIPSPRO
#   define PYCPP_COMPILER_NAME "MIPSpro"
#endif

// HPUX/HPUA
// ---------

// Detect presence of HP/UX C++ compiler.
#if !defined(PYCPP_COMPILER_DETECTED) && (defined(__hpux) || defined(__hpua))
#   error "Unknown ISO C++ support for HP/UX."
#   define PYCPP_HPUX 1
#   define PYCPP_COMPILER_DETECTED PYCPP_HPUX
#   define PYCPP_COMPILER_NAME "HP/UX"
#endif

// CLANG
// -----

// Fallback, no other front-ends besides GNU C used for Clang.
// Detect presence of Clang compiler, using any LLVM or GNUC backend.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(__clang__)
#   define PYCPP_CLANG 1
#   define PYCPP_COMPILER_DETECTED PYCPP_CLANG
#   define PYCPP_COMPILER_MAJOR_VERSION __clang_major__
#   define PYCPP_COMPILER_MINOR_VERSION __clang_minor__
#   define PYCPP_COMPILER_PATCH_VERSION __clang_patchlevel__
#   if PYCPP_COMPILER_MAJOR_VERSION == 5
#      define PYCPP_CLANG_5 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 4
#      define PYCPP_CLANG_4 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 3
#      define PYCPP_CLANG_3 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 2
#      define PYCPP_CLANG_2 1
#   endif
#endif

// GCC
// ---

// Fallback, no other GNU-like compilers possible,
// we have GCC.
#if !defined(PYCPP_COMPILER_DETECTED) && defined(PYCPP_GNUC)
#   define PYCPP_GCC 1
#   define PYCPP_COMPILER_DETECTED PYCPP_GCC
#   define PYCPP_COMPILER_NAME "GCC"
#   define PYCPP_COMPILER_MAJOR_VERSION PYCPP_GNUC_MAJOR_VERSION
#   define PYCPP_COMPILER_MINOR_VERSION PYCPP_GNUC_MINOR_VERSION
#   define PYCPP_COMPILER_PATCH_VERSION PYCPP_GNUC_PATCH_VERSION
#   if PYCPP_COMPILER_MAJOR_VERSION == 8
#      define PYCPP_GCC_8 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 7
#      define PYCPP_GCC_7 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 6
#      define PYCPP_GCC_6 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 5
#      define PYCPP_GCC_5 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 4
#      define PYCPP_GCC_4 1
#   elif PYCPP_COMPILER_MAJOR_VERSION == 3
#      define PYCPP_GCC_3 1
#   endif
#endif

// C++
// ---

#if defined(__cplusplus)
// TODO: C++20 has not yet been standardized, refine when ratified.
#   if __cplusplus >= 202099L
#       define PYCPP_CPP20 1
#   endif
#   if __cplusplus >= 201703L
#       define PYCPP_CPP17 1
#   endif
#   if __cplusplus >= 201402L
#       define PYCPP_CPP14 1
#   endif
#   if __cplusplus >= 201103L
#       define PYCPP_CPP11 1
#   endif
#endif

// VERSION
// -------

#define PYCPP_COMPILER_VERSION(major, minor, patch)     \
    ((major << 16) + (minor << 8) + patch)

#define PYCPP_COMPILER_VERSION_CODE                     \
    PYCPP_COMPILER_VERSION(PYCPP_COMPILER_MAJOR_VERSION,      \
                     PYCPP_COMPILER_MINOR_VERSION,            \
                     PYCPP_COMPILER_PATCH_VERSION)
