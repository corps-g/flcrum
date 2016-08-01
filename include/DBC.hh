// This file is part of flcrum.
// Copyright (c) 2016 Jeremy Roberts.  See LICENSE for more information.
//----------------------------------*-C++-*-----------------------------------//

#ifndef flcrum_DBC_HH
#define flcrum_DBC_HH

#include "Exception.hh"

#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>

//----------------------------------------------------------------------------//
/**
 *  @page  DBC
 *  @brief Design-By-Contract
 *
 *  DBC is a framework for ensuring consistency between a client's request
 *  and a server's response.  Here, we're not really implementing the full
 *  idea, but we do implement a handful of macros that help imitate DBC:
 *
 *   - Require: precondition upon entering a method that must be satisfied;
 *              if not satisfied, the client is to blame
 *   - Ensure:  postcondition that must be satisfied for the server to be
 *              correct
 *   - Assert:  a general assertion macro
 *   - Insist:  Conditions that must always be true (i.e., these are always
 *              checked)
 *
 *  See the nice tutorial at:
 *    eventhelix.com/realtimemantra/object_oriented/design_by_contract.htm
 *
 */
//----------------------------------------------------------------------------//

namespace flcrum
{

/// Compile time boolean (straight from Alexandrescu's Modern C++ Design
template <bool> struct StaticChecker {StaticChecker(...);};
template <> struct StaticChecker<false> { };

#ifndef NODBC

// DBC Macros
#define Assert(c)                                                              \
	if (!(c)) throw flcrum::Exception("Assertion error",__LINE__,__FILE__,#c);
#define Require(c) Assert(c)
#define Ensure(c)  Assert(c)

// Verbose DBC Macros (i.e. with an additional message)
#define Assertv(c, m)                                                          \
	if (!(c)) throw flcrum::Exception("Assertion error", __LINE__, __FILE__,     \
			                              std::string(#c) + ", " + std::string(m))
#define Requirev(c, m) Assertv(c, m)
#define Ensurev(c, m)  Assertv(c, m)

// Macro for compile time assertions (from Alexandrescu)
#define StaticAssert(c)                                                        \
{                                                                              \
  class ERROR_Compile_time{};                                                  \
  (void)sizeof flcrum::StaticChecker<(c)!=0>((ERROR_Compile_time()));          \
}
#define StaticAssertv(c, m)                                                    \
{                                                                              \
  class ERROR_##m{};                                                           \
  (void)sizeof flcrum::StaticChecker<(c)!=0>((ERROR_##m()) );                  \
}

#else

#define Assert(c)           ((void) 0);
#define Require(c)          ((void) 0);
#define Ensure(c)           ((void) 0);
#define StaticAssert(c)     ((void) 0);
#define Assertv(c, m)       ((void) 0);
#define Requirev(c, m)      ((void) 0);
#define Ensurev(c, m)       ((void) 0);
#define StaticAssertv(c, m) ((void) 0);

#endif

#define Insist(c,m) if (!(c))                       \
{                                                   \
  std::cerr << m << std::endl;                      \
  throw flcrum::Exception("Assertion error", __LINE__, __FILE__, #c); \
}

template <class T>
inline std::string as_string(T v)
{
  std::ostringstream o;
  if (!(o << v))
    THROW("Error converting to string from " + std::string(typeid(T).name()))
  return o.str();
}

#define AsString(c) flcrum::as_string(c)

} // end namespace flcrum

#endif // flcrum_DBC_HH

