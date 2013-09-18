/*
 * MainController.cpp
 *
 *  Created on: 8/09/2013
 *      Author: jonathan
 */

#include "MainController.h"
#include "Resizer.h"
#include "GeneralEventController.h"
#include "../vista/DraggingView.h"
#include "../vista/RotationView.h"
#include "../vista/CargadorDeTextures.h"
#include "zonaToolBar/ZonaToolBar.h"
#include "inicializador/InicializadorJuego.h"
#include "ToolBarController.h"
#include "ToolBarEventController.h"
#include "CanvasController.h"

MainController::MainController() {
	this->dropController = new JuegoEventsController();
}

MainController::~MainController() {
}

void taparHueco(SDL_Renderer * renderer){
	SDL_Rect dest;
	Resizer * r= Resizer::Instance();
	dest.x = 0;
	dest.y= r->resizearDistanciaLogicaY(100);
	dest.w= r->resizearDistanciaLogicaX(120);
	dest.h= r->resizearDistanciaLogicaY(20);
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderFillRect(renderer,&dest);
}
int MainController::run() {
	SDL_Window *ventana = NULL;
//	int draggin = false;
	bool terminar = false;
	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("The Incredible Fail", 400, 400, 600, 600,
			SDL_WINDOW_RESIZABLE);
	SDL_Renderer* render = SDL_CreateRenderer(ventana, -1,
			SDL_RENDERER_ACCELERATED);


	Resizer::Instance(600, 600, 120, 120);
	CargadorDeTextures * texturas = CargadorDeTextures::Instance(render);

	InicializadorJuego inicializador(render,dropController);

	ZonaJuego * zona =  inicializador.crearZonaJuego();
	ZonaToolBar* toolBar = new ZonaToolBar(0, 500 ,600, 100, texturas->cargarTexture("resource/fondoHerramientas.jpg"));
	ToolBarEventController* tbEventController = new ToolBarEventController(toolBar);
//	ToolBarController* toolbarController = new ToolBarController(toolBar, tbEventController);
	CanvasController* canvasController = new CanvasController(zona->getCanvas());
	GeneralEventController eventController;
	eventController.addCanvasController(canvasController);
	eventController.addMouseController(this->dropController,1,1);
	eventController.addMouseController(tbEventController, 2, 1);
	eventController.addKeyboardController(tbEventController);
	DraggingView vista(this->dropController);
	RotationView vistaRotacion(this->dropController, texturas->cargarTexture("resource/rotacion.png"));
	this->dropController->setZona(zona);
	while(!terminar){
		SDL_Delay(5);
		terminar = eventController.procesarEventos(ventana);
		SDL_SetRenderDrawColor(render,1,1,1,1);
		SDL_RenderClear(render);

		zona->dibujarse(render);
		taparHueco(render);
		vista.dibujarse(render);
		vistaRotacion.dibujarse(render);
		toolBar->dibujarse(render);
		SDL_RenderPresent(render);
	}
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(ventana);
	//
	delete zona;

	return 0;
}


