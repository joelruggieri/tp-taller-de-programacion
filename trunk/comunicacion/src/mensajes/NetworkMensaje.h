/*
 * NetworkMensaje.h
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#ifndef NETWORKMENSAJE_H_
#define NETWORKMENSAJE_H_
#include <string>
#include "yaml-cpp/yaml.h"
using namespace std;

class NetworkMensaje {
private:
	//TODO EZE ESTE ES EL TIPO CORRECTO PARA EL DESCRIPTOR DEL DESTINATARIO?
	int destinatario;

public:
	NetworkMensaje();
	//TODO ESTO PODRÍA SER UN ARRAY DE BITS O ALGO ASI??? TIENE QUE SER SI O SI STRING? QUE PROBLEMAS TENEMOS?
	virtual ~NetworkMensaje();
	int getDestinatario();
	void setDestinatario(int destinatario);
	virtual void serialize(YAML::Node * nodo) = 0;
	//RECIBE UN ITERADOR DESDE DONDE LEER SUS VALORES, EL TAG DEL MSJ YA ESTA LEIDO A ESTA ALTURA.
	virtual NetworkMensaje * deserialize(YAML::const_iterator &) = 0;

};

#endif /* NETWORKMENSAJE_H_ */
