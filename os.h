//  :copyright: (c) 2001-2002 John Maddock.
//  :copyright: (c) 2001 Jens Maurer.
//  :copyright: (c) 2008-2013 Rene Rivera.
//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: Boost, see licenses/boost.md for more details.
/**
 *  \addtogroup PySTD
 *  \brief Detect operating system for build.
 *
 *  Macros to detect the operating system and potentially the operating
 *  system version. If the operating system is detected, `PYCPP_OS_DETECTED`
 *  will be defined. If a POSIX-like system is detected, `OS_POSIX`
 *  will be defined (**not** `OS_UNIX`, which is for Unixware). If
 *  PyCPP is able to detect the operating system version, it will also
 *  define `PYCPP_OS_VERSION_MAJOR`, `PYCPP_OS_VERSION_MINOR`, and `PYCPP_OS_VERSION_PATCH`.
 *
 *  \synopsis
 *      #define PYCPP_OS_DETECTED           implementation-defined
 *      #define PYCPP_OS_VERSION_MAJOR      implementation-defined
 *      #define PYCPP_OS_VERSION_MINOR      implementation-defined
 *      #define PYCPP_OS_VERSION_PATCH      implementation-defined
 *      #define PYCPP_AEGIS                 implementation-defined
 *      #define PYCPP_AIX                   implementation-defined
 *      #define PYCPP_AMDAHL                implementation-defined
 *      #define PYCPP_AMIGAOS               implementation-defined
 *      #define PYCPP_ANDROID               implementation-defined
 *      #define PYCPP_APOLLO                implementation-defined
 *      #define PYCPP_BEOS                  implementation-defined
 *      #define PYCPP_BLUEGENE              implementation-defined
 *      #define PYCPP_BSD                   implementation-defined
 *      #define PYCPP_BSD4_2                implementation-defined
 *      #define PYCPP_BSD4_3                implementation-defined
 *      #define PYCPP_BSD4_4                implementation-defined
 *      #define PYCPP_BSDI                  implementation-defined
 *      #define PYCPP_CONVEX                implementation-defined
 *      #define PYCPP_CYGWIN                implementation-defined
 *      #define PYCPP_DARWIN                implementation-defined
 *      #define PYCPP_OS_DGUX               implementation-defined
 *      #define PYCPP_OS_DYNIX              implementation-defined
 *      #define PYCPP_OS_ECOS               implementation-defined
 *      #define PYCPP_OS_EMX                implementation-defined
 *      #define PYCPP_OS_FREEBSD            implementation-defined
 *      #define PYCPP_OS_HAIKU              implementation-defined
 *      #define PYCPP_OS_HPUX               implementation-defined
 *      #define PYCPP_OS_HURD               implementation-defined
 *      #define PYCPP_OS_INTEGRITY          implementation-defined
 *      #define PYCPP_OS_INTERIX            implementation-defined
 *      #define PYCPP_OS_IOS                implementation-defined
 *      #define PYCPP_OS_IRIX               implementation-defined
 *      #define PYCPP_OS_LINUX              implementation-defined
 *      #define PYCPP_OS_LYNX               implementation-defined
 *      #define PYCPP_OS_MACOS              implementation-defined
 *      #define PYCPP_OS_MACOSX             implementation-defined
 *      #define PYCPP_OS_MICROWARE          implementation-defined
 *      #define PYCPP_OS_MINIX              implementation-defined
 *      #define PYCPP_OS_MORPHOS            implementation-defined
 *      #define PYCPP_OS_MPEIX              implementation-defined
 *      #define PYCPP_OS_MSDOS              implementation-defined
 *      #define PYCPP_OS_NACL               implementation-defined
 *      #define PYCPP_OS_NETBSD             implementation-defined
 *      #define PYCPP_OS_NONSTOP            implementation-defined
 *      #define PYCPP_OS_NUCLEUS            implementation-defined
 *      #define PYCPP_OS_OPENBSD            implementation-defined
 *      #define PYCPP_OS_OS2                implementation-defined
 *      #define PYCPP_OS_OS400              implementation-defined
 *      #define PYCPP_OS_OSF                implementation-defined
 *      #define PYCPP_OS_PALM               implementation-defined
 *      #define PYCPP_OS_PLAN9              implementation-defined
 *      #define PYCPP_OS_POSIX              implementation-defined
 *      #define PYCPP_OS_PYRAMID            implementation-defined
 *      #define PYCPP_OS_QNX                implementation-defined
 *      #define PYCPP_OS_RELIANT            implementation-defined
 *      #define PYCPP_OS_SCO                implementation-defined
 *      #define PYCPP_OS_SOLARIS            implementation-defined
 *      #define PYCPP_OS_SVR4               implementation-defined
 *      #define PYCPP_OS_SYLLABLE           implementation-defined
 *      #define PYCPP_OS_SYMBIAN            implementation-defined
 *      #define PYCPP_OS_ULTRIX             implementation-defined
 *      #define PYCPP_OS_UNICOS             implementation-defined
 *      #define PYCPP_OS_UNICOSMP           implementation-defined
 *      #define PYCPP_OS_UNIX               implementation-defined
 *      #define PYCPP_OS_UNIXWARE           implementation-defined
 *      #define PYCPP_OS_VMS                implementation-defined
 *      #define PYCPP_OS_VOS                implementation-defined
 *      #define PYCPP_OS_VXWORKS            implementation-defined
 *      #define PYCPP_OS_WINAPI_DESKTOP     implementation-defined
 *      #define PYCPP_WINDOWS               implementation-defined
 *      #define PYCPP_WINDOWS_CE            implementation-defined
 *      #define PYCPP_OS_WINDU              implementation-defined
 *      #define PYCPP_OS_ZOS                implementation-defined
 */

