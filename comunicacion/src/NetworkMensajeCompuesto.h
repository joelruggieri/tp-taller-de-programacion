/*
 * NetworkMensajeCompuesto.h
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#ifndef NETWORKMENSAJECOMPUESTO_H_
#define NETWORKMENSAJECOMPUESTO_H_
#include <list>
#include <string>
#include "NetworkMensaje.h"
using namespace std;



class NetworkMensajeCompuesto: public NetworkMensaje {
private:
	list<NetworkMensaje*> mensajes;
public:
	NetworkMensajeCompuesto(int);
	virtual ~NetworkMensajeCompuesto();
	void addMensaje(NetworkMensaje * mensaje);
	string serialize();
};

#endif /* NETWORKMENSAJECOMPUESTO_H_ */
