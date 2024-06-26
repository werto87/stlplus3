#ifndef STLPLUS_PERSISTENT_CALLBACK
#define STLPLUS_PERSISTENT_CALLBACK
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence for pointers to polymorphic classes using the callback approach.

//   This works on a set of classes. Each subclass has a set of callback
//   (non-method) functions that enable create/dump/restore operations. Each
//   subclass must be registered with the persistence dump/restore context so
//   that the system knows how to handle it.

//   This approach is suited to classes that cannot be modified to add
//   persistence methods. See persistent_interface for a more C++-like way of
//   handling polymorphism.

//   Objects are always dumped/restored as pointers to the superclass T.

//   Multiple pointers to the same object are handled in the same way as for
//   simple pointers

//   Only classes registered with the context can be dumped and restored as
//   polymorphic types - see dump_context::register_callback and
//   restore_context::register_callback. Attempting to use any unrecognised class
//   will throw an exception.

////////////////////////////////////////////////////////////////////////////////

#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // exceptions: persistent_dump_failed
  template<typename T>
  void dump_callback(dump_context&, const T* const data);

  // exceptions: persistent_restore_failed
  template<typename T>
  void restore_callback(restore_context&, T*& data);

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_callback.tpp"
#endif
