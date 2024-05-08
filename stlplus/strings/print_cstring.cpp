////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/strings/print_cstring.hpp"

namespace stlplus
{

  void print_cstring(std::ostream& device, const char* value)
  {
    device << value;
  }

} // end namespace stlplus
