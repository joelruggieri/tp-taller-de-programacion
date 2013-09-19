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
#include "src/NivelInexistenteException.h"
#include "src/Logger.h"
PersistenciaManager::PersistenciaManager() {
	this->dao = new NivelDAO();
	this->nivel = NULL;
	nivelActual =1;
}

PersistenciaManager::~PersistenciaManager() {
	if(nivel != NULL){
		delete nivel;
	}
	delete dao;
}

list<Figura*> & PersistenciaManager::getFiguras() {
	if(nivel== NULL){
		try{
			nivel = dao->leerNivel(nivelActual);
		} catch (NivelInexistenteException& e){
			Logger log;
			log.warning("No existe el nivel, se procede a crear uno vacio");
			nivel = new Nivel(nivelActual);
		}
	}
 return this->nivel->getFiguras();
}

void PersistenciaManager::persistirFiguras(list<Figura*>& figuras) {
	if(this->nivel != NULL){
		nivel->getFiguras().empty();
		nivel->getFiguras().merge(figuras);
	}
}

void PersistenciaManager::cambiarNivel(int nivel) {
	throw "No implementado todavia";
}
