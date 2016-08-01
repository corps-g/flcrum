// This file is part of flcrum.
// Copyright (c) 2016 Jeremy Roberts.  See LICENSE for more information.
//----------------------------------*-C++-*-----------------------------------//

#ifndef flcrum_EXCEPTION_HH
#define flcrum_EXCEPTION_HH

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

namespace flcrum
{

//---------------------------------------------------------------------------//
class Exception: public std::exception
{

public:

  /// Constructs with the default message.
  Exception()
    : d_message("flcrum exception: ")
  {
    /* ... */
  }

  /**
   * @brief Constructs with a provided message
   *
   * @param line 		line of code erring
   * @param file 		file in which error occurs
   * @param message 	the message
   */
  Exception(int line, std::string file, std::string message)
  {
	std::stringstream line_s << i;
    d_message = prepend + "\n"
	          + "           on line: " + line_s.str() + "\n"
	          + "           in file: " + file + "\n"
	          + "           message: " + message;
  }

  /// Destructor
  virtual ~Exception() throw ();

  /// Returns the error message associated with this Exception.
  virtual const char* what() const throw ()
  {
    return d_message.c_str();
  }

private:

  /// The message associated with this exception.
  std::string d_message;

};

/// Easy macro for throwing exceptions.
#define THROW(m) throw flcrum::Exception(__LINE__,__FILE__,m);

} // end namespace flcrum

#endif // flcrum_EXCEPTION_HH
