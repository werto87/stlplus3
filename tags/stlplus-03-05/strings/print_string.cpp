////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004-2009
//   License:   BSD License, see ../docs/license.html

////////////////////////////////////////////////////////////////////////////////
#include "print_string.hpp"

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////
  // strings

  void print_string(std::ostream& device, const std::string& value)
  {
    device << value;
  }

} // end namespace stlplus
