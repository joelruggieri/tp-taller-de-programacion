/*
 * ModeloController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "ModeloController.h"

ModeloController::ModeloController() {
	mapa = new Mapa(50, 50, 100, 100);

	iniciado = false;
}

ModeloController::~ModeloController() {
	delete mapa;
}

bool ModeloController::crearFigura(Figura* figura) {
	return this->mapa->add(figura);;
}

void ModeloController::removerFigura(Figura* figura) {
	this->mapa->remove(figura);

}

list<Figura*>& ModeloController::getFiguras() {
	this->figuras.clear();
	std::list<Figura*> figurasMapa = mapa->getFiguras();
	list<Figura*>::iterator it;
	for (it = figurasMapa.begin(); it != figurasMapa.end(); ++it) {
		figuras.push_back(*it);
	}
	std::list<Union*> unionesMapa = mapa->getUniones();
	list<Union*>::iterator it2;
	for (it2 = unionesMapa.begin(); it2 != unionesMapa.end(); ++it2) {
		figuras.push_back(*it2);
	}
	return this->figuras;
}

Figura* ModeloController::pickUp(float x, float y, uint16 mascara,
		int numeroJugador) {
	//entrega3 un pickup q tome solo los del jugador
	return mapa->pickUp(x, y, mascara, numeroJugador,false);
}

Figura* ModeloController::pickUpConEstaticos(float x, float y, uint16 mascara,
		int numeroJugador) {
	//UN PICKUP QUE TOME EL JUGADOR ESTATICO O EL ELEGIDO. dentro del area.
	Figura* figura = mapa->pickUp(x, y, mascara, numeroJugador,true );
	return figura;
}

void ModeloController::step() {
	if (iniciado) {
		mapa->step();
	}
}

void ModeloController::start() {
	mapa->makeBackUp();
	mapa->despertar();
	iniciado = true;
}

void ModeloController::stop() {
	mapa->restoreBackUp();
	iniciado = false;
}

bool ModeloController::crearUnion(Union* figura) {
	//UN PICKUP QUE TOME EL JUGADOR ESTATICO O EL ELEGIDO. dentro del area.
	Figura* fInicial = this->pickUpConEstaticos(figura->getXInicial(),
			figura->getYInicial(), figura->getMascaraExtremos(),
			figura->getNumeroJugador());
	Figura* fFinal = this->pickUpConEstaticos(figura->getXFinal(),
			figura->getYFinal(), figura->getMascaraExtremos(),
			figura->getNumeroJugador());
	if (fFinal == fInicial)
		return false;

	figura->setExtremos(fInicial, fFinal);
	//recupero los cuerpos que une, se los seteo y verifico.
	return mapa->add(figura);
}

void ModeloController::cleanDeletes() {
	mapa->cleanDeletes();
}

void ModeloController::addArea(Area* area, int numeroJugador) {
	this->mapa->addArea(area, numeroJugador);
}

void ModeloController::interactuar(Area&a, int jugador, float x, float y) {
	if (iniciado) {
		//entrega3 un pickup que no chequea ni jugador ni area.
		Figura* pup = mapa->pickUp(x, y, CATEGORIA_FIGURAS);
		if (pup != NULL)
			pup->interactuar(a, jugador);
	}

}
