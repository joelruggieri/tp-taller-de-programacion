/*
 * main.cpp
 *
 *  Created on: 09/09/2013
 *      Author: joel
 */

#include "ObjetoDAO.h"
#include <list>
#include <iostream>
#include "gtest/gtest.h"
#include "PersistenciaTests.h"

int main(int argc, char **argv){

	 ::testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
}
