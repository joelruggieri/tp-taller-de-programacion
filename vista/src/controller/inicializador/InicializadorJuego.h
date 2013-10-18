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
#include <map>
#include "../../modelo/Cuadrado.h"
#include "ValidadorEstatico.h"

#include "src/objeto/Motor.h"
#include "src/objeto/Plataforma.h"
#include "src/objeto/Balancin.h"
#include "src/objeto/GloboHelio.h"
#include "src/objeto/PelotaJuego.h"
#include "src/objeto/CintaTransportadora.h"
#include "src/objeto/BolaBoliche.h"
#include "src/objeto/Engranaje.h"
#include "src/objeto/Correa.h"
#include "src/objeto/Union.h"
#include "src/objeto/Soga.h"
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
	FiguraFactory * factory;
	ValidadorEstatico * validador;
	void agregarFigura(ViewFiguraFactory * factory, Figura * modelo);
	void agregarUnion(ViewFiguraFactory * factory, Union * modelo);
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
	void visit(Engranaje*);
	void visit(Correa*);
	void visit(Soga*);
	JuegoEventsController * crearZonaJuego();
};

#endif /* INICIALIZADORJUEGO_H_ */
