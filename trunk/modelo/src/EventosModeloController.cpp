/*
 * ModeloController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "ModeloController.h"

ModeloController::ModeloController() {
	mapa = new Mapa(50,50,100,100);

}

ModeloController::~ModeloController() {
	delete mapa;
}

bool ModeloController::crearFigura(Figura* figura) {
	return this->mapa->add(figura);;
}

bool ModeloController::removerFigura(Figura* figura) {
	bool result = this->mapa->remove(figura);
	return result;;

}

list<Figura*>& ModeloController::getFiguras() {
	this->figuras.clear();
	std::list<Figura*>figurasMapa = mapa->getFiguras();
	list<Figura*>::iterator it;
	for(it= figurasMapa.begin(); it!= figurasMapa.end(); ++it){
		figuras.push_back(*it);
	}
	std::list<Union*>unionesMapa = mapa->getUniones();
	list<Union*>::iterator it2;
	for(it2= unionesMapa.begin(); it2!= unionesMapa.end(); ++it2){
		figuras.push_back(*it2);
	}
	return this->figuras;
}

Figura* ModeloController::pickUp(float x, float y, uint16 mascara, int numeroJugador) {
	return mapa->pickUp(x,y, mascara, numeroJugador);
}

Figura* ModeloController::pickUpParaUnir(float x, float y, uint16 mascara, int numeroJugador) {
	Figura* figura = mapa->pickUp(x,y, mascara, numeroJugador);

	if(figura == NULL) {
		figura = mapa->pickUp(x,y, mascara, NUMERO_JUGADOR_DEFECTO);
	}

	return figura;
}

void ModeloController::step() {
	mapa->step();
}

void ModeloController::start() {
	mapa->makeBackUp();
	mapa->despertar();
}

void ModeloController::stop() {
	mapa->restoreBackUp();
}

bool ModeloController::crearUnion(Union* figura) {

		Figura* fInicial = this->pickUpParaUnir(figura->getXInicial(),
				figura->getYInicial(), figura->getMascaraExtremos(),figura->getNumeroJugador());
		Figura* fFinal = this->pickUpParaUnir(figura->getXFinal(),
				figura->getYFinal(), figura->getMascaraExtremos(),figura->getNumeroJugador());
		if (fFinal == fInicial)
			return false;

		figura->setExtremos(fInicial,fFinal);
		//recupero los cuerpos que une, se los seteo y verifico.
		return mapa->add(figura);
}

void ModeloController::cleanDeletes() {
	mapa->cleanDeletes();
}

void ModeloController::addArea(Area* area, int numeroJugador){
	this->mapa->addArea(area,numeroJugador);
}
