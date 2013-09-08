/*
 * MainController.cpp
 *
 *  Created on: 8/09/2013
 *      Author: jonathan
 */

#include "MainController.h"
#include "zonaDragAndDrop/ZonaJuego.h"
MainController::MainController() {
	// TODO Auto-generated constructor stub

}

MainController::~MainController() {
	// TODO Auto-generated destructor stub
}


SDL_Texture* MainController::cargarTexture (const string &file, SDL_Renderer* ren){
	SDL_Texture* texture = IMG_LoadTexture(ren, file.c_str() );
	if (texture == NULL) cout << "IMG_Load error: " << IMG_GetError() <<endl;

	return texture;
}

int MainController::run() {
	SDL_Window *ventana = NULL ;
//	int draggin = false;

	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("Hola mundo", 400,400,400,400,SDL_WINDOW_RESIZABLE);

	SDL_Renderer* render = SDL_CreateRenderer(ventana,-1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* canvasTexture = this->cargarTexture("Fondo4.jpg", render);
	ZonaJuego * zona = new ZonaJuego(canvasTexture);
	zona->dibujarse(render);
	SDL_RenderPresent(render);
	SDL_Delay(4000);
	delete zona;

 return 0;
}
