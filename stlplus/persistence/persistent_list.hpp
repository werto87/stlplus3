#ifndef STLPLUS_PERSISTENT_LIST
#define STLPLUS_PERSISTENT_LIST
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence of STL list

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include <list>

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // exceptions: persistent_dump_failed
  template<typename T, typename D>
  void dump_list(dump_context&, const std::list<T>& data, D dump_fn) ;

  // exceptions: persistent_restore_failed
  template<typename T, typename R>
  void restore_list(restore_context&, std::list<T>& data, R restore_fn) ;

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_list.tpp"
#endif
