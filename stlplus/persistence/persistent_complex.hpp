#ifndef STLPLUS_PERSISTENT_COMPLEX
#define STLPLUS_PERSISTENT_COMPLEX
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Set of persistence routines for the STL classes

////////////////////////////////////////////////////////////////////////////////

#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"
#include <complex>

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // exceptions: persistent_dump_failed
  template<typename T, typename D>
  void dump_complex(dump_context&, const std::complex<T>& data, D dump_fn) ;

  // exceptions: persistent_restore_failed
  template<typename T, typename R>
  void restore_complex(restore_context&, std::complex<T>& data, R restore_fn) ;

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#include "persistent_complex.tpp"
#endif
