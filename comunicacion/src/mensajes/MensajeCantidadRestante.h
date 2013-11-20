/*
 * MensajeCantidadRestante.h
 *
 *  Created on: 19/11/2013
 *      Author: ezequiel
 */

#ifndef MENSAJECANTIDADRESTANTE_H_
#define MENSAJECANTIDADRESTANTE_H_
#include "viewMensaje/ViewMsj.h"
#include "yaml-cpp/yaml.h"
class MensajeCantidadRestante : public ViewMsj{
public:
	MensajeCantidadRestante(int id , int cantidad);
	virtual ~MensajeCantidadRestante();
	void serialize(YAML::Emitter &out);
	NetworkMensaje* deserialize(YAML::const_iterator & it);
	string getTag();
	void acept(ViewMsjVisitor*);
	ViewMsj* clone(int dest);

	int getCantidadRestante() const {
		return cantidadRestante;
	}

private:
	int cantidadRestante ;


};

#endif /* MENSAJECANTIDADRESTANTE_H_ */
