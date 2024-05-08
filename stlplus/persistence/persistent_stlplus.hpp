#ifndef STLPLUS_PERSISTENT_STLPLUS
#define STLPLUS_PERSISTENT_STLPLUS
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   Set of persistence routines for the STLplus classes

////////////////////////////////////////////////////////////////////////////////

// can be excluded to break the dependency on the containers library
#ifndef NO_STLPLUS_CONTAINERS
#include "stlplus/persistence/persistent_digraph.hpp"
#include "stlplus/persistence/persistent_foursome.hpp"
#include "stlplus/persistence/persistent_hash.hpp"
#include "stlplus/persistence/persistent_matrix.hpp"
#include "stlplus/persistence/persistent_ntree.hpp"
#include "stlplus/persistence/persistent_smart_ptr.hpp"
#include "stlplus/persistence/persistent_triple.hpp"
#endif

// can be excluded to break the dependency on the portability library
#ifndef NO_STLPLUS_INF
#include "stlplus/persistence/persistent_inf.hpp"
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
