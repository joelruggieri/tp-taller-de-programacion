/*
 * ViewSogaUpdateMje.h
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWSOGAUPDATEMJE_H_
#define VIEWSOGAUPDATEMJE_H_
#include "ViewObjetoUpdateMsj.h"
class ViewSogaUpdateMje : public ViewObjetoUpdateMsj {
public:
	ViewSogaUpdateMje(float, float, float ,float);
	virtual ~ViewSogaUpdateMje();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
private:
//	float x,y;
	float xDesde,yDesde,xHasta,yHasta;
//	typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWSOGAUPDATEMJE_H_ */
