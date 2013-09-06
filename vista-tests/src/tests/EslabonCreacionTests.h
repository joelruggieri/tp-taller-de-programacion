///*
// * EslabonCreacionTests.h
// *
// *  Created on: 31/08/2013
// *      Author: jonathan
// */
//
//#ifndef ESLABONCREACIONTESTS_H_
//#define ESLABONCREACIONTESTS_H_
//#include "gtest/gtest.h"
//#include "src/vista/modelo/EslabonCreacion.h"
//#include "src/vista/modelo/DropeableFactory.h"
//#include "src/vista/modelo/Dropeable.h"
//class EslabonCreacionTests: public testing::Test {
//protected:
//	EslabonCreacion* eslabon1;
//public:
//	virtual void SetUp() {
//		DropeableFactory* factory= new DropeableFactory("A");
//		eslabon1 = new EslabonCreacion(factory,Cuerpo(50,50,100,100), 2);
//	}
//
//	virtual void TearDown() {
//		delete eslabon1;
//	}
//};
//
//#endif /* ESLABONCREACIONTESTS_H_ */
//
//
//TEST_F(EslabonCreacionTests, creacionSimple) {
//	Dropeable* dropeable = eslabon1->antender(50, 50);
//	EXPECT_EQ("A", dropeable->getModelo());
//	delete dropeable;
//}
//
//TEST_F(EslabonCreacionTests, creacionFueraLimite) {
//	Dropeable* dropeable = eslabon1->antender(50, 50);
//	delete dropeable;
//	dropeable = eslabon1->antender(50, 50);
//	delete dropeable;
//	dropeable = eslabon1->antender(50, 50);
//	EXPECT_EQ(NULL, dropeable);
//}
//
//TEST_F(EslabonCreacionTests, clickNoAtendido) {
//	Dropeable* dropeable = eslabon1->antender(500, 50);
//	EXPECT_EQ(NULL, dropeable);
//}
//
//TEST_F(EslabonCreacionTests, pasarAOtroEslabon) {
//	DropeableFactory * factory = new DropeableFactory("B");
//	EslabonCreacion * eslabon2 = new EslabonCreacion(factory,Cuerpo(150,50,100,100,0),1);
//	eslabon1->setSiguiente(eslabon2);
//	Dropeable* dropeable = eslabon1->antender(180, 60);
//	EXPECT_EQ("B", dropeable->getModelo());
//}
