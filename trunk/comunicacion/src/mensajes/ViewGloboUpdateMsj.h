/*
 * ViewGloboUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#ifndef VIEWGLOBOUPDATEMSJ_H_
#define VIEWGLOBOUPDATEMSJ_H_

#include "NetworkMensaje.h"

class ViewGloboUpdateMsj: public NetworkMensaje {
public:
	ViewGloboUpdateMsj(float x, float y);
	virtual ~ViewGloboUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
private:
	float x,y;
};

#endif /* VIEWGLOBOUPDATEMSJ_H_ */
