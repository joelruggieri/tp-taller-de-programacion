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
#include <assert.h>
#include <list>
#include "src/AdministradorDeLoggers.h"


class figuras_test: public testing::Test {
protected:
	ObjetoDAO *dao;
public:
	virtual void SetUp() {
		dao = new ObjetoDAO();
	}

	virtual void TearDown(){
		delete dao;
	}
};

#endif /* FIGURAS_TEST_H_ */

TEST_F(figuras_test,test_archivo_no_creardo_excepcion){
	bool exc = false;
	Triangulo *triangulo = new Triangulo(3.5, 6.5,0,0);
	try{
		ObjetoDAO *dao2 = new ObjetoDAO("config2.yaml");
		//dao->guardar(triangulo);
		delete dao2;
	}catch (YAML::BadFile& e){
		exc = true;
	}
	EXPECT_EQ(exc,false);


}


TEST_F(figuras_test, test_triangulos) {
	Triangulo *triangulo = new Triangulo(3.5, 6.5, 2.0, 2.0);
	dao->guardar(triangulo);

	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Triangulo *triangulo2 = (Triangulo*) *iter;
	EXPECT_EQ(triangulo2->getX(), triangulo->getX());
	EXPECT_EQ(triangulo2->getY(), triangulo->getY());
	EXPECT_EQ(triangulo2->getAncho(), triangulo->getAncho());
	EXPECT_EQ(triangulo2->getAlto(), triangulo->getAlto());


}

TEST_F(figuras_test, test_cuadrados) {
	Cuadrado *cuadrado = new Cuadrado(1,1,2,2);
	dao->guardar(cuadrado);

	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Cuadrado *cuadrado2 = (Cuadrado*) *iter;
	EXPECT_EQ(cuadrado2->getAlto(), cuadrado->getAlto());
	EXPECT_EQ(cuadrado2->getAncho(), cuadrado->getAncho());
	EXPECT_EQ(cuadrado2->getRotacion(), cuadrado->getRotacion());


}

TEST_F(figuras_test,test_Muchos_Cuadrados){
	Cuadrado* cuadrado1 = new Cuadrado(1.56,5.80,3,1.2);
	Cuadrado* cuadrado2 = new Cuadrado(3.12,8.05,4.5,2.4);
	Cuadrado* cuadrado3 = new Cuadrado(6.24,10.3,6.75,4.8);
	Cuadrado* cuadrado4 = new Cuadrado(12.48,12.55,10.125,9.6);
	Cuadrado* cuadrado5 = new Cuadrado(24.96,14.8,15.1875,19.2);
	Cuadrado* cuadrado6 = new Cuadrado(49.92,17.05,22.78125,38.4);
	dao->guardar(cuadrado1);
	dao->guardar(cuadrado2);
	dao->guardar(cuadrado3);
	dao->guardar(cuadrado4);
	dao->guardar(cuadrado5);
	dao->guardar(cuadrado6);
	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Cuadrado* un_cuadrado = (Cuadrado*) *iter;
	float x = 1.56;
	float y = 5.80;
	float ancho = 3;
	float alto = 1.2;
	while(strcmp(typeid(*un_cuadrado).name(),"Cuadrado") == 0){
		EXPECT_EQ(un_cuadrado->getX(),x);
		EXPECT_EQ(un_cuadrado->getY(),y);
		EXPECT_EQ(un_cuadrado->getAncho(),ancho);
		EXPECT_EQ(un_cuadrado->getAlto(),alto);
		x = 2*x;
		y = 2.25 + y;
		ancho = 1.5*ancho;
		alto = 2*alto;
		iter.operator ++();
		un_cuadrado = (Cuadrado*) *iter;
	}

}

