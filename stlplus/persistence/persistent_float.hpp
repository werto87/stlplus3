#ifndef STLPLUS_PERSISTENT_FLOAT
#define STLPLUS_PERSISTENT_FLOAT
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Persistence of floating-point types

//   Note: despite years and years of IEEE standardisation, not all
//   architectures use IEEE-standard representations of floating-point numbers.
//   Therefore a binary dump is not necessarily portable between platforms.
//   Solving this is (currently) beyond the scope of the STLplus project.

//   If you want to be strictly portable to all platforms, do not dump/restore float

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistence_fixes.hpp"
#include "stlplus/persistence/persistent_contexts.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  // exceptions: persistent_dump_failed
  void dump_float(dump_context&, const float& data) ;
  // exceptions: persistent_restore_failed
  void restore_float(restore_context&, float& data) ;

  // exceptions: persistent_dump_failed
  void dump_double(dump_context&, const double& data) ;
  // exceptions: persistent_restore_failed
  void restore_double(restore_context&, double& data) ;

} // end namespace stlplus

  ////////////////////////////////////////////////////////////////////////////////
#endif
