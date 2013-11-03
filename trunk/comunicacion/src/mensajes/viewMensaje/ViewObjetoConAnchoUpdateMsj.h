/*
 * ViewObjetoConAnchoUpdateMsj.h
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#ifndef VIEWOBJETOCONANCHOUPDATEMSJ_H_
#define VIEWOBJETOCONANCHOUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"
#include "yaml-cpp/yaml.h"

using namespace std;

class ViewObjetoConAnchoUpdateMsj: public ViewObjetoUpdateMsj {
private:
	float ancho;
	typedef ViewObjetoUpdateMsj super;
public:
	ViewObjetoConAnchoUpdateMsj(float, float, float, float, int);
	virtual ~ViewObjetoConAnchoUpdateMsj();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	void getMensaje();
	string getTag();
};

#endif /* VIEWOBJETOCONANCHOUPDATEMSJ_H_ */
