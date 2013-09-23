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
#include "../RotadorSistemaCoordenadas.h"
#include <map>
#include "src/figura/Circulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Rueda.h"
#include "src/figura/Globo.h"
#include "src/figura/Pelota.h"
#include "src/figura/Resorte.h"
#include "src/figura/Martillo.h"
#include "src/figura/Bloque.h"
#include "src/figura/Cohete.h"
#include "src/figura/Carrito.h"

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
	RotadorSistemaCoordenadas * rotador;
	FiguraFactory * factory;
	void agregarFigura(ViewFiguraFactory * factory, Figura * modelo);
public:
	InicializadorJuego(GeneralEventController * eventsController, ModeloController * modeloController);
	virtual ~InicializadorJuego();
	void visit(Cuadrado*);
	void visit(Triangulo*);
	void visit(Circulo*);
	void visit(Rueda*);
	void visit(Globo*);
	void visit(Pelota*);
	void visit(Resorte*);
	void visit(Martillo*);
	void visit(Bloque*);
	void visit(Cohete*);
	void visit(Carrito*);
	JuegoEventsController * crearZonaJuego();
};

#endif /* INICIALIZADORJUEGO_H_ */
