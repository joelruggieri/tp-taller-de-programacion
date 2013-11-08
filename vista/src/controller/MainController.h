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
#include "GeneralEventController.h"
#include "src/threading/ColaEventos.h"
#include "ViewController.h"
using namespace std;
namespace CLIENTE {
class MainController: public DrawController {
private:
	SDL_Renderer * render;
	JuegoEventsController * juegoController;
	GeneralEventController * crearGeneralEventController(list<string> & factories);
	ColaEventos * entrada;
	ColaEventos * salida;
	ViewController * viewController;
public:

	MainController(ColaEventos* entrada,ColaEventos * salida);
	virtual ~MainController();
	int run(list<string> & factories);
	void dibujar();
	ViewController * getviewController();
};
}
#endif /* MAINCONTROLLER_H_ */
