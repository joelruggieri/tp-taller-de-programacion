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
using namespace std;


class CargadorDeTextures {
public:
	~CargadorDeTextures();
	//virtual ~CargadorDeTextures();
	SDL_Texture* cargarTexture(string ruta);
	static CargadorDeTextures* Instance();
	static CargadorDeTextures* Instance (SDL_Renderer* render);
private:
	int getCantTextures();	//para prueba fue
	map<string, SDL_Texture*> Textures;
	SDL_Renderer* render ;
	static CargadorDeTextures* pinstance;

protected:
	CargadorDeTextures(SDL_Renderer*);
	CargadorDeTextures(const CargadorDeTextures & ) ;
	CargadorDeTextures &operator= (const CargadorDeTextures & ) ;

};
#endif /* CARGADORDETEXTURES_H_ */
