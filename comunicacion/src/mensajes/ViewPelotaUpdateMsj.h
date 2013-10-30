/*
 * ViewPelotaUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWPELOTAUPDATEMSJ_H_
#define VIEWPELOTAUPDATEMSJ_H_
#include "NetworkMensaje.h"
class ViewPelotaUpdateMsj : public NetworkMensaje{
public:
	ViewPelotaUpdateMsj(float x, float y);
	virtual ~ViewPelotaUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
private:
	float x,y;
};

#endif /* VIEWPELOTAUPDATEMSJ_H_ */
