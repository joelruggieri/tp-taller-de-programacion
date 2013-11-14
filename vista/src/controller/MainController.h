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
#include "GeneralEventController.h"
#include "src/threading/ColaEventos.h"
#include "ViewController.h"
#include "src/Logger.h"
#include "src/threading/Status.h"
using namespace std;
namespace CLIENTE {
class MainController {
private:
	float xArea,yArea,wArea,hArea;
	SDL_Renderer * render;
	JuegoEventsController * juegoController;
	GeneralEventController * crearGeneralEventController(list<string> & factories);
	ColaEventos * entrada;
	ColaEventos * salida;
	ViewController * viewController;
	Logger log;
	Status* status;
public:
	MainController(ColaEventos* entrada,ColaEventos * salida,Status*);
	virtual ~MainController();
	int run(list<string> & factories);
	ViewController * getviewController();
	void setCoordenadasArea(float, float, float ,float);
};
}
#endif /* MAINCONTROLLER_H_ */