#pragma once

// ANDROID
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__ANDROID__) || defined(ANDROID)
#       define PYCPP_ANDROID
#       define PYCPP_OS_LINUX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// LINUX
// -----

#if !defined(PYCPP_OS_DETECTED)
#   if defined(__linux__) || defined(linux) || defined(__linux)
// DETECTION
#       define PYCPP_OS_LINUX
#       define PYCPP_OS_DETECTED
// VERSION
#       include <linux/version.h>
#       define PYCPP_OS_VERSION_MAJOR (LINUX_VERSION_CODE >> 16)
#       define PYCPP_OS_VERSION_MINOR ((LINUX_VERSION_CODE - (PYCPP_OS_VERSION_MAJOR << 16)) >> 8)
#       define PYCPP_OS_VERSION_PATCH ((LINUX_VERSION_CODE - ((PYCPP_OS_VERSION_MAJOR << 16) + (PYCPP_OS_VERSION_MINOR << 8))))
#   endif
#endif

// MACOS
// -----

#if !defined(PYCPP_OS_DETECTED)
// VERSION
#   if defined(__APPLE__) && defined(__MACH__)
#       define PYCPP_OS_VERSION_MAJOR 10
#       define PYCPP_OS_VERSION_MINOR 0
#       define PYCPP_OS_VERSION_PATCH 0
#   elif defined(__APPLE__) || defined(macintosh)
#       define PYCPP_OS_VERSION_MAJOR 9
#       define PYCPP_OS_VERSION_MINOR 0
#       define PYCPP_OS_VERSION_PATCH 0
#   endif
// DETECTION
#   if defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#       define PYCPP_OS_MACOS
#       define PYCPP_OS_DETECTED
#       if defined(__APPLE__) && defined(__MACH__)
#           define PYCPP_DARWIN
#           define PYCPP_BSD
#           define PYCPP_BSD4_4
#       endif
// SUBPLATFORMS
#       include <TargetConditionals.h>
#       if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#           define PYCPP_OS_IOS
#       elif TARGET_OS_MAC
#           define PYCPP_OS_MACOSX
#       endif
#   endif
#endif

// BSD
// ---

#if !defined(PYCPP_OS_DETECTED)
// VERSION
#   if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__bsdi__) || defined(__INTERIX)
#       include <sys/param.h>
#       define PYCPP_BSD
#       define PYCPP_OS_DETECTED
#       if defined(BSD4_4)
#           define PYCPP_BSD4_4
#          define PYCPP_OS_VERSION_MAJOR 4
#          define PYCPP_OS_VERSION_MINOR 4
#          define PYCPP_OS_VERSION_PATCH 0
#       elif defined(BSD4_3)
#           define PYCPP_BSD4_3
#          define PYCPP_OS_VERSION_MAJOR 4
#          define PYCPP_OS_VERSION_MINOR 3
#          define PYCPP_OS_VERSION_PATCH 0
#       elif defined(BSD4_2)
#           define PYCPP_BSD4_2
#          define PYCPP_OS_VERSION_MAJOR 4
#          define PYCPP_OS_VERSION_MINOR 2
#          define PYCPP_OS_VERSION_PATCH 0
#       endif
#   endif
// DETECTION
#   if defined(__FreeBSD__) || defined(__DragonFly__)
#       define PYCPP_OS_FREEBSD
#   elif defined(__NetBSD__)
#       define PYCPP_OS_NETBSD
#   elif defined(__OpenBSD__)
#       define PYCPP_OS_OPENBSD
#   elif defined(__bsdi__)
#       define PYCPP_BSDI
#   elif defined(__INTERIX)
#       define PYCPP_OS_INTERIX
#   endif
#endif

