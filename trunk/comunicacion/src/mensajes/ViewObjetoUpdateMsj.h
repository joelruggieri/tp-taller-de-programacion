/*
 * ViewObjetoUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWOBJETOUPDATEMSJ_H_
#define VIEWOBJETOUPDATEMSJ_H_
#include "NetworkMensaje.h"
class ViewObjetoUpdateMsj : public NetworkMensaje {
public:
	ViewObjetoUpdateMsj(float x, float y, float angulo);
	virtual ~ViewObjetoUpdateMsj();
	void serialize(YAML::Node * nodo);
	virtual NetworkMensaje * deserialize(YAML::const_iterator & it)=0;
	virtual string getTag()=0;
protected:
	float x,y, angulo;
};

#endif /* VIEWOBJETOUPDATEMSJ_H_ */
