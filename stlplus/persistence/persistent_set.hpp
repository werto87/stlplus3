#ifndef STLPLUS_PERSISTENT_SET
#define STLPLUS_PERSISTENT_SET
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Set of persistence routines for the STL classes

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include <set>

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // exceptions: persistent_dump_failed
  template<typename K, typename P, typename D>
  void dump_set(dump_context&, const std::set<K,P>& data, D dump_fn);

  // exceptions: persistent_restore_failed
  template<typename K, typename P, typename R>
  void restore_set(restore_context&, std::set<K,P>& data, R restore_fn);

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistent_set.tpp"
#endif
