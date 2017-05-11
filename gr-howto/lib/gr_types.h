#ifndef INCLUDED_GR_TYPES_H
#define INCLUDED_GR_TYPES_H
#include <gr_core_api.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <stddef.h>                             // size_t
#include <gr_complex.h>
typedef std::vector<int>                        gr_vector_int;
typedef std::vector<float>                      gr_vector_float;
typedef std::vector<double>                     gr_vector_double;
typedef std::vector<void *>                     gr_vector_void_star;
typedef std::vector<const void *>               gr_vector_const_void_star;

/*
 * #include <config.h> must be placed beforehand 
  * in the source file including gr_types.h for
00042  * the following to work correctly
00043  */
#ifdef HAVE_STDINT_H
#include <stdint.h>
typedef int16_t                 gr_int16;
typedef int32_t                 gr_int32;
typedef int64_t                 gr_int64;
typedef uint16_t                gr_uint16;
typedef uint32_t                gr_uint32;
typedef uint64_t                gr_uint64;
#else
 /*
00054  * Note: these defaults may be wrong on 64-bit systems
00055  */
typedef short                   gr_int16;
typedef int                     gr_int32;
typedef long long               gr_int64;
typedef unsigned short          gr_uint16;
typedef unsigned int            gr_uint32;
typedef unsigned long long      gr_uint64;
#endif  /* HAVE_STDINT_H */
#endif /* INCLUDED_GR_TYPES_H */


