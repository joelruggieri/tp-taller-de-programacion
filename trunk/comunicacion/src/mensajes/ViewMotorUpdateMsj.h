/*
 * ViewMotorUpdateMsj.h
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWMOTORUPDATEMSJ_H_
#define VIEWMOTORUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"
class ViewMotorUpdateMsj : public ViewObjetoUpdateMsj	{
public:
	ViewMotorUpdateMsj(float, float , float);
	virtual ~ViewMotorUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
	private:
	//	float x,y;
	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWMOTORUPDATEMSJ_H_ */
