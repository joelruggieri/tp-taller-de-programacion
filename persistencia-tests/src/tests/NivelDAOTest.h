/*
 * NivelDAOTest.h
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#ifndef NIVELDAOTEST_H_
#define NIVELDAOTEST_H_

#include "src/NivelDAO.h"

class niveldao_test: public testing::Test {
protected:
	NivelDAO nivelDAO;
	Nivel *n;
public:
	virtual void SetUp() {

	}
};


#endif /* NIVELDAOTEST_H_ */

#include "src/figura/Circulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Triangulo.h"

TEST_F(niveldao_test, test_niveldao) {
	n = new Nivel(1);
	n->agregar(new Circulo(1.0, 25.0, 3.0));
	n->agregar(new Cuadrado(12.0, 2.0, 23.0, 47.0));
	n->agregar(new Triangulo(15.0, 52.0, 3.0, 1.0));

	n->agregar(new Circulo(81.0, 24.0, 63.0));
	n->agregar(new Cuadrado(1.0, 2.0, 13.0, 4.0));
	n->agregar(new Triangulo(71.0, 2.0, 3.0, 1.0));


	n->agregar(new Circulo(31.0, 32.0, 3.0));
	n->agregar(new Circulo(16.0, 26.0, 63.0));
	n->agregar(new Circulo(11.0, 26.0, 83.0));

	ASSERT_EQ(n->cantidadFiguras(), 9);

	nivelDAO.guardarNivel(n);
}

TEST_F(niveldao_test, test_niveldao_leer) {

	Nivel *n2 = nivelDAO.leerNivel(1);
	ASSERT_EQ(n2->getNumero(), n->getNumero());
	ASSERT_EQ(n2->cantidadFiguras(), n->cantidadFiguras());
}

TEST_F(niveldao_test, test_niveldao_guardar_nuevo) {

	Nivel *n3 = new Nivel(2);
	n3->agregar(new Circulo(0,0,0));
	nivelDAO.guardarNivel(n3);

	n3 = nivelDAO.leerNivel(2);
	ASSERT_EQ(n3->cantidadFiguras(), 1);
}


TEST_F(niveldao_test, test_niveldao_sobreescribir_nuevo) {
	Nivel *n3 = new Nivel(3);
	n3->agregar(new Circulo(10,10,10));
	nivelDAO.guardarNivel(n3);

	Nivel *n4 = new Nivel(3);
	n4->agregar(new Cuadrado(10,10,20,10));
	nivelDAO.guardarNivel(n4);
	ASSERT_EQ(n3->cantidadFiguras(), n4->cantidadFiguras());
	ASSERT_EQ(n3->getNumero(), n4->getNumero());
}
