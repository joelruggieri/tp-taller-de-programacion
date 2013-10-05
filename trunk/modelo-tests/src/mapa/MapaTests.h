/*
 * MapaTests.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef MAPATESTS_H_
#define MAPATESTS_H_
#include "src/figura/Mapa.h"
#include "gtest/gtest.h"
#include "ObjetoCualquiera.h"
class MapaTests: public testing::Test {
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

#endif /* MAPATESTS_H_ */
TEST_F(MapaTests, AgregarFigura) {
//	Triangulo t(1, 1, 0, 10,10);
//	mapa->addObjeto(&t);
//	Figura* figura = mapa->pickUp(2, 2);
//	ASSERT_TRUE(figura != 0);
//
//	figura = mapa->pickUp(1,0);
//	ASSERT_TRUE(figura != 0);
//
//	figura = mapa->pickUp(-4,-4);
//	ASSERT_TRUE(figura != 0);
//
//	figura = mapa->pickUp(6,-4);
//	ASSERT_TRUE(figura != 0);
//
//	figura = mapa->pickUp(-1,10);
//	ASSERT_TRUE(figura != 0);
//
//	figura = mapa->pickUp(10,9);
//	ASSERT_TRUE(figura == 0);

}


TEST_F(MapaTests, DarPaso) {
	Figura * fig = new ObjetoCualquiera(10,10);
	mapa->addFigura(fig);
	for (int i = 0; i < 10; ++i) {
//		mapa->step();
	}
	b2Vec2 pos = fig->getBody()->GetPosition();
	ASSERT_LT(pos.y, 10);
}
