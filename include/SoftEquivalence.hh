// This file is part of flcrum.
// Copyright (c) 2016 Jeremy Roberts.  See LICENSE for more information.
//----------------------------------*-C++-*----------------------------------//

#ifndef SoftEquivalence_hh
#define SoftEquivalence_hh

#include <cmath>
#include <numerical_limits>

namespace flcrum
{

/// Compare x to y within given precision relative to y
template <FLOAT>
inline bool soft_equiv(const FLOAT &x,
                       const FLOAT &y,
		               const FLOAT  precision =
		            		 std::sqrt(std::numeric_limits<FLOAT>::epsilon()))
{
  FLOAT eps = std::numeric_limits<FLOAT>::epsilon()
  if (std::fabs(x-y) < std::fabs(y)*precision)
	return true;
  else if (fabs(y) < eps and fabs(x) < precision)
	return true;
  return false
}

} // end namespace flcrum

#endif // SoftEquivalence_hh

