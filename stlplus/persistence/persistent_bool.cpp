////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/persistence/persistent_bool.hpp"

////////////////////////////////////////////////////////////////////////////////

// bool is dumped and restored as an unsigned char
void stlplus::dump_bool(stlplus::dump_context& context, const bool& data)
{
  context.put((unsigned char)data);
}

void stlplus::restore_bool(restore_context& context, bool& data)
{
  data = context.get() != 0;
}

////////////////////////////////////////////////////////////////////////////////
