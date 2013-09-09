/*
 * PersistenciaTests.h
 *
 *  Created on: 09/09/2013
 *      Author: joel
 */

#ifndef PERSISTENCIATESTS_H_
#define PERSISTENCIATESTS_H_
#include "ObjetoDAO.h"
#include "gtest/gtest.h"


class PersistenciaTests: public ::testing::Test {
protected:
	Cuadrado* unCuadrado;
	Circulo* unCirculo;
	Triangulo* unTriangulo;

public:
	virtual void SetUp() {
			unCuadrado = new Cuadrado(10.56,6.5,2,8.9);
			unCirculo = new Circulo(3.81,5.80,6.7);
			unTriangulo = new Triangulo(2,4.15);
		}
		virtual void TearDown() {
				delete unCuadrado;
				delete unCirculo;
				delete unTriangulo;
			}
};

TEST_F(PersistenciaTests,Serializacion_figuras){
	ObjetoDAO* dao = new ObjetoDAO();
	dao->guardar(unCuadrado);
	dao->guardar(unCirculo);
	std::list<Figura*> figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter;
	iter = figuras.begin();
	Figura* unaFigura = *iter;
	EXPECT_EQ(strcmp(typeid(*unaFigura).name(),"7Circulo"),0);
	iter.operator ++();
	unaFigura = *iter;
	EXPECT_EQ(strcmp(typeid(*unaFigura).name(),"8Cuadrado"),0);
	delete dao;

}


#endif /* PERSISTENCIATESTS_H_ */
