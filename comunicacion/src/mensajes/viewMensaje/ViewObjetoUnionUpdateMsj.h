/*
 * ViewObjetoUnionUpdateMsj.h
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#ifndef VIEWOBJETOUNIONUPDATEMSJ_H_
#define VIEWOBJETOUNIONUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"

class ViewObjetoUnionUpdateMsj: public ViewObjetoUpdateMsj {
private:
	float xHasta,yHasta;
public:
	ViewObjetoUnionUpdateMsj(float, float, float ,float,int);
	virtual ~ViewObjetoUnionUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
};

#endif /* VIEWOBJETOUNIONUPDATEMSJ_H_ */