// SOLARIS
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__sun) || defined(sun)
#       define PYCPP_OS_SOLARIS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// IRIX
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(sgi) || defined(__sgi)
#       define PYCPP_OS_IRIX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// HPUX
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__hpux) || defined(hpux) || defined(_hpux)
#       define PYCPP_OS_HPUX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// CYGWIN
// ------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__CYGWIN__)
#       define PYCPP_CYGWIN
#       define PYCPP_OS_DETECTED
#   endif
#endif

// WIN32
// -----

#if !defined(PYCPP_OS_DETECTED)
#   if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) || defined(__NT__)
#      include <sdkddkver.h>
#       if _WIN32_WINNT == _WIN32_WINNT_NT4
#       elif _WIN32_WINNT == _WIN32_WINNT_WIN2K             // NT 4.0
#           define PYCPP_OS_VERSION_MAJOR 4
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WINXP             // 2000
#           define PYCPP_OS_VERSION_MAJOR 6
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WS03              // XP
#           define PYCPP_OS_VERSION_MAJOR 6
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WIN6              // Server 2003
#           define PYCPP_OS_VERSION_MAJOR 6
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_VISTA             // VISTA
#           define PYCPP_OS_VERSION_MAJOR 7
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WS08              // VISTA
#           define PYCPP_OS_VERSION_MAJOR 7
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WS08              // VISTA
#           define PYCPP_OS_VERSION_MAJOR 7
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_LONGHORN          // VISTA
#           define PYCPP_OS_VERSION_MAJOR 7
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WIN7              // WINDOWS 7
#           define PYCPP_OS_VERSION_MAJOR 8
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WIN8              // WINDOWS 8
#           define PYCPP_OS_VERSION_MAJOR 9
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WINBLUE           // WINDOWS 8
#           define PYCPP_OS_VERSION_MAJOR 9
#           define PYCPP_OS_VERSION_MINOR 1
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WINTHRESHOLD      // WINDOWS 10
#           define PYCPP_OS_VERSION_MAJOR 10
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       elif _WIN32_WINNT == _WIN32_WINNT_WIN10             // WINDOWS 10
#           define PYCPP_OS_VERSION_MAJOR 10
#           define PYCPP_OS_VERSION_MINOR 0
#           define PYCPP_OS_VERSION_PATCH 0
#       endif
#   endif
// DETECTION
#   if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) || defined(__NT__)
#       define PYCPP_WINDOWS
#       define PYCPP_OS_DETECTED
#       if !defined(WINAPI_FAMILY) || WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#           define PYCPP_OS_WINAPI_DESKTOP
#       endif
#   endif
#endif

// WINDOWS CE
// ----------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(_WIN32_WCE)
#       define PYCPP_WINDOWS_CE
#       define PYCPP_OS_DETECTED
#   endif
#endif

// HAIKU
// -----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__HAIKU__)
#       define PYCPP_OS_HAIKU
#       define PYCPP_OS_DETECTED
#   endif
#endif

// BEOS
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__BEOS__)
#       define PYCPP_BEOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// AIX
// ---

#if !defined(PYCPP_OS_DETECTED)
// VERSION
#   if defined(_AIX43)
#       define PYCPP_OS_VERSION_MAJOR 4
#       define PYCPP_OS_VERSION_MINOR 3
#       define PYCPP_OS_VERSION_PATCH 0
#   elif defined(_AIX41)
#       define PYCPP_OS_VERSION_MAJOR 4
#       define PYCPP_OS_VERSION_MINOR 1
#       define PYCPP_OS_VERSION_PATCH 0
#   elif defined(_AIX32)
#       define PYCPP_OS_VERSION_MAJOR 3
#       define PYCPP_OS_VERSION_MINOR 2
#       define PYCPP_OS_VERSION_PATCH 0
#   elif defined(_AIX3)
#       define PYCPP_OS_VERSION_MAJOR 3
#       define PYCPP_OS_VERSION_MINOR 0
#       define PYCPP_OS_VERSION_PATCH 0
#   endif
// DETECTION
#   if defined(_AIX) || defined(__TPYCPP_AIX__) || defined(__IBMCPP__)
#       define PYCPP_AIX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// AMIGAOS
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(AMIGA) || defined(__amigaos__)
#       define PYCPP_AMIGAOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// QNX
// ---

