/*
 * ViewPlataformaUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWPLATAFORMAUPDATEMSJ_H_
#define VIEWPLATAFORMAUPDATEMSJ_H_
#include "NetworkMensaje.h"
class ViewPlataformaUpdateMsj : public NetworkMensaje {
public:
	ViewPlataformaUpdateMsj(float, float, float);
	virtual ~ViewPlataformaUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
private:
	float x,y, ancho;
};

#endif /* VIEWPLATAFORMAUPDATEMSJ_H_ */
