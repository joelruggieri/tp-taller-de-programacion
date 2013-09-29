/*
 * MotorTests.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef MOTORTESTS_H_
#define MOTORTESTS_H_
#include "src/figura/Mapa.h"
#include "src/objeto/Motor.h"
#include "gtest/gtest.h"
class MotorTests: public testing::Test {
protected:
	Mapa * mapa;
public:
	virtual void SetUp() {
		mapa = new Mapa(50,50,100,100);
	}

	virtual void TearDown() {
		delete mapa;
	}
};

#endif /* MOTORTESTS_H_ */
TEST_F(MotorTests, AgregarFigura) {
	Motor m (10,10,0,10,6);
	// los vertices son entonces (5,7)(15,7)(15,13)(5,13)
	mapa->addFigura(&m);
	Figura* figura = mapa->pickUp(10, 10);
	ASSERT_TRUE(figura != 0);

	figura = mapa->pickUp(5,7);
	ASSERT_TRUE(figura != 0);

	figura = mapa->pickUp(15,7);
	ASSERT_TRUE(figura != 0);

	figura = mapa->pickUp(15,13);
	ASSERT_TRUE(figura != 0);

	figura = mapa->pickUp(5,13);
	ASSERT_TRUE(figura != 0);

	figura = mapa->pickUp(15,16);
	ASSERT_TRUE(figura == 0);

}
