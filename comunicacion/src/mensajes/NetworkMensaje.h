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
#include "MensajeVisitor.h"
#include "../ConstantesComunicacion.h"
using namespace std;

class NetworkMensaje {
private:
	int destinatario;
public:

	NetworkMensaje();
	virtual ~NetworkMensaje() ;
	int getDestinatario();
	void setDestinatario(int destinatario);
	virtual void serialize(YAML::Emitter & out) = 0;
	//RECIBE UN ITERADOR DESDE DONDE LEER SUS VALORES, EL TAG DEL MSJ YA ESTA LEIDO A ESTA ALTURA.
	virtual NetworkMensaje * deserialize(YAML::const_iterator &) = 0;
	virtual void acept(MensajeVisitor *) = 0;
};

#endif /* NETWORKMENSAJE_H_ */
