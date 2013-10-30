/*
 * ColaSalida.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef COLAEVENTOS_H_
#define COLAEVENTOS_H_
#include "src/mensajes/NetworkMensaje.h"
#include "ObjetoCompartido.h"

//ENTREGA3 LA COLA DEBERIA INICIALIZARSE CON UN LIMITE. SI PASA ESE LIMITE DE MSJS, HACE CLEAN PARA NO SATURARSE CON COSAS QUE YA NO VAN.
//LOS MENSAJES PODRIAN TENER UN METODO QUE SEA LENGHT E INTERNAMENTE IR SUMANDO Y RESTANDO EN LOS SUCESIVOS PUSH Y FRONT
//PARA SABER EXACTAMENTE A CUANTO SE FUE LA COLA.

class ColaEventos: public ObjetoCompartido {
public:
	ColaEventos();
	void push(NetworkMensaje * msj);
	NetworkMensaje * front();
	virtual ~ColaEventos();
	void clear();
};

#endif /* COLAEVENTOS_H_ */
