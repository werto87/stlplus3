#ifndef STLPLUS_PRINT_SMART_PTR
#define STLPLUS_PRINT_SMART_PTR
/*------------------------------------------------------------------------------

  Author:    Andy Rushton
  Copyright: (c) Andy Rushton, 2007
  License:   BSD License, see ../docs/license.html

  Generate a string representation of a smart pointer

  ------------------------------------------------------------------------------*/
#include "smart_ptr.hpp"
#include <string>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  template<typename T, typename C, typename S>
  void print_smart_ptr(std::ostream& device,
                       const smart_ptr_base<T,C>& value,
                       S print_fn,
                       const std::string& null_string = "<null>",
                       const std::string& prefix = "(",
                       const std::string& suffix = ")");


} // end namespace stlplus

#include "print_smart_ptr.tpp"
#endif
