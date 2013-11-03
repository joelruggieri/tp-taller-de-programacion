/*
 * ViewPlataformaUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWPLATAFORMAUPDATEMSJ_H_
#define VIEWPLATAFORMAUPDATEMSJ_H_
#include "NetworkMensaje.h"
#include "ViewObjetoUpdateMsj.h"
class ViewPlataformaUpdateMsj : public ViewObjetoUpdateMsj {
public:
	ViewPlataformaUpdateMsj(float, float, float, float, int);
//	virtual ~ViewPlataformaUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
private:
//	float x,y, ancho;
	float ancho;
	typedef ViewObjetoUpdateMsj super;

};

#endif /* VIEWPLATAFORMAUPDATEMSJ_H_ */
