/*
 * ViewSogaUpdateMsj.h
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#ifndef VIEWSOGAUPDATEMSJ_H_
#define VIEWSOGAUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"
using namespace std;

class ViewSogaUpdateMsj: public ViewObjetoUpdateMsj {
public:
	ViewSogaUpdateMsj(float, float, float ,float,int);
	virtual ~ViewSogaUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
private:
//	float x,y;
	float xDesde,yDesde,xHasta,yHasta;
//	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWSOGAUPDATEMSJ_H_ */
