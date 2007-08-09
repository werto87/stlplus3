/*------------------------------------------------------------------------------

  Author:    Andy Rushton
  Copyright: (c) Andy Rushton, 2004
  License:   BSD License, see ../docs/license.html

  ------------------------------------------------------------------------------*/
#include "persistent_int.hpp"

////////////////////////////////////////////////////////////////////////////////

template<typename K, typename T, typename P, typename DK, typename DT>
void stlplus::dump_map(stlplus::dump_context& context, const std::map<K,T,P>& data, DK key_fn, DT val_fn)
  throw(stlplus::persistent_dump_failed)
{
  stlplus::dump_unsigned(context,data.size());
  for (typename std::map<K,T,P>::const_iterator i = data.begin(); i != data.end(); i++)
  {
    key_fn(context,i->first);
    val_fn(context,i->second);
  }
}

template<typename K, typename T, typename P, typename RK, typename RT>
void stlplus::restore_map(stlplus::restore_context& context, std::map<K,T,P>& data, RK key_fn, RT val_fn)
  throw(stlplus::persistent_restore_failed)
{
  data.clear();
  unsigned size = 0;
  stlplus::restore_unsigned(context,size);
  for (unsigned j = 0; j < size; j++)
  {
    K key;
    key_fn(context,key);
    val_fn(context,data[key]);
  }
}

////////////////////////////////////////////////////////////////////////////////
