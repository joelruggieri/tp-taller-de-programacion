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
}

MainController::~MainController() {
}

Uint32 my_callbackfunc(Uint32 interval, void *param) {
	SDL_Event event = crearEvento(USREVENT_DRAW, NULL, NULL);
	SDL_PushEvent(&event);
	return (interval);
}
void taparHueco(SDL_Renderer * renderer) {
	SDL_Rect dest;
	Resizer * r = Resizer::Instance();
	dest.x = 0;
	dest.y = r->resizearPosicionLogicaY(100);
	dest.w = r->resizearDistanciaLogicaX(120);
	dest.h = r->resizearDistanciaLogicaY(20);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(renderer, &dest);
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
	ventana = SDL_CreateWindow("Generador Niveles", 300, 100, 600, 600, SDL_WINDOW_RESIZABLE);
	render = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);

	Resizer::Instance(600, 600, 120, 120);
//	CargadorDeTextures * texturas = CargadorDeTextures::Instance(render);

	GeneralEventController * eventController = crearGeneralEventController();

//	juegoController = inicializador.crearZonaJuego();
//	eventController.setDrawController(this);
//	int timerID =SDL_AddTimer(1000/VELOCIDAD_REFRESCO_VISTA, my_callbackfunc, NULL);
	SDL_SetWindowMaximumSize(ventana, 825, 825);
//	SDL_SetWindowMaximumSize(ventana, 650, 650);
	SDL_SetWindowPosition(ventana, 300, 100);

	while (!terminar) {
//		SDL_Delay(100.0/VELOCIDAD_REFRESCO);
		terminar = eventController->procesarEventos(ventana);
	}
//	SDL_RemoveTimer(timerID);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(ventana);

	return 0;
}

GeneralEventController* MainController::crearGeneralEventController() {
	ZonaTablero * tablero = new ZonaTablero(this->salida);
	ZonaPlay * zp = new ZonaPlay(110, 10, this->salida);
	list<string> factories;
	ZonaCreacion* zonaCreacion = new ZonaCreacion(factories, 110, 10, salida);
	JuegoEventsController * juegoController = new JuegoEventsController(zp);
	juegoController->setZonas(tablero, zonaCreacion);
	GeneralEventController * generalEventController = new GeneralEventController();
	generalEventController->addMouseController(juegoController, 1, 1);

	return generalEventController;
}
}
