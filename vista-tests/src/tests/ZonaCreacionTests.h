///*
// * ZonaCreacionTests.h
// *
// *  Created on: 31/08/2013
// *      Author: jonathan
// */
//
//#ifndef ZONACREACIONTESTS_H_
//#define ZONACREACIONTESTS_H_
//#include "gtest/gtest.h"
//#include "src/vista/modelo/ZonaCreacion.h"
//class ZonaCreacionTests : public testing::Test {
//public:
//	  virtual void SetUp()
//	  {
//	  }
//
//};
//
//#endif /* ZONACREACIONTESTS_H_ */
//TEST_F(ZonaCreacionTests, clickYCreacion) {
//	ZonaCreacion zona(Cuerpo(150,150,300,300));
//	Dropeable * drop1= zona.drag(30,30);
//	EXPECT_EQ("A", drop1->getModelo());
//	delete drop1;
//	drop1= zona.drag(95,30);
//	EXPECT_EQ("B", drop1->getModelo());
//	delete drop1;
//
//	drop1= zona.drag(160,55);
//	EXPECT_EQ("JONY", drop1->getModelo());
//	delete drop1;
//
//	drop1= zona.drag(30,30);
//	EXPECT_EQ(NULL, drop1);
//
//	drop1 = zona.drag(200,200);
//	EXPECT_EQ(NULL, drop1);
//}
//
//
//TEST_F(ZonaCreacionTests, crearConScroll) {
//	ZonaCreacion zona(Cuerpo(150,150,300,300,0));
//	zona.setScrollY(25);
//	Dropeable * drop1= zona.drag(30,5);
//	EXPECT_EQ("A", drop1->getModelo());
//	delete drop1;
//	drop1= zona.drag(95,5);
//	EXPECT_EQ("B", drop1->getModelo());
//	delete drop1;
//
//	drop1= zona.drag(160,30);
//	EXPECT_EQ("JONY", drop1->getModelo());
//	delete drop1;
//
//	drop1= zona.drag(30,5);
//	EXPECT_EQ(NULL, drop1);
//
//	drop1 = zona.drag(200,175);
//	EXPECT_EQ(NULL, drop1);
//}
