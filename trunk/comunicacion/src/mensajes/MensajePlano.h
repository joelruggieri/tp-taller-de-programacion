/*
 * MensajePlano.h
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#ifndef MENSAJEPLANO_H_
#define MENSAJEPLANO_H_

#include "NetworkMensaje.h"
#include <string>
using namespace std;

//ESTE MENSAJE ES EL QUE SE ENVIAN EL SERVER Y EL CLIENTE, ES PLANO PORQUE ES UN SOLO DATO.
class MensajePlano: public NetworkMensaje {
private:
	string msj;
public:
	MensajePlano(string m);
	virtual ~MensajePlano();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getMensaje();
	string getTag();
	void acept(MensajeVisitor *);
};

#endif /* MENSAJEPLANO_H_ */
