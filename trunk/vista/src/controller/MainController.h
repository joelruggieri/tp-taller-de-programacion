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
#include "JuegoEventsController.h"
#include "DrawController.h"
using namespace std;

class MainController: public DrawController {
private:
	SDL_Renderer * render;
	JuegoEventsController * juegoController;
public:
	MainController();
	virtual ~MainController();
	int run();
	void dibujar();
};

#endif /* MAINCONTROLLER_H_ */
