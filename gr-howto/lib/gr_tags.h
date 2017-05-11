#ifndef INCLUDED_GR_TAGS_H
#define INCLUDED_GR_TAGS_H
#include <gnuradio/api.h>
#include <pmt/pmt.h>
 
namespace gr {
 
 struct GR_RUNTIME_API tag_t
  {
  //! the item \p tag occurred at (as a uint64_t)
  uint64_t offset;
 
  //! the key of \p tag (as a PMT symbol)
  pmt::pmt_t key;
 
  //! the value of \p tag (as a PMT)
  pmt::pmt_t value;
 
  //! the source ID of \p tag (as a PMT)
  pmt::pmt_t srcid;
 
  //! Used by gr_buffer to mark a tagged as deleted by a specific block. You can usually ignore this.
  std::vector<long> marked_deleted;
 
  /*!
 49  * Comparison function to test which tag, \p x or \p y, came
 50  * first in time
 51  */
  static inline bool offset_compare(const tag_t &x,
  const tag_t &y)
  {
  return x.offset < y.offset;
  }
 
 inline bool operator == (const tag_t &t) const
  {
  return (t.key == key) && (t.value == value) && \
  (t.srcid == srcid) && (t.offset == offset);
 }
 };
 
 } /* namespace gr */
 
#endif /*INCLUDED_GR_TAGS_H*/

