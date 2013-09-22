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
#include <sstream>

PersistenciaManager::PersistenciaManager() {
	this->dao = new NivelDAO();
	this->nivel = NULL;
	nivelActual = "nivel1";
}

PersistenciaManager::~PersistenciaManager() {
	if(nivel != NULL){
		delete nivel;
	}
	delete dao;
}

list<Figura*> & PersistenciaManager::getFiguras() {
	Logger log;
	if(nivel== NULL){
		if (AdministradorDeArchivos::cantidadNiveles() == 0) {
			// No hay niveles, se creara uno nuevo.
			log.warning("No existe el nivel, se procede a crear uno vacio");
			std::stringstream aux;
			aux << "NuevoNivel" << AdministradorDeArchivos::cantidadNiveles();
			nivel = new Nivel(aux.str());
		} else {
			nivel = dao->cargarPrimerNivel();

		}
		nivelActual = nivel->getNombre();
	}
	return this->nivel->getFiguras();
}

void PersistenciaManager::persistirFiguras(list<Figura*>& figuras) {
	Logger log;
	if(this->nivel != NULL){
		nivel->getFiguras().empty();
		nivel->getFiguras().merge(figuras);
	} else {
		try{
			nivel = dao->leerNivel(nivelActual);
		} catch (NivelInexistenteException& e){
			log.warning("No existe el nivel, se procede a crear uno vacio");
			nivel = new Nivel(nivelActual);
		}
	}
	log.debug("Persistiendo nivel");
	string msj = "Se van a persistir ";
	float size = nivel->getFiguras().size();
	log.concatenar(msj, size);
	msj = msj +" Figuras";
	log.info(msj);
	dao->guardarNivel(nivel);
}

void PersistenciaManager::cambiarNivel(int nivel) {
	throw "No implementado todavia";
}
