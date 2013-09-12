/*
 * MainController.cpp
 *
 *  Created on: 8/09/2013
 *      Author: jonathan
 */

#include "MainController.h"
#include "zonaDragAndDrop/ZonaJuego.h"
#include "zonaDragAndDrop/ZonaCreacion.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include "Resizer.h"
#include "viewFactory/ViewCirculoFactory.h"
#include "viewFactory/ViewCuadradoFactory.h"
#include "viewFactory/ViewTrianguloFactory.h"
#include "GeneralEventController.h"
#include "../vista/DraggingView.h"
#include "../vista/RotationView.h"
MainController::MainController() {
	this->dropController = new JuegoEventsController();
}

MainController::~MainController() {
}

SDL_Texture* MainController::cargarTexture(const string &file,
		SDL_Renderer* ren) {
	SDL_Texture* texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == NULL)
		cout << "IMG_Load error: " << IMG_GetError() << endl;

	return texture;
}

int MainController::run() {
	SDL_Window *ventana = NULL;
//	int draggin = false;
	Resizer::Instance(800, 600, 120, 120);
	bool terminar = false;
	SDL_Init(SDL_INIT_VIDEO);
	ventana = SDL_CreateWindow("Hola mundo", 400, 400, 800, 600,
			SDL_WINDOW_RESIZABLE);
	SDL_Renderer* render = SDL_CreateRenderer(ventana, -1,
			SDL_RENDERER_ACCELERATED);
	Zona * zona = crearZonaJuego(render);

	GeneralEventController eventController;
	eventController.addMouseController(this->dropController,1,1);
	DraggingView vista(this->dropController);
	RotationView vistaRotacion(this->dropController, cargarTexture("resource/rotacion.png",render));
	this->dropController->setZona(zona);
	while(!terminar){
		SDL_Delay(5);
		terminar = eventController.procesarEventos();
		SDL_SetRenderDrawColor(render,1,1,1,1);
		SDL_RenderClear(render);
		zona->dibujarse(render);
		vista.dibujarse(render);
		vistaRotacion.dibujarse(render);
		SDL_RenderPresent(render);
	}
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(ventana);
	//
	delete zona;

	return 0;
}

Zona* MainController::crearZonaJuego(SDL_Renderer* renderer) {

	//TODO VER DONDE ENCAPSULAR ESTA LOGICA.
	// 5 margen izq
	// 100 tablero
	// 10 entre los dos paneles
	// 20 la zona creacion
	// 5 margen izquierdo

	list<ViewFiguraFactory*> factories;
	SDL_Texture* canvasTexture = this->cargarTexture("resource/Fondo4.jpg",
			renderer);
	SDL_Texture* herrTextura = this->cargarTexture("resource/fondoHerramientas.jpg",
			renderer);
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewTrianguloFactory(renderer, dropController));
	factories.push_back(new ViewCirculoFactory(renderer, dropController));
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewTrianguloFactory(renderer, dropController));
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewCirculoFactory(renderer, dropController));

	Zona* zonaCreacion = new ZonaCreacion(&factories, 110, 0,
			herrTextura);
	Zona* zonaTablero = new ZonaTablero(new Mapa(),50,50, canvasTexture);
	return new ZonaJuego(zonaCreacion, zonaTablero,
			new Cuadrado(75, 50, 150, 100));
}
