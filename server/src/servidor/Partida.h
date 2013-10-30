/*
 * Partida.h
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_
#include <src/Nivel.h>
#include "ColaEventos.h"
#include "Disponibilidad.h"
#include <list>
#include "EventDispatcherThread.h"
#include "EventReceptorThread.h"
using namespace std;

class Partida {

//La partida comienza a recibir a los clientes y empieza a pasarle el control a cada  thread que atiende. controla el numero maximo de clientes.
private:
	ColaEventos * cola;
	Disponibilidad * dispo;
	Nivel * nivel;
	EventDispatcherThread * dispatcher;
	EventReceptorThread * receiver;
public:
	Partida(Nivel * n);
	virtual ~Partida();
	void run();
};

#endif /* PARTIDA_H_ */
