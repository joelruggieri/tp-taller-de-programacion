//============================================================================
// Name        : modelo-tests.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "gtest/gtest.h"
#include "mapa/MapaTests.h"
#include "mapa/MotorTests.h"
int main(int argc, char **argv) {
	  ::testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
}
