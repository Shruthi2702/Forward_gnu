#ifndef INCLUDED_GR_CORE_API_H
#define INCLUDED_GR_CORE_API_H
 
#include <attributes.h>
 
#ifdef gnuradio_core_EXPORTS
#  define GR_CORE_API __GR_ATTR_EXPORT
#else
#  define GR_CORE_API __GR_ATTR_IMPORT
#endif
 
#endif /* INCLUDED_GR_CORE_API_H */
