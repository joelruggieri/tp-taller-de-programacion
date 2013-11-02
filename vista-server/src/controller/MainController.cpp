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
#include <src/ModeloController.h>
#include <new>

#include "../vista/DraggingView.h"
#include "GeneralEventController.h"
#include "inicializador/InicializadorJuego.h"
#include "JuegoEventsController.h"
#include "src/Logger.h"
#include "UserEventCreator.h"
#include "../ConstantesVista.h"
#include "src/mensajes/ViewMsj.h"
#include <list>
using namespace std;

struct SDL_Renderer;
struct SDL_Window;

MainController::MainController() {
	Logger::setNivel(INFO_N);
}

MainController::~MainController() {
}

Uint32 my_callbackfunc(Uint32 interval, void *param)
{
	SDL_Event event = crearEvento(USREVENT_DRAW, NULL, NULL);
	SDL_PushEvent(&event);
	return(interval);
}

void MainController::dibujar() {
	SDL_SetRenderDrawColor(render, 1, 1, 1, 1);
	SDL_RenderClear(render);
	list<ViewMsj*> lista;
	juegoController->dibujarse(lista);
	SDL_RenderPresent(render);
}
int MainController::run() {
	SDL_Window *ventana = NULL;
//	int draggin = false;
	bool terminar = false;
	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("Generador Niveles", 300, 100, 600, 600,
			SDL_WINDOW_RESIZABLE);
	render = SDL_CreateRenderer(ventana, -1,
			SDL_RENDERER_ACCELERATED);


	GeneralEventController eventController;
	ModeloController modeloController;
	InicializadorJuego inicializador(&eventController, &modeloController);

	juegoController = inicializador.crearZonaJuego();
	eventController.setFlujoController(juegoController);
	eventController.setDrawController(this);
	int timerID =SDL_AddTimer(1000/VELOCIDAD_REFRESCO_VISTA, my_callbackfunc, NULL);
	SDL_SetWindowMaximumSize(ventana, 825, 825);
//	SDL_SetWindowMaximumSize(ventana, 650, 650);
	SDL_SetWindowPosition(ventana, 300,100);

	while (!terminar) {
		SDL_Delay(100.0/VELOCIDAD_REFRESCO);
		juegoController->paso();
		terminar = eventController.procesarEventos(ventana);
	}
	SDL_RemoveTimer(timerID);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(ventana);

	return 0;
}

