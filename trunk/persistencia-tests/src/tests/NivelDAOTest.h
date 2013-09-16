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
public:
	virtual void SetUp() {

	}
};


#endif /* NIVELDAOTEST_H_ */

#include "src/figura/Circulo.h"

TEST_F(niveldao_test, test_niveldao) {
	Nivel n(1);
	n.agregar(new Circulo(1.0, 2.0, 3.0));
	n.agregar(new Circulo(1.0, 2.0, 3.0));
	nivelDAO.guardarNivel(n);
}

TEST_F(niveldao_test, test_niveldao_leer) {
	Nivel *n = nivelDAO.leerNivel(1);
	ASSERT_EQ(n->getNumero(), 1);
	ASSERT_EQ(n->cantidadFiguras(), 0);
}
