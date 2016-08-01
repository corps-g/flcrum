// This file is part of flcrum.
// Copyright (c) 2016 Jeremy Roberts.  See LICENSE for more information.
//----------------------------------*-C++-*----------------------------------//

// LIST OF TEST FUNCTIONS
#define TEST_LIST                \
        FUNC(test_Testing_pass)  \
        FUNC(test_Testing_fail)

#include "TestDriver.hh"
#include <iostream>
#include <cstdlib>

using namespace flcrum;
using namespace std;

int main(int argc, char *argv[])
{
  RUN(argc, argv);
}

//----------------------------------------------------------------------------//
// TEST DEFINITIONS
//----------------------------------------------------------------------------//

int test_Testing_pass(int argc, char *argv[])
{
  TEST(1==1)
  return 0;
}

int test_Testing_fail(int argc, char *argv[])
{
  TESTFALSE(1==0)
  return 0;
}
