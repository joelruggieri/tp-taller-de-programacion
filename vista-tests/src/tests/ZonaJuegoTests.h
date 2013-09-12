///*
// * ZonaJuegoTests.h
// *
// *  Created on: 05/09/2013
// *      Author: jonathan
// */
//
//#ifndef ZONAJUEGOTESTS_H_
//#define ZONAJUEGOTESTS_H_
//#include "gtest/gtest.h"
//#include "src/controller/zonaDragAndDrop/ZonaJuego.h"
//
//class ZonaJuegoTests : public testing::Test{
//protected:
//	ZonaJuego * zona;
//public:
//	virtual void SetUp() {
//		zona = new ZonaJuego();
//	}
//	virtual void TearDown() {
//		delete zona;
//	}
//};
//#endif /* ZONAJUEGOTESTS_H_ */
//
//
//
//TEST_F(ZonaJuegoTests, click) {
//	//clickea en una zona vacia
//	FiguraView* drag = zona->click(0, 5);
//	EXPECT_EQ(NULL, drag);
//	//clickea en una factory
//	drag = zona->click(132, 19);
//	EXPECT_TRUE(NULL!= drag);
//	delete drag;
//	//clickea en la segunda factory
//	drag = zona->click(137, 26);
//	EXPECT_TRUE(NULL!= drag);
//	delete drag;
//
//}
