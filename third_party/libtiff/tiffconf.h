/* libtiff/tiffconf.h.  Generated by configure.  */
/*
  Configuration defines for installed libtiff.
  This file maintained for backward compatibility. Do not use definitions
  from this file in your programs.
*/
#ifndef _TIFFCONF_
#define _TIFFCONF_

#include "core/fxcrt/fx_system.h"

//NOTE: The tiff codec requires an ANSI C compiler environment for building and 
//		presumes an ANSI C environment for use.

# define HAVE_SYS_TYPES_H 1
# define HAVE_FCNTL_H 1

/* Compatibility stuff. */

/* Define to 1 if you have the <assert.h> header file. */
#define HAVE_ASSERT_H 1

/* Define as 0 or 1 according to the floating point format suported by the
   machine */
#define HAVE_IEEEFP 1

/* Define to 1 if you have the <string.h> header file. */
//#define HAVE_STRING_H 1
//fx_system.h already include the string.h in ANSIC

/* Define to 1 if you have the <search.h> header file. */
#if _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_ && _MSC_VER >= 1900
// search.h is always available in VS 2015 and above, and may be
// available in earlier versions.
#define HAVE_SEARCH_H 1
#endif

/* The size of a `int'. */
/* According typedef int  int32_t; in the fx_system.h*/
#define SIZEOF_INT 4

/* Sunliang.Liu 20110325. We should config the correct long size for tif 
   fax4decode optimize in tif_fax3.c  -- Linux64 decode issue. 
   TESTDOC: Bug #23661 - z1.tif. */
#if _FX_CPU_ == _FX_WIN64_ || _FX_CPU_ == _FX_X64_ || _FX_CPU_ == _FX_IA64_
/* The size of `unsigned long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG 8
#else
#define SIZEOF_UNSIGNED_LONG 4
#endif

/* The size of void*. */
#ifdef __LP64__
#define SIZEOF_VOIDP 8
#else
#define SIZEOF_VOIDP 4
#endif

/* Signed 8-bit type */
#define TIFF_INT8_T signed char

/* Unsigned 8-bit type */
#define TIFF_UINT8_T unsigned char

/* Signed 16-bit type */
#define TIFF_INT16_T signed short

/* Unsigned 16-bit type */
#define TIFF_UINT16_T unsigned short

/* Signed 32-bit type */
#define TIFF_INT32_T signed int

/* Unsigned 32-bit type */
#define TIFF_UINT32_T unsigned int

/* Signed 32-bit type formatter */
#define TIFF_INT32_FORMAT "%d"

/* Unsigned 32-bit type formatter */
#define TIFF_UINT32_FORMAT "%u"

#ifdef _MSC_VER		// windows

/* Signed 64-bit type formatter */
#define TIFF_INT64_FORMAT "%I64d"

/* Unsigned 64-bit type formatter */
#define TIFF_UINT64_FORMAT "%I64u"

/* Signed 64-bit type */
#define TIFF_INT64_T signed __int64

/* Unsigned 64-bit type */
#define TIFF_UINT64_T unsigned __int64

#else						// linux/unix

#if 0 //_FX_CPU_ == _FX_X64_	// linux/unix 64

/* Signed 64-bit type formatter */
#define TIFF_INT64_FORMAT "%ld"

/* Unsigned 64-bit type formatter */
#define TIFF_UINT64_FORMAT "%lu"

/* Signed 64-bit type */
#define TIFF_INT64_T signed long

#else						// linux/unix 32

/* Signed 64-bit type formatter */
#define TIFF_INT64_FORMAT "%lld"

/* Unsigned 64-bit type formatter */
#define TIFF_UINT64_FORMAT "%llu"

/* Signed 64-bit type */
#define TIFF_INT64_T signed long long

#endif						// end _FX_CPU_

/* Unsigned 64-bit type */
#define TIFF_UINT64_T unsigned long long

#endif


/* Signed size type */
#ifdef _MSC_VER

#if defined(_WIN64)
#define TIFF_SSIZE_T signed __int64
#else
#define TIFF_SSIZE_T signed int
#endif

#else

#define TIFF_SSIZE_T signed long

#endif

/* Signed size type formatter */
#if defined(_WIN64)
#define TIFF_SSIZE_FORMAT "%I64d"
#else
#define TIFF_SSIZE_FORMAT "%ld"
#endif

/* Pointer difference type */
#ifdef _MSC_VER
#define TIFF_PTRDIFF_T long
#else
#define TIFF_PTRDIFF_T ptrdiff_t
#endif

/* Signed 64-bit type */
/*#define TIFF_INT64_T signed __int64*/

/* Unsigned 64-bit type */
/*#define TIFF_UINT64_T unsigned __int64*/

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
# ifndef inline
#  define inline __inline
# endif
#endif

#define lfind _lfind

#define BSDTYPES

/* Set the native cpu bit order (FILLORDER_LSB2MSB or FILLORDER_MSB2LSB) */
#define HOST_FILLORDER FILLORDER_LSB2MSB

/* Native cpu byte order: 1 if big-endian (Motorola) or 0 if little-endian
   (Intel) */
#if _FX_ENDIAN_ == _FX_BIG_ENDIAN_
# define HOST_BIGENDIAN 1
#else
# define HOST_BIGENDIAN 0
#endif

/* Support CCITT Group 3 & 4 algorithms */
#define CCITT_SUPPORT 1

/* Support JPEG compression (requires IJG JPEG library) */
#define JPEG_SUPPORT 1

/* Support LogLuv high dynamic range encoding */
#define LOGLUV_SUPPORT 1

/* Support LZW algorithm */
#define LZW_SUPPORT 1

/* Support NeXT 2-bit RLE algorithm */
#define NEXT_SUPPORT 1

/* Support Old JPEG compresson (read contrib/ojpeg/README first! Compilation
   fails with unpatched IJG JPEG library) */
#define  OJPEG_SUPPORT	1

/* Support Macintosh PackBits algorithm */
#define PACKBITS_SUPPORT 1

/* Support Pixar log-format algorithm (requires Zlib) */
#define PIXARLOG_SUPPORT 1

/* Support ThunderScan 4-bit RLE algorithm */
#define THUNDER_SUPPORT 1

/* Support Deflate compression */
#define ZIP_SUPPORT 1

/* Support strip chopping (whether or not to convert single-strip uncompressed
   images to mutiple strips of ~8Kb to reduce memory usage) */
#define STRIPCHOP_DEFAULT TIFF_STRIPCHOP

/* Enable SubIFD tag (330) support */
#define SUBIFD_SUPPORT 1

/* Treat extra sample as alpha (default enabled). The RGBA interface will
   treat a fourth sample with no EXTRASAMPLE_ value as being ASSOCALPHA. Many
   packages produce RGBA files but don't mark the alpha properly. */
#define DEFAULT_EXTRASAMPLE_AS_ALPHA 1

/* Pick up YCbCr subsampling info from the JPEG data stream to support files
   lacking the tag (default enabled). */
#define CHECK_JPEG_YCBCR_SUBSAMPLING 1

/* Support MS MDI magic number files as TIFF */
#define MDI_SUPPORT 1

/*
 * Feature support definitions.
 * XXX: These macros are obsoleted. Don't use them in your apps!
 * Macros stays here for backward compatibility and should be always defined.
 */
#define COLORIMETRY_SUPPORT
#define YCBCR_SUPPORT
#define CMYK_SUPPORT
#define ICC_SUPPORT
#define PHOTOSHOP_SUPPORT
#define IPTC_SUPPORT

#endif /* _TIFFCONF_ */
