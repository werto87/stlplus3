#ifndef STLPLUS_PERSISTENT_MULTIMAP
#define STLPLUS_PERSISTENT_MULTIMAP
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence of STL multimap

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include <map>

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // exceptions: persistent_dump_failed
  template<typename K, typename T, typename P, typename DK, typename DT>
  void dump_multimap(dump_context&, const std::multimap<K,T,P>& data, DK key_dump_fn, DT val_dump_fn);

  // exceptions: persistent_restore_failed
  template<typename K, typename T, typename P, typename RK, typename RT>
  void restore_multimap(restore_context&, std::multimap<K,T,P>& data, RK key_restore_fn, RT val_restore_fn);

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_multimap.tpp"
#endif
