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
#include "GeneralEventController.h"
#include "JuegoEventsController.h"
#include "Resizer.h"
#include "src/Logger.h"
#include "UserEventCreator.h"
#include "../ConstantesVista.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include "src/threading/EventReceptorThread.h"
#include "MensajesServerReceptor.h"
#include <string>
#include <list>
using namespace std;



namespace CLIENTE {

MainController::MainController(ColaEventos* entrada,ColaEventos * salida,Status* st) {
	Logger::setNivel(DEBUG_N);
	this->entrada = entrada;
	this->salida = salida;
	viewController = NULL;
	juegoController = NULL;
	render = NULL;
	this->status = st;
}

MainController::~MainController() {
}

Uint32 my_callbackfunc(Uint32 interval, void *param) {
	SDL_Event event = crearEvento(USREVENT_DRAW, NULL, NULL);
	SDL_PushEvent(&event);
	return (interval);
}

int MainController::run(list<string> & factories) {
	SDL_Window *ventana = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("The Incredible Machine LAN", 300, 100, TAMANIO_PANTALLA, TAMANIO_PANTALLA, SDL_WINDOW_RESIZABLE);
	render = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
	Cuadrado cuadrado = Cuadrado(this->xArea, this->yArea, this->wArea,this->hArea);
	viewController = new ViewController(render, Resizer::crearTransformacionALogica(TAMANIO_PANTALLA,TAMANIO_PANTALLA), cuadrado, this->objetivo);
	StatusJuego juegoStatus;
	GeneralEventController * eventController = crearGeneralEventController(factories,juegoStatus);
	eventController->setDrawController(viewController);
	eventController->addResizerController(viewController);
	MensajesServerReceptor juego(&juegoStatus);

	//Creo el thread que se encarga de distribuir los msjs que vienen del server server
	EventReceptorThread receptor(this->entrada, NULL, this->viewController, &juego, NULL);
	receptor.run();
	int timerID =SDL_AddTimer(1000/VELOCIDAD_REFRESCO_VISTA, my_callbackfunc, NULL);
	SDL_SetWindowMaximumSize(ventana, 825,825);
	SDL_SetWindowPosition(ventana, 300, 100);
	bool terminar = false;
	while (!juegoStatus.isTerminado() && status->isAlive() && !terminar) {
		usleep(1000000.0/VELOCIDAD_REFRESCO);
		terminar = eventController->procesarEventos(ventana);
	}
	if(terminar){
		log.info("Finalizando Juego");
	} else {
		if(juegoStatus.isTerminado()){
			if (juegoStatus.isGanado()) {
				log.info("Juego Ganado!");
			} else {
				log.info("Juego Perdido");
			}
		} else {
			log.error("El server no responde, finalizando juego");
		}

	}
	receptor.cancel();
	sleep(1);
	SDL_RemoveTimer(timerID);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(ventana);
	delete eventController;
	return 0;
}

GeneralEventController* MainController::crearGeneralEventController(list<string> & factories, StatusJuego & statusjuego) {
	ZonaTablero * tablero = new ZonaTablero(viewController,this->salida);
	ZonaPlay * zp = new ZonaPlay(viewController,110, 90, this->salida);
	ZonaCreacion* zonaCreacion = new ZonaCreacion(viewController, factories, 110, 80, salida);
	JuegoEventsController * juegoController = new JuegoEventsController(zp,tablero, zonaCreacion,&statusjuego,Resizer::crearTransformacionALogica(TAMANIO_PANTALLA,TAMANIO_PANTALLA));
	GeneralEventController * generalEventController = new GeneralEventController();
	generalEventController->addMouseController(juegoController, 1, 1);
	generalEventController->addResizerController(juegoController);
	return generalEventController;
}

ViewController* MainController::getviewController() {
	return viewController;
}
void MainController::setCoordenadasArea(float float1, float float2,
		float float3, float float4) {
	this->xArea = float1;
	this->yArea= float2;
	this->wArea = float3;
	this->hArea = float4;
}
void MainController::setObjetivo(const string& objetivo) {
	this->objetivo = objetivo;
}
}

