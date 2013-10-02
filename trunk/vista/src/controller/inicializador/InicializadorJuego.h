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
#include "../../vista/Canvas.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include "../PersistenciaManager.h"
#include "../JuegoEventsController.h"
#include "../GeneralEventController.h"
#include "../RotadorSistemaCoordenadas.h"
#include <map>
#include "src/figura/Circulo.h"
#include "../../modelo/Cuadrado.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Rueda.h"
#include "src/figura/Globo.h"
#include "src/figura/Pelota.h"
#include "src/objeto/Motor.h"
#include "src/objeto/Plataforma.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
using namespace std;

class InicializadorJuego: public VisitorFigura {
private:
	ZonaTablero* tablero;
	map<string, ViewFiguraFactory *> figuraFactory;
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
	void visit(Motor*);
	void visit(Plataforma*);
	JuegoEventsController * crearZonaJuego();
};

#endif /* INICIALIZADORJUEGO_H_ */
