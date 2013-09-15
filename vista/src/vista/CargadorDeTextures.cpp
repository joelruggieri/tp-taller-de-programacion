/*
 * CargadorDeTextures.cpp
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#include "src/AdministradorDeLoggers.h"
#include "CargadorDeTextures.h"
#include <iostream>
using namespace std;

CargadorDeTextures* CargadorDeTextures::pinstance = 0;// Inicializar el puntero
CargadorDeTextures* CargadorDeTextures::Instance (SDL_Renderer* render)
{
  if (pinstance == 0)  // ¿Es la primera llamada?
  {
    pinstance = new CargadorDeTextures(render); // Creamos la instancia
  }
  return pinstance; // Retornamos la dirección de la instancia
}

CargadorDeTextures* CargadorDeTextures::Instance ()
{
	Logger& log = AdministradorDeLoggers::getLogger(ERROR);

	if(pinstance == 0){
		//TODO LANZAR EXCEPTION
		std::string mensaje_error = "No se pudo inicializar la Instancia correctamente";
		log.error(mensaje_error);
		//cout<< "ERROR"<<endl;
	}
  return pinstance; // Retornamos la dirección de la instancia
}



CargadorDeTextures::CargadorDeTextures(SDL_Renderer* render) {
	this->rutaError = "resource/imagenError.jpg";
	this->render = render;
	return;

}




SDL_Texture* CargadorDeTextures::cargarTexture(string ruta)
{
	pair<string, SDL_Texture*> par;
	SDL_Texture* texture;
	map<string, SDL_Texture*>::iterator iter = this->Textures.find(ruta);
	if (iter!= this->Textures.end())	// Si la textura ya ha sido cargada anteriormente
	{
//		this->Textures.insert(par(ruta, ))
		return iter->second;
	}
	else	//si la textura no esta en el mapa , genero la textura, y la asigno
	{
		texture = IMG_LoadTexture(this->render, ruta.c_str() );
		if (texture == NULL)
			{
			texture = IMG_LoadTexture(this->render, this->rutaError.c_str() );
			this->Textures.insert(pair<string, SDL_Texture*>(rutaError, texture));
			}
		else
			this->Textures.insert(pair<string, SDL_Texture*>(ruta, texture));




	}



return texture; }


CargadorDeTextures::~CargadorDeTextures() {
	map<string, SDL_Texture* >::const_iterator iter;
	for(iter = this->Textures.begin(); iter != this->Textures.end(); ++iter)
	{
		SDL_DestroyTexture(iter->second);

	}
	// SDL_DestroyRenderer(this->render); se destruye mas adelante ??
}

int CargadorDeTextures::getCantTextures()
{
	return this->Textures.size();
}


