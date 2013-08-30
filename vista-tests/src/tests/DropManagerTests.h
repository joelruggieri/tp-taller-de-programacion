/*
 * ManagerTests.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef MANAGERTESTS_H_
#define MANAGERTESTS_H_

#include "gtest/gtest.h"
#include "src/vista/modelo/DropManager.h"
class DropManagerTests : public testing::Test {
public:
	  virtual void SetUp()
	  {
	  }

};

TEST_F(DropManagerTests, clickYCreacion) {
	DropManager manager;
	Dropeable * drop1= manager.drag(30,30);
	EXPECT_EQ("A", drop1->getModelo());
	delete drop1;
	drop1= manager.drag(95,30);
	EXPECT_EQ("B", drop1->getModelo());
	delete drop1;

	drop1= manager.drag(160,55);
	EXPECT_EQ("JONY", drop1->getModelo());
	delete drop1;

	drop1= manager.drag(30,30);
	EXPECT_EQ(NULL, drop1);

	drop1 = manager.drag(200,200);
	EXPECT_EQ(NULL, drop1);
}


#endif /* MANAGERTESTS_H_ */
