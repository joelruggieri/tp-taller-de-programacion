/*
 * RotacionTests.h
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#ifndef ROTACIONTESTS_H_
#define ROTACIONTESTS_H_
#include "src/modelo/Rotacion.h"
class RotacionTests: public testing::Test {
public:
	virtual void SetUp() {
	}
	virtual void TearDown() {

	}
};

#endif /* ROTACIONTESTS_H_ */

TEST_F(RotacionTests, giroIzquierda) {
	Rotacion r(0,0,10,10,0);
	r.rotar(9,10);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(0,10);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(-3,3);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(-3,0);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(-3.0,-2.0);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(0,-3);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(1,-3);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(1,0);
	EXPECT_TRUE(r.getAngulo()< 0);
	r.rotar(1,1);
	EXPECT_TRUE(r.getAngulo()< 0);
}

TEST_F(RotacionTests, giroDerecha) {
	Rotacion r(0,0,10,10,0);
	r.rotar(10,9);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(10,0);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(3,-3);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(0,-3);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(-2,-3);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(-3,0);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(-3,1);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(0,1);
	EXPECT_TRUE(r.getAngulo()> 0);
	r.rotar(1,1);
	EXPECT_TRUE(r.getAngulo()> 0);
}

TEST_F(RotacionTests, tercerCuadranteAmbos) {
	Rotacion r(1,1,0.5,0.6,0);
	r.rotar(0,0);
	EXPECT_TRUE(r.getAngulo()> 0);
}

TEST_F(RotacionTests, cuartoCuadranteAmbos) {
	Rotacion r(1,1,2,0.6,0);
	r.rotar(3,0);
	EXPECT_TRUE(r.getAngulo()> 0);
}
