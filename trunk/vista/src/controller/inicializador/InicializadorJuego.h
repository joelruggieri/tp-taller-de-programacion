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
#include "../../modelo/Cuadrado.h"


#include "src/objeto/Motor.h"
#include "src/objeto/Plataforma.h"
#include "src/objeto/Balancin.h"
#include "src/objeto/GloboHelio.h"
#include "src/objeto/PelotaJuego.h"
#include "src/objeto/CintaTransportadora.h"
#include "src/objeto/BolaBoliche.h"
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
	void visit(Motor*);
	void visit(Plataforma*);
	void visit(Balancin*);
	void visit(GloboHelio*);
	void visit(CintaTransportadora*);
	void visit(BolaBoliche*);
	void visit(PelotaJuego*);
	JuegoEventsController * crearZonaJuego();
};

#endif /* INICIALIZADORJUEGO_H_ */
