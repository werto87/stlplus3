////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/strings/print_vector.hpp"
#include "stlplus/strings/string_vector.hpp"

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////
  // special case of vector<bool>

  void print_bool_vector(std::ostream& device, const std::vector<bool>& values)
  {
    device << bool_vector_to_string(values);
  }

  ////////////////////////////////////////////////////////////////////////////////

} // end namespace stlplus
