/*
 * Partida.h
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_
#include <src/Nivel.h>
#include "src/threading/ColaEventos.h"
#include "threading/Disponibilidad.h"
#include <list>
#include "threading/EventDispatcherThread.h"
#include "src/threading/EventReceptorThread.h"
#include "threading/ThreadCleaner.h"
#include "src/Serializador.h"
#include "src/controller/GeneralEventController.h"
#include "src/controller/inicializador/InicializadorJuego.h"
#include "threading/DrawThread.h"
#include "threading/StepModeloThread.h"
#include "src/controller/inicializador/JuegoControllerFactory.h"
#include "src/controller/zonaDragAndDrop/ZonaTablero.h"
#include "threading/RecepcionClientesThread.h"
#include "src/controller/objetivosJuegos/ObjetivoJuego.h"
using namespace std;

class Partida {

//La partida comienza a recibir a los clientes y empieza a pasarle el control a cada  thread que atiende. controla el numero maximo de clientes.
private:
	ColaEventos * colaIn,  *colaOut;
	Disponibilidad * dispo;
	Nivel * nivel;
	EventDispatcherThread * dispatcher;
	EventReceptorThread * receiver;
	ThreadCleaner * cleaner;
	GeneralEventController * generalController;
	DrawThread * drawingService;
	StepModeloThread * fisicaService;
	JuegoControllerFactory * controllersFactory;
	ZonaTablero * tablero;
	ModeloController * modeloController;
	InicializadorJuego* inicializadorJuego;
	RecepcionClientesThread* recepcionThread;
	ObjetivoJuego * objetivo;
	Logger log;
	void iniciarGeneralEventController();
public:
	Partida(Nivel * n, int socket);
	virtual ~Partida();
	void run(int fdJugador1);
};

#endif /* PARTIDA_H_ */
