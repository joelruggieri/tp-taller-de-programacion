/*
 * ViewBolaBolicheUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWBOLABOLICHEUPDATEMSJ_H_
#define VIEWBOLABOLICHEUPDATEMSJ_H_
#include "NetworkMensaje.h"
#include "ViewObjetoUpdateMsj.h"
class ViewBolaBolicheUpdateMsj: public ViewObjetoUpdateMsj {
public:
	ViewBolaBolicheUpdateMsj(float, float, float,int);
	virtual ~ViewBolaBolicheUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
private:
//	float x, y, angulo;
	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWBOLABOLICHEUPDATEMSJ_H_ */
