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
using namespace std;

class MainController {
public:
	MainController();
	virtual ~MainController();
	int run();
	SDL_Texture* cargarTexture (const string &file, SDL_Renderer* ren);
};

#endif /* MAINCONTROLLER_H_ */
