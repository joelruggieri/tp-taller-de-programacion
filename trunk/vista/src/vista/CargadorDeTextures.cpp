/*
 * CargadorDeTextures.cpp
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#include "CargadorDeTextures.h"
#include "src/Logger.h"
#include <iostream>
#include "../ConstantesVista.h"
using namespace std;

CargadorDeTextures* CargadorDeTextures::pinstance = 0; // Inicializar el puntero
CargadorDeTextures* CargadorDeTextures::Instance(SDL_Renderer* render) {
	if (pinstance == 0)  // ¿Es la primera llamada?
			{
		pinstance = new CargadorDeTextures(render); // Creamos la instancia
	}
	return pinstance; // Retornamos la dirección de la instancia
}

CargadorDeTextures* CargadorDeTextures::Instance() {
	Logger log;

	if (pinstance == 0) {
		//TODO LANZAR EXCEPTION
		std::string mensaje_error =
				"No se pudo inicializar la Instancia correctamente";
		log.error(mensaje_error);
		//cout<< "ERROR"<<endl;
	}
	return pinstance; // Retornamos la dirección de la instancia
}

CargadorDeTextures::CargadorDeTextures(SDL_Renderer* render) {
	this->render = render;
	pair<string, SDL_Texture*> par;
	SDL_Texture* texture;
	texture = IMG_LoadTexture(this->render, PATH_ERROR_IMG);
	this->Textures.insert(pair<string, SDL_Texture*>(PATH_ERROR_IMG, texture));
	return;

}

SDL_Texture* CargadorDeTextures::cargarTexture(string ruta) {
	pair<string, SDL_Texture*> par;
	SDL_Texture* texture;
	Logger log;
	string msj;
	map<string, SDL_Texture*>::iterator iter = this->Textures.find(ruta);
	if (iter != this->Textures.end()) {// Si la textura ya ha sido cargada anteriormente la retorno.
		msj = "La textura '" + ruta + "' ya ha sido cargada, se omite la carga";
		log.info(msj);
		return iter->second;
	} else {	//si la textura no esta en el mapa , genero la textura, y la asigno
		texture = IMG_LoadTexture(this->render, ruta.c_str());
		if (texture == NULL) { // si la imagen no existe asigno la textura de error y retorno esa.
			map<string, SDL_Texture*>::iterator iter = this->Textures.find(PATH_ERROR_IMG);
			this->Textures.insert(pair<string, SDL_Texture*>(ruta, iter->second));
			msj = "La textura '" + ruta + "' no existe, se retorna la textura por defecto";
			log.warning(msj);
			return iter->second;
		} else
			log.info("Se ha cargado exitosamente la textura '" + ruta +"'");
			this->Textures.insert(pair<string, SDL_Texture*>(ruta, texture));
			return texture;
	}

}

CargadorDeTextures::~CargadorDeTextures() {
	map<string, SDL_Texture*>::const_iterator iter;
	for (iter = this->Textures.begin(); iter != this->Textures.end(); ++iter) {
		SDL_DestroyTexture(iter->second);

	}
	// SDL_DestroyRenderer(this->render); se destruye mas adelante ??
}

int CargadorDeTextures::getCantTextures() {
	return this->Textures.size();
}

