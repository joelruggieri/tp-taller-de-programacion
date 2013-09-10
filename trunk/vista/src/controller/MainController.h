/*
 * MainController.h
 *
 *  Created on: 8/09/2013
 *      Author: jonathan
 */

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"
#include "DragAndDropController.h"
using namespace std;

class MainController {
private:
	Zona *crearZonaJuego(SDL_Renderer* render);
	DragAndDropController * dropController;
public:
	MainController();
	virtual ~MainController();
	int run();
	SDL_Texture* cargarTexture (const string &file, SDL_Renderer* ren);
};

#endif /* MAINCONTROLLER_H_ */
