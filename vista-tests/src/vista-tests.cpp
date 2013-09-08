//============================================================================
// Name        : vista-tests.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "gtest/gtest.h"
#include "tests/ZonaCreacionTests.h"
#include "tests/ZonaTableroTests.h"
#include "tests/DropeableFactoryTests.h"
#include "tests/EslabonCreacionTests.h"
#include "tests/ZonaJuegoTests.h"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

