// This file is part of flcrum.
// Copyright (c) 2016 Jeremy Roberts.  See LICENSE for more information.
//----------------------------------------------------------------------------//

ADD_EXECUTABLE(test_Testing                 test_Testing.cc)
ADD_TEST(test_Testing_pass                  test_Testing 0)
ADD_TEST(test_Testing_fail                  test_Testing 1)
