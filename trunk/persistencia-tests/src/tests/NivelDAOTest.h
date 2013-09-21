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
#include "src/controller/RotadorSistemaCoordenadas.h"
#include "src/figura/Globo.h"
#include "src/figura/Pelota.h"
#include "src/figura/Rueda.h"
#include "src/figura/Bloque.h"
#include "src/figura/Cohete.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Mapa.h"
#include "src/figura/Martillo.h"
#include "src/figura/Resorte.h"

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

	nivel2 = nivelDAO.leerNivel("test02");
	ASSERT_EQ(nivel2->cantidadFiguras(), 1);
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


TEST_F(niveldao_test, test_niveldao_guardar_nivel_grande) {
	Nivel *nivel4 = new Nivel("test04");
	nivel4->agregar(new Globo(10,10, new RotadorSistemaCoordenadas(), 10));
	nivel4->agregar(new Pelota(10,10, new RotadorSistemaCoordenadas(),10));
	nivel4->agregar(new Rueda(10,10, new RotadorSistemaCoordenadas(),10));
	nivel4->agregar(new Bloque(10,10, new RotadorSistemaCoordenadas(), 10,10));
	nivel4->agregar(new Cohete(10,10, new RotadorSistemaCoordenadas(), 10,10));
	nivel4->agregar(new Mapa());
	nivel4->agregar(new Martillo(10,10, new RotadorSistemaCoordenadas(), 10,10));
	nivel4->agregar(new Resorte(10,10, new RotadorSistemaCoordenadas(), 10,10));
	nivelDAO.guardarNivel(nivel4);

	nivel4 = nivelDAO.leerNivel("test04");
	ASSERT_EQ(8, nivel4->cantidadFiguras());

}
