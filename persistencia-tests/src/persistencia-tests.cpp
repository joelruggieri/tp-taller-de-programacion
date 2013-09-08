/*
 * persistencia-tests.cpp
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#include "gtest/gtest.h"
#include "tests/figuras_test.h"
#include "tests/logger_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
