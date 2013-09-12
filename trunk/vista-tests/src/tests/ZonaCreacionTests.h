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
//#include "src/controller/zonaDragAndDrop/ZonaCreacion.h"
//#include "src/controller/viewFactory/ViewCuadradoFactory.h"
//#include "src/controller/viewFactory/ViewCirculoFactory.h"
//#include "src/controller/viewFactory/ViewTrianguloFactory.h"
//#include <list>
//using namespace std;
//
//class ZonaCreacionTests : public testing::Test {
//protected:
//	list<ViewFiguraFactory*> factories;
//public:
//	  virtual void SetUp()
//	  {
//		  factories.push_back(new ViewCuadradoFactory());
//		  factories.push_back(new ViewCuadradoFactory);
//		  factories.push_back(new ViewTrianguloFactory());
//
//	  }
//	  virtual void TearDown(){
//
//	  }
//};
//
//#endif /* ZONACREACIONTESTS_H_ */
//TEST_F(ZonaCreacionTests, clickYCreacion) {
//
//	ZonaCreacion zona(&(this->factories), 5.0, 0);
//	FiguraView* vista = zona.click(6.0, 10);
//	// las posiciona automaticamente cada 2 del borde.
//
//	EXPECT_FALSE(vista == NULL);
//	delete vista;
//}
//
//TEST_F(ZonaCreacionTests, clickEnLugarFalso) {
//
//	ZonaCreacion zona(&(this->factories), 5.0, 0);
//	FiguraView* vista = zona.click(6.0, 0);
//	// las posiciona automaticamente cada 2 del borde.
//
//	EXPECT_TRUE(vista == NULL);
//	delete vista;
//}
//
//TEST_F(ZonaCreacionTests, clickSegunda) {
//
//	ZonaCreacion zona(&(this->factories), 5.0, 0);
//	FiguraView* vista = zona.click(6.0, 13);
//	// las posiciona automaticamente cada 2 del borde.
//
//	EXPECT_FALSE(vista == NULL);
//	delete vista;
//}
