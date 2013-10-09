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

#include "../vista/CargadorDeTextures.h"
#include "../vista/DraggingView.h"
#include "GeneralEventController.h"
#include "inicializador/InicializadorJuego.h"
#include "JuegoEventsController.h"
#include "Resizer.h"
#include "ToolBarEventController.h"
#include "zonaToolBar/ZonaToolBar.h"
#include "src/Logger.h"
#include "UserEventCreator.h"
#include "../ConstantesVista.h"
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
	toolBar->dibujarse(render);
	SDL_RenderPresent(render);
}
int MainController::run() {
	SDL_Window *ventana = NULL;
//	int draggin = false;
	bool terminar = false;
	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("Generador Niveles", 400, 400, 600, 600,
			SDL_WINDOW_RESIZABLE);
	render = SDL_CreateRenderer(ventana, -1,
			SDL_RENDERER_ACCELERATED);

	Resizer::Instance(600, 600, 120, 120);
	CargadorDeTextures * texturas = CargadorDeTextures::Instance(render);

	GeneralEventController eventController;
	ModeloController modeloController;
	InicializadorJuego inicializador(&eventController, &modeloController);

	juegoController = inicializador.crearZonaJuego();
	toolBar = new ZonaToolBar(300, 550, 600, 100,
			texturas->cargarTexture("resource/fondoHerramientas.jpg"));
	ToolBarEventController* tbEventController = new ToolBarEventController(
			toolBar);

	eventController.addMouseController(tbEventController, 2, 1);
	eventController.addKeyboardController(tbEventController);
	eventController.setFlujoController(juegoController);
	eventController.setDrawController(this);
	int timerID =SDL_AddTimer(1000/VELOCIDAD_REFRESCO_VISTA, my_callbackfunc, NULL);
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

