/*
 * PersistenciaManager.cpp
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#include "PersistenciaManager.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Figura.h"
#include "src/figura/Circulo.h"
PersistenciaManager::PersistenciaManager() {
	//TODO PEGARLO CON EL DAO DE PERSISTENCIA.
	Figura * figura = new Cuadrado(10,10,10,10);
	figura->setRotacion(30);
	figurasPersistidas.push_back(figura);
	figura = new Cuadrado(15,15,10,10);
	figura->setRotacion(67);
	figurasPersistidas.push_back(figura);
	figurasPersistidas.push_back(new Cuadrado(20,20,10,10));
	figurasPersistidas.push_back(new Circulo(25,25,5));
}

PersistenciaManager::~PersistenciaManager() {
	// TODO Auto-generated destructor stub
}

list<Figura*> & PersistenciaManager::getFiguras() {
 return this->figurasPersistidas;
}

void PersistenciaManager::persistirFiguras(list<Figura*>& figuras) {
	this->figurasPersistidas.clear();
	this->figurasPersistidas.merge(figuras);
}

void PersistenciaManager::cambiarNivel(int nivel) {
	this->figurasPersistidas.clear();
}