#if !defined(PYCPP_OS_DETECTED)
// VERSION
#   if defined(__QNX__)
#       define PYCPP_OS_VERSION_MAJOR 4
#       define PYCPP_OS_VERSION_MINOR 0
#       define PYCPP_OS_VERSION_PATCH 0
#   endif
// DETECTION
#   if defined(__QNX__) || defined(__QNXNTO__)
#       define PYCPP_OS_QNX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// VXWORKS
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION && VERSION
#   include <version.h>
#   if defined(__VXWORKS__) || defined(__vxworks) || defined(__RTP__) || defined(_WRS_KERNEL)
#       define PYCPP_OS_VXWORKS
#       define PYCPP_OS_DETECTED
#       define PYCPP_OS_VERSION_MAJOR _WRS_VXWORKS_MAJOR
#       define PYCPP_OS_VERSION_MINOR _WRS_VXWORKS_MINOR
#       define PYCPP_OS_VERSION_PATCH _WRS_VXWORKS_MAINT
#   endif
#endif

// SYMBIAN
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__SYMBIAN32__)
#       define PYCPP_OS_SYMBIAN
#       define PYCPP_OS_DETECTED
#   endif
#endif

// VMS
// ---

#if !defined(PYCPP_OS_DETECTED)
// VERSION
#   if defined(__VMS_VER)
#       define PYCPP_OS_VERSION_MAJOR __VMS_VER / 10000000
#       define PYCPP_OS_VERSION_MINOR (__VMS_VER - PYCPP_OS_VERSION_MAJOR * 10000000) / 100000
#       define PYCPP_OS_VERSION_PATCH 0
#   endif
// DETECTION
#   if defined(__VMS)
#       define PYCPP_OS_VMS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// ULTRIX
// ------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__ultrix) || defined(ultrix)
#       define PYCPP_OS_ULTRIX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// RELIANT
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(sinix)
#       define PYCPP_OS_RELIANT
#       define PYCPP_OS_DETECTED
#   endif
#endif

// NATIVE CLIENT
// -------------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__native_client__)
#       define PYCPP_OS_NACL
#       define PYCPP_OS_DETECTED
#   endif
#endif

// DYNIX
// -----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(_SEQUENT_) || defined(sequent)
#       define PYCPP_OS_DYNIX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// ECOS
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__ECOS)
#       define PYCPP_OS_ECOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// EMX
// ---

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__EMX__)
#       define PYCPP_OS_EMX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// OSF
// ---

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__osf__)
#       define PYCPP_OS_OSF
#       define PYCPP_OS_DETECTED
#   endif
#endif

// DGUX
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#       define PYCPP_OS_DGUX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// INTEGRITY
// ---------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__INTEGRITY)
#       define PYCPP_OS_INTEGRITY
#       define PYCPP_OS_DETECTED
#   endif
#endif

// LYNX
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__Lynx__)
#       define PYCPP_OS_LYNX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// SCO
// ---

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(_SCO_DS) || defined(M_XENIX) || defined(M_I386)
#       define PYCPP_OS_SCO
#       define PYCPP_OS_DETECTED
#   endif
#endif

// HURD
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__GNU__) || defined(__gnu_hurd__)
#       define PYCPP_OS_HURD
#       define PYCPP_OS_DETECTED
#   endif
#endif

// UNIXWARE
// --------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__USLC__) || defined(_UNIXWARE7) || defined(sco)
#       define PYCPP_OS_UNIXWARE
#       define PYCPP_OS_DETECTED
#   endif
#endif

// AMDAHL
// ------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(UTS)
#       define PYCPP_AMDAHL
#       define PYCPP_OS_DETECTED
#   endif
#endif

// APOLLO AEGIS
// ------------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(aegis)
#       define PYCPP_AEGIS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// APOLLO DOMAIN
// -------------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(apollo)
#       define PYCPP_APOLLO
#       define PYCPP_OS_DETECTED
#   endif
#endif

// BLUE GENE
// ---------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__bg__) || defined(__bgq__) || defined(__THW_BLUEGENE__) || defined(__TOS_BGQ__)
#       define PYCPP_BLUEGENE
#       define PYCPP_OS_DETECTED
#   endif
#endif

