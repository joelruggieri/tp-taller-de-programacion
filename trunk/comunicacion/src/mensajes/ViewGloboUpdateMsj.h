/*
 * ViewGloboUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#ifndef VIEWGLOBOUPDATEMSJ_H_
#define VIEWGLOBOUPDATEMSJ_H_

//#include "NetworkMensaje.h"
#include "ViewObjetoUpdateMsj.h"
class ViewGloboUpdateMsj: public ViewObjetoUpdateMsj {
public:
	ViewGloboUpdateMsj(float x, float y, float angulo, int id);
	virtual ~ViewGloboUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
private:
//	float x,y;
	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWGLOBOUPDATEMSJ_H_ */
