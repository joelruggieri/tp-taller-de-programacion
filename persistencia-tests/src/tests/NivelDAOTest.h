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
#include "src/figura/Triangulo.h"
#include "src/controller/RotadorSistemaCoordenadas.h"

class niveldao_test: public testing::Test {
public:
	NivelDAO nivelDAO;
	virtual void SetUp() {

	}
};


#endif /* NIVELDAOTEST_H_ */



TEST_F(niveldao_test, test_niveldao_leer) {
	AdministradorDeArchivos::registrar("test01.yaml");
	Nivel *nivel1 = nivelDAO.leerNivel("test01");
	ASSERT_STREQ("test01", nivel1->getNombre().c_str());
	ASSERT_EQ(1, nivel1->cantidadFiguras());
}

TEST_F(niveldao_test, test_niveldao_guardar_nuevo) {
	Nivel *nivel2 = new Nivel("test02");
	nivel2->agregar(new Triangulo(0,0,new RotadorSistemaCoordenadas(), 0,1));
	nivelDAO.guardarNivel(nivel2);

	Nivel *nivel3 = nivelDAO.leerNivel("test02");
	ASSERT_EQ(nivel3->cantidadFiguras(), 1);
}


TEST_F(niveldao_test, test_niveldao_sobreescribir_nuevo) {
	Nivel *nivel3 = new Nivel("test03");
	nivel3->agregar(new Triangulo(10,10, new RotadorSistemaCoordenadas(), 10,10));
	nivelDAO.guardarNivel(nivel3);

	Nivel *otroNivel3 = new Nivel("test03");
	otroNivel3->agregar(new Triangulo(20,20,new RotadorSistemaCoordenadas(), 20,20));
	nivelDAO.guardarNivel(otroNivel3);
	otroNivel3 = nivelDAO.leerNivel("test03");
	ASSERT_EQ(1, otroNivel3->cantidadFiguras());
	ASSERT_EQ(nivel3->getNombre(), otroNivel3->getNombre());

}
