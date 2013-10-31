/*
 * ViewPelotaUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWPELOTAUPDATEMSJ_H_
#define VIEWPELOTAUPDATEMSJ_H_
#include "NetworkMensaje.h"
#include "ViewObjetoUpdateMsj.h"
class ViewPelotaUpdateMsj : public ViewObjetoUpdateMsj{
public:
	ViewPelotaUpdateMsj(float x, float y, float angulo);
	virtual ~ViewPelotaUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	void getMensaje();
	string getTag();
private:
//	float x,y;

	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWPELOTAUPDATEMSJ_H_ */
