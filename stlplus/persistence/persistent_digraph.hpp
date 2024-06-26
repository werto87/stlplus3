#ifndef STLPLUS_PERSISTENT_DIGRAPH
#define STLPLUS_PERSISTENT_DIGRAPH
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence of STLplus digraph

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include "stlplus/containers/digraph.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // digraph

  // exceptions: persistent_dump_failed
  template<typename NT, typename AT, typename DN, typename DA>
  void dump_digraph(dump_context&, const digraph<NT,AT>& data, DN dump_node, DA dump_arc);

  // exceptions: persistent_restore_failed
  template<typename NT, typename AT, typename RN, typename RA>
  void restore_digraph(restore_context&, digraph<NT,AT>& data, RN restore_node, RA restore_arc);

  // node iterator

  // exceptions: persistent_dump_failed
  template<typename NT, typename AT, typename NRef, typename NPtr>
  void dump_digraph_iterator(dump_context& str, const digraph_iterator<NT,AT,NRef,NPtr>& data);

  // exceptions: persistent_restore_failed
  template<typename NT, typename AT, typename NRef, typename NPtr>
  void restore_digraph_iterator(restore_context& str, digraph_iterator<NT,AT,NRef,NPtr>& data);

  // arc iterator

  // exceptions: persistent_dump_failed
  template<typename NT, typename AT, typename NRef, typename NPtr>
  void dump_digraph_arc_iterator(dump_context& str, const digraph_arc_iterator<NT,AT,NRef,NPtr>& data);

  // exceptions: persistent_restore_failed
  template<typename NT, typename AT, typename NRef, typename NPtr>
  void restore_digraph_arc_iterator(restore_context& str, digraph_arc_iterator<NT,AT,NRef,NPtr>& data);

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_digraph.tpp"
#endif
