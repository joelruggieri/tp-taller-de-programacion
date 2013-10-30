/*
 * ColaSalida.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef COLASALIDA_H_
#define COLASALIDA_H_
#include "../comunicacion/NetworkMensaje.h"
#include "ObjetoCompartido.h"
class ColaEventos: public ObjetoCompartido {
public:
	ColaEventos();
	void push(NetworkMensaje * msj);
	NetworkMensaje * front();
	virtual ~ColaEventos();
};

#endif /* COLASALIDA_H_ */
