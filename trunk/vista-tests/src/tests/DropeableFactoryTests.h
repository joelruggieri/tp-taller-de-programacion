/*
 * ZonaCreacionTests.h
 *
 *  Created on: 31/08/2013
 *      Author: jonathan
 */

#ifndef DROPEABLEFACTORYTESTS_H_
#define DROPEABLEFACTORYTESTS_H_
#include "gtest/gtest.h"
#include "src/vista/modelo/DropeableFactory.h"
class DropeableFactoryTests: public testing::Test {
protected:
	DropeableFactory * factory;
public:
	virtual void SetUp() {
		factory = new DropeableFactory("A");
	}

	virtual void TearDown() {
		delete factory;
	}
};

#endif /* DROPEABLEFACTORYTESTS_H_ */
TEST_F(DropeableFactoryTests, CREACION) {
	Dropeable* drop = factory->crear(10, 10);
	EXPECT_EQ("A", drop->getModelo());
	delete drop;
}
