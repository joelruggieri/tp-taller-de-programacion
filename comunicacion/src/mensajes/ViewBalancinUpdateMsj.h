/*
 * ViewBalancinUpdateMsj.h
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWBALANCINUPDATEMSJ_H_
#define VIEWBALANCINUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"
class ViewBalancinUpdateMsj : public ViewObjetoUpdateMsj {
public:
	ViewBalancinUpdateMsj(float, float, float);
	virtual ~ViewBalancinUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
	private:
	//	float x,y;
	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWBALANCINUPDATEMSJ_H_ */
