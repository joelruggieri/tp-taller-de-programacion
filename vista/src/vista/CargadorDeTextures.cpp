/*
 * CargadorDeTextures.cpp
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#include "CargadorDeTextures.h"
using namespace std;



CargadorDeTextures::CargadorDeTextures(SDL_Renderer* render, string rutaCasoError) {
	this->rutaError = rutaCasoError;
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

void CargadorDeTextures::destruirCargador()
{
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