// MINIX
// -----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__convex__)
#       define PYCPP_CONVEX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// MINIX
// -----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__minix)
#       define PYCPP_OS_MINIX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// MORPHOS
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__MORPHOS__)
#       define PYCPP_OS_MORPHOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// MPE/IX
// ------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(mpeix) || defined(__mpexl)
#       define PYCPP_OS_MPEIX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// MICROWARE
// ---------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__OS9000) || defined(_OSK)
#       define PYCPP_OS_MICROWARE
#       define PYCPP_OS_DETECTED
#   endif
#endif

// MSDOS
// -----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#       define PYCPP_OS_MSDOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// NONSTOP
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__TANDEM)
#       define PYCPP_OS_NONSTOP
#       define PYCPP_OS_DETECTED
#   endif
#endif

// NUCLEUS
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__nucleus__)
#       define PYCPP_OS_NUCLEUS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// OS2
// ---

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#       define PYCPP_OS_OS2
#       define PYCPP_OS_DETECTED
#   endif
#endif

// OS400
// -----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__OS400__)
#       define PYCPP_OS_OS400
#       define PYCPP_OS_DETECTED
#   endif
#endif

// PALM OS
// -------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__palmos__)
#       define PYCPP_OS_PALM
#       define PYCPP_OS_DETECTED
#   endif
#endif

// PLAN9
// -----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(EPLAN9)
#       define PYCPP_OS_PLAN9
#       define PYCPP_OS_DETECTED
#   endif
#endif

// PYRAMID DC/OSx
// --------------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(pyr)
#       define PYCPP_OS_PYRAMID
#       define PYCPP_OS_DETECTED
#   endif
#endif

// STARTUS VOS
// -----------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__VOS__)
#       define PYCPP_OS_VOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// SVR4
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#       define PYCPP_OS_SVR4
#       define PYCPP_OS_DETECTED
#   endif
#endif

// SYLLABLE
// --------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__SYLLABLE__)
#       define PYCPP_OS_SYLLABLE
#       define PYCPP_OS_DETECTED
#   endif
#endif

// UNICOS
// ------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(_UNICOS)
#       define PYCPP_OS_UNICOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// UNICOS/mp
// ---------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(_CRAY) || defined(__crayx1)
#       define PYCPP_OS_UNICOSMP
#       define PYCPP_OS_DETECTED
#   endif
#endif

// WIND/U
// ------

#if !defined(PYCPP_OS_DETECTED)
// DETECTION && VERSION
#   if defined(_WINDU_SOURCE)
#       define PYCPP_OS_WINDU
#       define PYCPP_OS_DETECTED
#       define PYCPP_OS_VERSION_MAJOR (_WINDU_SOURCE & 0xff0000) >> 16
#       define PYCPP_OS_VERSION_MINOR (_WINDU_SOURCE & 0xff00) >> 8
#       define PYCPP_OS_VERSION_PATCH (_WINDU_SOURCE & 0xff)
#   endif
#endif

// Z/OS
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION && VERSION
#   if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#       define PYCPP_OS_ZOS
#       define PYCPP_OS_DETECTED
#   endif
#endif

// UNIX
// ----

#if !defined(PYCPP_OS_DETECTED)
// DETECTION
#   if defined(__unix__) || defined(__unix)
#       define PYCPP_OS_UNIX
#       define PYCPP_OS_DETECTED
#   endif
#endif

// POSIX
// -----

// Check if we have a POSIX-like system.
#if defined(PYCPP_OS_DETECTED)
#   if defined(OS_LINUX) || defined(OS_MACOS) || defined(PYCPP_BSD) || \
        defined(OS_SOLARIS) || defined(OS_IRIX) || defined(OS_HPUX) || \
        defined(PYCPP_CYGWIN) || defined(PYCPP_AIX) || defined(OS_QNX) || \
        defined(OS_VMS) || defined(OS_ULTRIX) || defined(OS_RELIANT) || \
        defined(OS_DYNIX) || defined(OS_EMX) || defined(OS_OSF) || \
        defined(OS_DGUX) || defined(OS_LYNX) || defined(OS_SCO) || \
        defined(OS_HURD) || defined(OS_UNIXWARE) || defined(AMDAHL) || \
        defined(PYCPP_AEGIS) || defined(PYCPP_APOLLO) || defined(OS_MINIX) || \
        defined(OS_MPEIX) || defined(OS_VOS) || defined(OS_SVR4) || \
        defined(OS_UNICOS) || defined(OS_UNICOSMP) || defined(OS_ZOS) || \
        defined(OS_UNIX)
#       define PYCPP_OS_POSIX
#   endif
#endif
