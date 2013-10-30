/*
 * ViewBolaBolicheUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWBOLABOLICHEUPDATEMSJ_H_
#define VIEWBOLABOLICHEUPDATEMSJ_H_
#include "NetworkMensaje.h"
class ViewBolaBolicheUpdateMsj : public NetworkMensaje {
public:
	ViewBolaBolicheUpdateMsj(float, float);
	virtual ~ViewBolaBolicheUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
private:
	float x,y ;
};

#endif /* VIEWBOLABOLICHEUPDATEMSJ_H_ */
