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
#include "../viewFactory/ViewFiguraFactory.h"
#include <map>
#include "../../modelo/Cuadrado.h"

#include "src/objeto/Gancho.h"
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
#include "src/Nivel.h"
#include "src/ModeloController.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
using namespace std;

class InicializadorJuego: public VisitorFigura {
private:
	ZonaTablero* tablero;
	map<string, ViewFiguraFactory *> figuraFactory;
	Nivel* nivel;
	//JuegoEventsController * juegoController;
	//GeneralEventController * eventsController;
	//PersistenciaManager * bbdd;
	ModeloController * modeloController;
	FiguraFactory * factory;
	//ValidadorEstatico * validador;
	void agregarFigura(ViewFiguraFactory * factory, Figura * modelo);
	void agregarUnion(ViewFiguraFactory * factory, Union * modelo);
public:
	InicializadorJuego(Nivel* nivel, ModeloController * modeloController);
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
	void visit(Gancho*);
	ZonaTablero* crearTablero();
};

#endif /* INICIALIZADORJUEGO_H_ */
