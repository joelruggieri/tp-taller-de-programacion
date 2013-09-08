/*
 * figuras_test.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef FIGURAS_TEST_H_
#define FIGURAS_TEST_H_

#include "gtest/gtest.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Circulo.h"
#include "src/figura/Figura.h"
#include "src/AdministradorDeArchivos.h"
#include "src/ObjetoDAO.h"
#include <list>

#include "src/Logger.h"

class figuras_test: public testing::Test {
protected:
	AdministradorDeArchivos *archivo;
	ObjetoDAO *dao;
public:
	virtual void SetUp() {
		dao = new ObjetoDAO();
	}
};

#endif /* FIGURAS_TEST_H_ */

TEST_F(figuras_test, test_cuadrados) {
	Triangulo *triangulo = new Triangulo(3.5, 6.5);
	dao->guardar(triangulo);

	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Triangulo *triangulo2 = (Triangulo*) *iter;
	EXPECT_EQ(triangulo2->getX(), triangulo->getX());
	EXPECT_EQ(triangulo2->getY(), triangulo->getY());
	EXPECT_EQ(triangulo2->getRotacion(), triangulo->getRotacion());

//	Logger *l = new Logger("test");
//	l->error("Prueba del logger");
}
