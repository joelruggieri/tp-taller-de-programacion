/*
 * Partida.h
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#ifndef PARTIDA_H_
#define PARTIDA_H_
#include <src/Nivel.h>
class Partida {

//La partida comienza a recibir a los clientes y empieza a pasarle el control a cada  thread que atiende y controlar el numero maximo de clientes.

public:
	Partida(Nivel * n);
	virtual ~Partida();
	void run();
};

#endif /* PARTIDA_H_ */
