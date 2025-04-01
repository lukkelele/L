#pragma once

#include <cassert>

#ifdef L_DEBUG
#define L_ASSERT(_COND, ...)  assert(_COND)
#else
#define L_ASSERT(_COND, ...)  (void)(_COND)
#endif