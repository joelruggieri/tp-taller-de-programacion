/*
 * NivelDAOTest.h
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#ifndef NIVELDAOTEST_H_
#define NIVELDAOTEST_H_

#include "src/NivelDAO.h"
#include "src/Archivo.h"
#include "src/figura/Circulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Triangulo.h"

class niveldao_test: public testing::Test {
public:
	NivelDAO nivelDAO;
	Nivel *nivel;
	virtual void SetUp() {

		nivel = new Nivel(1);
		nivel->agregar(new Circulo(1.0, 25.0, 3.0));
		nivel->agregar(new Cuadrado(12.0, 2.0, 23.0, 47.0));
		nivel->agregar(new Triangulo(15.0, 52.0, 3.0, 1.0));

		nivel->agregar(new Circulo(81.0, 24.0, 63.0));
		nivel->agregar(new Cuadrado(1.0, 2.0, 13.0, 4.0));
		nivel->agregar(new Triangulo(71.0, 2.0, 3.0, 1.0));

		nivel->agregar(new Circulo(31.0, 32.0, 3.0));
		nivel->agregar(new Circulo(16.0, 26.0, 63.0));
		nivel->agregar(new Circulo(11.0, 26.0, 83.0));
	}
};


#endif /* NIVELDAOTEST_H_ */



TEST_F(niveldao_test, test_niveldao_leer) {
	Nivel *nivel1 = nivelDAO.leerNivel(1);
	ASSERT_EQ(nivel1->getNumero(), nivel->getNumero());
	ASSERT_EQ(nivel1->cantidadFiguras(), nivel->cantidadFiguras());
}

TEST_F(niveldao_test, test_niveldao_guardar_nuevo) {
	Nivel *nivel2 = new Nivel(2);
	nivel2->agregar(new Circulo(0,0,0));
	nivelDAO.guardarNivel(nivel2);

	nivel2 = nivelDAO.leerNivel(2);
	ASSERT_EQ(nivel2->cantidadFiguras(), 1);
}


TEST_F(niveldao_test, test_niveldao_sobreescribir_nuevo) {
	Nivel *nivel3 = new Nivel(3);
	nivel3->agregar(new Circulo(10,10,10));
	nivelDAO.guardarNivel(nivel3);

	Nivel *otroNivel3 = new Nivel(3);
	otroNivel3->agregar(new Cuadrado(10,10,20,10));
	nivelDAO.guardarNivel(otroNivel3);
	otroNivel3 = nivelDAO.leerNivel(3);
	ASSERT_EQ(1, otroNivel3->cantidadFiguras());
	ASSERT_EQ(nivel3->getNumero(), otroNivel3->getNumero());
}
