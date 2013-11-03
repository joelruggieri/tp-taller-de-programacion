/*
 * ViewCintaUpdateMsj.h
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWCINTAUPDATEMSJ_H_
#define VIEWCINTAUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"
class ViewCintaUpdateMsj : public ViewObjetoUpdateMsj {
public:
	ViewCintaUpdateMsj(float, float, float, float, int);
	virtual ~ViewCintaUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
private:
//	float x,y, ancho;
	float ancho;
	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWCINTAUPDATEMSJ_H_ */
