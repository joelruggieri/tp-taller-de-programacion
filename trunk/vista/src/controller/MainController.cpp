/*
 * MainController.cpp
 *
 *  Created on: 8/09/2013
 *      Author: jonathan
 */

#include "MainController.h"

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <new>

#include "../vista/CargadorDeTextures.h"
#include "../vista/DraggingView.h"
#include "GeneralEventController.h"
#include "JuegoEventsController.h"
#include "Resizer.h"
#include "src/Logger.h"
#include "UserEventCreator.h"
#include "../ConstantesVista.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include <string>
#include <list>
using namespace std;
namespace CLIENTE {

MainController::MainController(ColaEventos * salida) {
	Logger::setNivel(DEBUG_N);
	this->salida = salida;
	viewController = NULL;
	juegoController = NULL;
	render = NULL;
}

MainController::~MainController() {
}

Uint32 my_callbackfunc(Uint32 interval, void *param) {
	SDL_Event event = crearEvento(USREVENT_DRAW, NULL, NULL);
	SDL_PushEvent(&event);
	return (interval);
}

void MainController::dibujar() {
	SDL_SetRenderDrawColor(render, 1, 1, 1, 1);
	SDL_RenderClear(render);
	juegoController->dibujarse(render);
	SDL_RenderPresent(render);
}
int MainController::run() {
	SDL_Window *ventana = NULL;
	bool terminar = false;
	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("The Incredible Machine LAN", 300, 100, 600, 600, SDL_WINDOW_RESIZABLE);
	render = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
	viewController = new ViewController(render, Resizer::crearTransformacionALogica(600,600));
	GeneralEventController * eventController = crearGeneralEventController();
	eventController->setDrawController(viewController);
	eventController->addResizerController(viewController);
	int timerID =SDL_AddTimer(1000/VELOCIDAD_REFRESCO_VISTA, my_callbackfunc, NULL);
	SDL_SetWindowMaximumSize(ventana, 825,825);
	SDL_SetWindowPosition(ventana, 300, 100);

	while (!terminar) {
		SDL_Delay(100.0/VELOCIDAD_REFRESCO);
		terminar = eventController->procesarEventos(ventana);
	}
	SDL_RemoveTimer(timerID);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(ventana);

	return 0;
}

GeneralEventController* MainController::crearGeneralEventController() {
	ZonaTablero * tablero = new ZonaTablero(viewController,this->salida);
	ZonaPlay * zp = new ZonaPlay(viewController,110, 10, this->salida);
	list<string> factories;
	factories.push_back("1");
	factories.push_back("2");
	factories.push_back("3");
	factories.push_back("4");
	factories.push_back("5");
	factories.push_back("6");
	factories.push_back("7");
	factories.push_back("8");
	factories.push_back("9");
	factories.push_back("10");
	factories.push_back("11");
	factories.push_back("12");
	ZonaCreacion* zonaCreacion = new ZonaCreacion(viewController, factories, 110, 80, salida);
	JuegoEventsController * juegoController = new JuegoEventsController(zp);
	juegoController->setZonas(tablero, zonaCreacion);
	GeneralEventController * generalEventController = new GeneralEventController();
	generalEventController->addMouseController(juegoController, 1, 1);

	return generalEventController;
}

ViewController* MainController::getviewController() {
	return viewController;
}

}
