/*
 * CargadorDeSonidos.cpp
 *
 *  Created on: 21/11/2013
 *      Author: joel
 */

#include "CargadorDeSonidos.h"
#include "src/Logger.h"
namespace CLIENTE{
CargadorDeSonidos* CargadorDeSonidos::pinstance = 0;

CargadorDeSonidos* CargadorDeSonidos::Instance(){
	Logger log;
	if (pinstance == 0) {
		pinstance = new CargadorDeSonidos();
	}
	return pinstance; // Retornamos la dirección de la instancia
}

CargadorDeSonidos::CargadorDeSonidos(){

}

CargadorDeSonidos::~CargadorDeSonidos() {
	map<int,Mix_Chunk*>::const_iterator iter;
	for (iter = this->sonidos.begin(); iter != this->sonidos.end(); ++iter) {
			Mix_FreeChunk(iter->second);

		}
}

bool CargadorDeSonidos::cargarSonido(int id , string ruta){
	Logger log;
	Mix_Chunk* sonido = Mix_LoadWAV(ruta.c_str());
	if (sonido == NULL){
		std::string mensaje_error = "No se pudo cargar el sonido con la ruta ";
		mensaje_error.append(ruta);
		log.error(mensaje_error);
		return false;
	}
	this->sonidos.insert(pair<int,Mix_Chunk*>(id,sonido));
	return true;
}

Mix_Chunk* CargadorDeSonidos::getSonido(int id){
	map<int,Mix_Chunk*>::iterator iter = this->sonidos.find(id);
	if(iter != this->sonidos.end())
		return iter->second;

	return NULL;
}

}
