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
#include "RutasArchivos.h"
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
			nivel->setFondo(FONDO_DEFECTO);
		} else {
			try {
				nivel = dao->cargarPrimerNivel();
			} catch (NivelInexistenteException &exc) {
				log.error("El nivel ingresado por parametro no existe. Se creara un nuevo nivel.");
				std::stringstream aux;
				aux << "NuevoNivel" << AdministradorDeArchivos::cantidadNiveles();
				nivel = new Nivel(aux.str());
//				nivel->setFondo(FONDO_DEFECTO);
			}

		}
		nivelActual = nivel->getNombre();
	}
	return this->nivel->getFiguras();
}

void PersistenciaManager::setFiguras(list<Figura*>& figuras) {
	Logger log;
	if(this->nivel != NULL){
		nivel->getFiguras().clear();
		nivel->getFiguras().insert(nivel->getFiguras().begin(),figuras.begin(),figuras.end());
	} else {
		try{
			nivel = dao->leerNivel(nivelActual);
		} catch (NivelInexistenteException& e){
			log.warning("No existe el nivel, se procede a crear uno vacio");
			nivel = new Nivel(nivelActual);
			nivel->setFondo(FONDO_DEFECTO);
		}
	}
}

void PersistenciaManager::cambiarNivel(int nivel) {
	throw "No implementado todavia";
}

void PersistenciaManager::cambiarImagenFondo(string ruta) {
	nivel->setFondo(ruta);
}

void PersistenciaManager::persistir() {
	Logger log;
	log.debug("Persistiendo nivel " + nivel->getNombre());
	string msj = "Se van a persistir ";
	float size = nivel->getFiguras().size();
	log.concatenar(msj, size);
	msj = msj +" Figuras";
	log.info(msj);
	dao->guardarNivel(nivel);
}

string PersistenciaManager::getImagenFondo() {
	return nivel->getFondo();
}

