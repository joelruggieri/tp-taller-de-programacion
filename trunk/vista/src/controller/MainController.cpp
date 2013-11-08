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
#include "src/ConstantesComunicacion.h"
#include "../vista/CargadorDeTextures.h"
#include "../vista/DraggingView.h"
#include "GeneralEventController.h"
#include "JuegoEventsController.h"
#include "Resizer.h"
#include "src/Logger.h"
#include "UserEventCreator.h"
#include "../ConstantesVista.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include "src/threading/EventReceptorThread.h"
#include <string>
#include <list>
using namespace std;



namespace CLIENTE {

MainController::MainController(ColaEventos* entrada,ColaEventos * salida) {
	Logger::setNivel(DEBUG_N);
	this->entrada = entrada;
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
int MainController::run(list<string> & factories) {
	SDL_Window *ventana = NULL;
	bool terminar = false;;
	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("The Incredible Machine LAN", 300, 100, TAMANIO_PANTALLA, TAMANIO_PANTALLA, SDL_WINDOW_RESIZABLE);
	render = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
	viewController = new ViewController(render, Resizer::crearTransformacionALogica(TAMANIO_PANTALLA,TAMANIO_PANTALLA));
	GeneralEventController * eventController = crearGeneralEventController(factories);
	eventController->setDrawController(viewController);
	eventController->addResizerController(viewController);


	//Creo el thread que se encarga de distribuir los msjs del server
	EventReceptorThread receptor(this->entrada, NULL, this->viewController, NULL, NULL);
	receptor.run();
	int timerID =SDL_AddTimer(1000/VELOCIDAD_REFRESCO_VISTA, my_callbackfunc, NULL);
	SDL_SetWindowMaximumSize(ventana, 825,825);
	SDL_SetWindowPosition(ventana, 300, 100);

	while (!terminar) {
		SDL_Delay(100.0/VELOCIDAD_REFRESCO);
		terminar = eventController->procesarEventos(ventana);
	}
	receptor.cancel();
	SDL_RemoveTimer(timerID);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(ventana);
	return 0;
}

GeneralEventController* MainController::crearGeneralEventController(list<string> & factories) {
	ZonaTablero * tablero = new ZonaTablero(viewController,this->salida);
	ZonaPlay * zp = new ZonaPlay(viewController,110, 90, this->salida);
	ZonaCreacion* zonaCreacion = new ZonaCreacion(viewController, factories, 110, 80, salida);
	JuegoEventsController * juegoController = new JuegoEventsController(zp,tablero, zonaCreacion,Resizer::crearTransformacionALogica(TAMANIO_PANTALLA,TAMANIO_PANTALLA));
	GeneralEventController * generalEventController = new GeneralEventController();
	generalEventController->addMouseController(juegoController, 1, 1);
	generalEventController->addResizerController(juegoController);
	return generalEventController;
}

ViewController* MainController::getviewController() {
	return viewController;
}

}
