#ifndef STLPLUS_PERSISTENT_BITSET
#define STLPLUS_PERSISTENT_BITSET
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence of STL bitset

////////////////////////////////////////////////////////////////////////////////

#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include <bitset>

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // exceptions: persistent_dump_failed
  template<size_t N>
  void dump_bitset(dump_context&, const std::bitset<N>& data) ;

  // exceptions: persistent_restore_failed
  template<size_t N>
  void restore_bitset(restore_context&, std::bitset<N>& data) ;

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_bitset.tpp"
#endif
