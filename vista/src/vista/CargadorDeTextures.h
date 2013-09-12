/*
 * CargadorDeTextures.h
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#ifndef CARGADORDETEXTURES_H_
#define CARGADORDETEXTURES_H_
#include <map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <utility>
#include <string>

namespace std {

class CargadorDeTextures {
public:
	CargadorDeTextures(SDL_Renderer* render, string rutaCasoError);
	//virtual ~CargadorDeTextures();
	SDL_Texture* cargarTexture(string ruta);
	void destruirCargador();	//destruye el render

private:
	int getCantTextures();	//para prueba fue
	map<string, SDL_Texture*> Textures;
	SDL_Renderer* render ;
	string rutaError;




};

} /* namespace std */
#endif /* CARGADORDETEXTURES_H_ */
