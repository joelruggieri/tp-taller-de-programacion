/*
 * NetworkMensaje.h
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#ifndef NETWORKMENSAJE_H_
#define NETWORKMENSAJE_H_
#include <string>
using namespace std;

class NetworkMensaje {
private:
	//TODO EZE ESTE ES EL TIPO CORRECTO PARA EL DESCRIPTOR DEL DESTINATARIO?
	int destinatario;

public:
	NetworkMensaje(int destinatario);
	//TODO ESTO PODRÍA SER UN ARRAY DE BITS O ALGO ASI??? TIENE QUE SER SI O SI STRING? QUE PROBLEMAS TENEMOS?
	virtual string serialize();
	virtual ~NetworkMensaje();
	int getDestinatario();
	void setDestinatario(int destinatario);


};

#endif /* NETWORKMENSAJE_H_ */
