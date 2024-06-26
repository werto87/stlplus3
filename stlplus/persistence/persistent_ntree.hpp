#ifndef STLPLUS_PERSISTENT_NTREE
#define STLPLUS_PERSISTENT_NTREE
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence of STLplus ntree

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include "stlplus/containers/ntree.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // ntree

  // exceptions: persistent_dump_failed
  template<typename T, typename D>
  void dump_ntree(dump_context&, const ntree<T>& data, D dump_fn);

  // exceptions: persistent_restore_failed
  template<typename T, typename R>
  void restore_ntree(restore_context&, ntree<T>& data, R restore_fn);

  // iterator

  // exceptions: persistent_dump_failed
  template<typename T, typename TRef, typename TPtr>
  void dump_ntree_iterator(dump_context&, const ntree_iterator<T,TRef,TPtr>&);

  // exceptions: persistent_restore_failed
  template<typename T, typename TRef, typename TPtr>
  void restore_ntree_iterator(restore_context&, ntree_iterator<T,TRef,TPtr>&);

  // prefix iterator

  // exceptions: persistent_dump_failed
  template<typename T, typename TRef, typename TPtr>
  void dump_ntree_prefix_iterator(dump_context&, const ntree_prefix_iterator<T,TRef,TPtr>&);

  // exceptions: persistent_restore_failed
  template<typename T, typename TRef, typename TPtr>
  void restore_ntree_prefix_iterator(restore_context&, ntree_prefix_iterator<T,TRef,TPtr>&);

  // postfix iterator

  // exceptions: persistent_dump_failed
  template<typename T, typename TRef, typename TPtr>
  void dump_ntree_postfix_iterator(dump_context&, const ntree_postfix_iterator<T,TRef,TPtr>&);

  // exceptions: persistent_restore_failed
  template<typename T, typename TRef, typename TPtr>
  void restore_ntree_postfix_iterator(restore_context&, ntree_postfix_iterator<T,TRef,TPtr>&);

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_ntree.tpp"
#endif
