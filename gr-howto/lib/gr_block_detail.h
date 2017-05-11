#ifndef INCLUDED_GR_BLOCK_DETAIL_H
#define INCLUDED_GR_BLOCK_DETAIL_H
 
#include <gr_core_api.h>
#include <gr_runtime_types.h>
#include <gr_tpb_detail.h>
#include <gr_tags.h>
#include <stdexcept>
 
 /*!
00033  * \brief Implementation details to support the signal processing abstraction
00034  * \ingroup internal
00035  *
00036  * This class contains implementation detail that should be "out of sight"
00037  * of almost all users of GNU Radio.  This decoupling also means that
00038  * we can make changes to the guts without having to recompile everything.
00039  */
class GR_CORE_API gr_block_detail {
  public:
  ~gr_block_detail ();
 
   int ninputs () const { return d_ninputs; }
   int noutputs () const { return d_noutputs; }
   bool sink_p () const { return d_noutputs == 0; }
   bool source_p () const { return d_ninputs == 0; }

   void set_done (bool done);
   bool done () const { return d_done; }
 
   void set_input (unsigned int which, gr_buffer_reader_sptr reader);
   gr_buffer_reader_sptr input (unsigned int which)
   {
     if (which >= d_ninputs)
      throw std::invalid_argument ("gr_block_detail::input");
     return d_input[which];
   }
 
   void set_output (unsigned int which, gr_buffer_sptr buffer);
   gr_buffer_sptr output (unsigned int which)
   {
     if (which >= d_noutputs)
       throw std::invalid_argument ("gr_block_detail::output");
     return d_output[which];
   }
 
   /*!
    * \brief Tell the scheduler \p how_many_items of input stream \p which_input were consumed.
00070    */
   void consume (int which_input, int how_many_items);
 
   /*!
00074    * \brief Tell the scheduler \p how_many_items were consumed on each input stream.
00075    */
   void consume_each (int how_many_items);
 
   /*!
    * \brief Tell the scheduler \p how_many_items were produced on output stream \p which_output.
00080    */
   void produce (int which_output, int how_many_items);
 
   /*!
00084    * \brief Tell the scheduler \p how_many_items were produced on each output stream.
00085    */
   void produce_each (int how_many_items);

   /*!
00089    * Accept msg, place in queue, arrange for thread to be awakened if it's not already.
00090    */
   void _post(pmt::pmt_t msg);
 
   // Return the number of items read on input stream which_input
   uint64_t nitems_read(unsigned int which_input);
 
   // Return the number of items written on output stream which_output
   uint64_t nitems_written(unsigned int which_output);
 

   /*!
00101    * \brief  Adds a new tag to the given output stream.
00102    *
00103    * This takes the input parameters and builds a PMT tuple
00104    * from it. It then calls gr_buffer::add_item_tag(pmt::pmt_t t),
00105    * which appends the tag onto its deque.
00106    *
00107    * \param which_output  an integer of which output stream to attach the tag
00108    * \param tag the tag object to add
00109    */
  void add_item_tag(unsigned int which_output, const gr_tag_t &tag);
 
   /*!
00113    * \brief Given a [start,end), returns a vector of all tags in the range.
00114    *
00115    * Pass-through function to gr_buffer_reader to get a vector of tags
00116    * in given range. Range of counts is from start to end-1.
00117    *
00118    * Tags are tuples of:
00119    *      (item count, source id, key, value)
00120    *
00121    * \param v            a vector reference to return tags into
00122    * \param which_input  an integer of which input stream to pull from
00123    * \param abs_start    a uint64 count of the start of the range of interest
00124    * \param abs_end      a uint64 count of the end of the range of interest
00125    */
  void get_tags_in_range(std::vector<gr_tag_t> &v,
                         unsigned int which_input,
                          uint64_t abs_start,
                          uint64_t abs_end);
 
   /*!
00132    * \brief Given a [start,end), returns a vector of all tags in the range
00133    * with a given key.
00134    *
00135    * Calls get_tags_in_range(which_input, abs_start, abs_end) to get a vector of
00136    * tags from the buffers. This function then provides a secondary filter to
00137    * the tags to extract only tags with the given 'key'.
00138    *
00139    * Tags are tuples of:
00140    *      (item count, source id, key, value)
00141    *
00142    * \param v            a vector reference to return tags into
00143    * \param which_input  an integer of which input stream to pull from
00144    * \param abs_start    a uint64 count of the start of the range of interest
00145    * \param abs_end      a uint64 count of the end of the range of interest
00146    * \param key          a PMT symbol to select only tags of this key
00147    */
  void get_tags_in_range(std::vector<gr_tag_t> &v,
                         unsigned int which_input,
                          uint64_t abs_start,
                          uint64_t abs_end,
                          const pmt::pmt_t &key);
 
   gr_tpb_detail                      d_tpb;     // used by thread-per-block scheduler
   int                                d_produce_or;
 
   // ----------------------------------------------------------------------------
 
 private:
   unsigned int                       d_ninputs;
   unsigned int                       d_noutputs;
   std::vector<gr_buffer_reader_sptr> d_input;
   std::vector<gr_buffer_sptr>        d_output;
   bool                               d_done;
 
   gr_block_detail (unsigned int ninputs, unsigned int noutputs);
 
   friend struct gr_tpb_detail;
 
   friend GR_CORE_API gr_block_detail_sptr
   gr_make_block_detail (unsigned int ninputs, unsigned int noutputs);
 };
 
 GR_CORE_API gr_block_detail_sptr
 gr_make_block_detail (unsigned int ninputs, unsigned int noutputs);
 
 GR_CORE_API long
 gr_block_detail_ncurrently_allocated ();
 
#endif /* INCLUDED_GR_BLOCK_DETAIL_H */


