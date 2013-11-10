/*
 * ConexionUsuario.h
 *
 *  Created on: 09/11/2013
 *      Author: jonathan
 */

#ifndef CONEXIONUSUARIO_H_
#define CONEXIONUSUARIO_H_

#include "MensajeInterno.h"

class ConexionUsuario: public MensajeInterno {
private:
	bool conectado;
public:
	ConexionUsuario(bool on);
	virtual ~ConexionUsuario();
	bool isConectado() const;
	void acept(MensajeInternoVisitor *);
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator &);
};

#endif /* CONEXIONUSUARIO_H_ */
