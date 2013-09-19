/*
 * InicializadorJuego.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef INICIALIZADORJUEGO_H_
#define INICIALIZADORJUEGO_H_
#include "src/figura/VisitorFigura.h"
#include "../zonaDragAndDrop/ZonaDragAndDrop.h"
#include "../zonaDragAndDrop/ZonaJuego.h"
#include "../../vista/Canvas.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include "../PersistenciaManager.h"
#include "../JuegoEventsController.h"
#include "../GeneralEventController.h"
#include <map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "src/figura/Circulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Triangulo.h"
using namespace std;

class InicializadorJuego: public VisitorFigura {
private:
	ZonaJuego* zonaJuego;
	map<string, ViewFiguraFactory *> figuraFactory;
	SDL_Renderer * renderer;
	JuegoEventsController * juegoController;
	GeneralEventController * eventsController;
	PersistenciaManager * bbdd;
	ModeloController * modeloController;
	void agregarFigura(ViewFiguraFactory * factory, Figura * modelo);
public:
	InicializadorJuego(SDL_Renderer * renderer,
			GeneralEventController * eventsController, ModeloController * modeloController);
	virtual ~InicializadorJuego();
	void visit(Cuadrado*);
	void visit(Triangulo*);
	void visit(Circulo*);
	JuegoEventsController * crearZonaJuego();
};

#endif /* INICIALIZADORJUEGO_H_ */
