#ifndef STLPLUS_PRINT_INF
#define STLPLUS_PRINT_INF
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   String conversion functions for the infinite precision integer type inf

//   The conversion supports all the formatting modes defined on format_types

////////////////////////////////////////////////////////////////////////////////

#include "stlplus/strings/strings_fixes.hpp"
#include "stlplus/portability/inf.hpp"
#include "stlplus/strings/format_types.hpp"
#include <stdexcept>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////

  // exceptions: std::invalid_argument
  void print_inf(std::ostream& device,
                 const inf&,
                 unsigned radix = 10,
                 radix_display_t display = radix_c_style_or_hash,
                 unsigned width = 0);

////////////////////////////////////////////////////////////////////////////////
} // end namespace stlplus


#endif