TEST_F(figuras_test,agregar_un_cuadrado_y_un_circulo_y_ambos_en_orden){
	Cuadrado* cuadrado1 = new Cuadrado(2,3,4,5);
	dao->guardar(cuadrado1);
	Circulo* circulo = new Circulo(2,3,4);
	dao->guardar(circulo);
	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Circulo *un_circulo = (Circulo*) *iter;
	EXPECT_EQ(un_circulo->getX(),circulo->getX());
	EXPECT_EQ(un_circulo->getY(),circulo->getY());
	EXPECT_EQ(un_circulo->getRadio(),circulo->getRadio());
	iter.operator ++();
	Cuadrado *un_cuadrado = (Cuadrado*) *iter;
	EXPECT_EQ(un_cuadrado->getX(),cuadrado1->getX());
	EXPECT_EQ(un_cuadrado->getY(),cuadrado1->getY());
	EXPECT_EQ(un_cuadrado->getAncho(),cuadrado1->getAncho());
	EXPECT_EQ(un_cuadrado->getAlto(),cuadrado1->getAlto());

}

TEST_F(figuras_test,no_hay_figuras_en_un_archivo_vacio){


	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Cuadrado *unTriangulo = (Cuadrado*) *iter;
	int i = 0;
	while(iter != Figuras.end()){
		iter.operator ++();
		i++;
	}
	EXPECT_EQ(i,0);

}


TEST_F(figuras_test,agregar_circulo_y_primera_figura_es_circulo){
	Circulo* circulo = new Circulo(40.47,12.94,5);
	dao->guardar(circulo);
	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Circulo *unCirculo = (Circulo*) *iter;
	EXPECT_EQ(unCirculo->getX(),circulo->getX());
	EXPECT_EQ(unCirculo->getY(),circulo->getY());
	EXPECT_EQ(unCirculo->getRadio(),circulo->getRadio());
}

TEST_F(figuras_test,agregamos_tres_figuras_diferentes){
	Circulo* circulo = new Circulo(0,0,0);
	Cuadrado* cuadrado = new Cuadrado(1,1,1,1);
	Triangulo* triangulo = new Triangulo(0,0,0,0);
	Cuadrado* cuadrado2 = new Cuadrado(1,1,1,1);
	dao->guardar(circulo);
	dao->guardar(cuadrado);
	dao->guardar(triangulo);
	dao->guardar(cuadrado2);
	std::list<Figura*> Figuras = dao->obtenerTodos();
	std::list<Figura*>::iterator iter = Figuras.begin();
	Circulo* unCirculo = (Circulo*)*iter;
	EXPECT_EQ(unCirculo->getX(),0);
	EXPECT_EQ(unCirculo->getY(),0);
	EXPECT_EQ(unCirculo->getRadio(),0);
	iter.operator ++();
	Cuadrado* unCuadrado = (Cuadrado*)*iter;
	EXPECT_EQ(unCuadrado->getAncho(),1);
	EXPECT_EQ(unCuadrado->getAlto(),1);
	iter.operator ++();
	unCuadrado = (Cuadrado*)*iter;
	EXPECT_EQ(unCuadrado->getAncho(),1);
	EXPECT_EQ(unCuadrado->getAlto(),1);
	iter.operator ++();
	Triangulo* unTriangulo = (Triangulo*)*iter;
	EXPECT_EQ(unTriangulo->getAncho(),0);
	EXPECT_EQ(unTriangulo->getAlto(),0);
	iter.operator ++();
	bool fin = false;
	if(iter == Figuras.end())
		fin = true;
	EXPECT_EQ(fin ,true);

	//TODO EL obtenerTodos() me devuelve los objetos que habia antes mas este cuadardo que agrege y no deberia
	//ser asi.
	/*Cuadrado* cuadrado3 = new Cuadrado(1,1,1,1);
	dao->guardar(cuadrado3);
	Figuras = dao->obtenerTodos();
	iter = Figuras.begin();
	Cuadrado* unb = (Cuadrado*)*iter;
	EXPECT_EQ(unb->getAncho(),1);
	EXPECT_EQ(unb->getAlto(),1);*/

}
