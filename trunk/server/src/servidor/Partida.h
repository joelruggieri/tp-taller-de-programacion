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
#include "threading/EventReceptorThread.h"
#include "threading/ThreadCleaner.h"
#include "src/Serializador.h"
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
	int socket;
	Logger log;
	void procesarRequest(int socketDesc, Serializador & serializador);
public:
	Partida(Nivel * n, int socket);
	virtual ~Partida();
	void run(int fdJugador1);
};

#endif /* PARTIDA_H_ */
