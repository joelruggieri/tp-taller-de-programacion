/*
 * NetworkSender.h
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#ifndef NETWORKEVENTSENDER_H_
#define NETWORKEVENTSENDER_H_
#include "NetworkMensaje.h"
/**
 * Esta clase debe recibir un socket en el constructor para hacer los envios
 */
class NetworkSender {
public:
	NetworkSender();
	virtual ~NetworkSender();
	void send(NetworkMensaje * msj);
};

#endif /* NETWORKEVENTSENDER_H_ */
