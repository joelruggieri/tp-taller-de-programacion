///*
// * ZonaTableroTests.h
// *
// *  Created on: 31/08/2013
// *      Author: jonathan
// */
//
//#ifndef ZONATABLEROTESTS_H_
//#define ZONATABLEROTESTS_H_
//#include "gtest/gtest.h"
//#include "src/vista/modelo/ZonaTablero.h"
//
//class ZonaTableroTests: public testing::Test {
//protected:
//	ZonaTablero * zona;
//public:
//	virtual void SetUp() {
//		zona = new ZonaTablero(Cuerpo(150,150,300,300));
//	}
//	virtual void TearDown(){
//		delete zona;
//	}
//};
//
//#endif /* ZONATABLEROTESTS_H_ */
//
//TEST_F(ZonaTableroTests, dropTest) {
//	Dropeable * drop = new Dropeable("A", Cuerpo(30,30,10,10,0));
//	bool result =zona->drop(drop);
//	EXPECT_EQ(true, result);
//}
//
//
//TEST_F(ZonaTableroTests, dragAndDropTest) {
//	Dropeable * drop = new Dropeable("A", Cuerpo(30,30,10,10,0));
//	Dropeable * drop2 = new Dropeable("B", Cuerpo(60,60,10,10));
//	zona->drop(drop);
//	zona->drop(drop2);
//	Dropeable* dragueado = zona->drag(30, 30);
//	EXPECT_EQ(drop, dragueado);
//	dragueado = zona->drag(30, 30);
//	EXPECT_EQ(NULL, dragueado);
//	delete drop;
//}
//
