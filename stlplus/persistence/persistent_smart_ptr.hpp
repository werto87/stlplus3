#ifndef STLPLUS_PERSISTENT_SMART_PTR
#define STLPLUS_PERSISTENT_SMART_PTR
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence of STLplus smart_ptr

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include "stlplus/containers/smart_ptr.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // smart_ptr - uses dump/restore_pointer on the contents

  // exceptions: persistent_dump_failed
  template<typename T, typename DE>
  void dump_smart_ptr(dump_context&, const smart_ptr<T>& data, DE dump_element);

  // exceptions: persistent_restore_failed
  template<typename T, typename RE>
  void restore_smart_ptr(restore_context&, smart_ptr<T>& data, RE restore_element);

  // smart_ptr_clone using the polymorphic callback approach - uses dump/restore_callback on the contents

  // exceptions: persistent_dump_failed
  template<typename T>
  void dump_smart_ptr_clone_callback(dump_context&, const smart_ptr_clone<T>& data);

  // exceptions: persistent_restore_failed
  template<typename T>
  void restore_smart_ptr_clone_callback(restore_context&, smart_ptr_clone<T>& data);

  // smart_ptr_clone using the interface approach - uses dump/restore_interface on the contents

  // exceptions: persistent_dump_failed
  template<typename T>
  void dump_smart_ptr_clone_interface(dump_context&, const smart_ptr_clone<T>& data);

  // exceptions: persistent_restore_failed
  template<typename T>
  void restore_smart_ptr_clone_interface(restore_context&, smart_ptr_clone<T>& data);

  // smart_ptr_nocopy is not made persistent because if it is uncopyable, it must be undumpable

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_smart_ptr.tpp"
#endif
