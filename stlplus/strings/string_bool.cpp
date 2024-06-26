////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   use the unsigned short representation for bool

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/strings/string_bool.hpp"
#include "stlplus/strings/string_int.hpp"

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////

  std::string bool_to_string(bool i, unsigned radix, radix_display_t display, unsigned width)
  {
    return unsigned_short_to_string((unsigned short)i, radix, display, width);
  }

  ////////////////////////////////////////////////////////////////////////////////

  bool string_to_bool(const std::string& str, unsigned radix)
  {
    return string_to_unsigned_short(str, radix) != 0;
  }

  ////////////////////////////////////////////////////////////////////////////////

} // end namespace stlplus
