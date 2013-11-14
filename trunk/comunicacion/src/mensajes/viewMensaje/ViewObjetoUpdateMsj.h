/*
 * ViewObjetoUpdateMsj.h
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWOBJETOUPDATEMSJ_H_
#define VIEWOBJETOUPDATEMSJ_H_
#include "ViewMsj.h"
#include "yaml-cpp/yaml.h"

class ViewObjetoUpdateMsj : public ViewMsj {
public:
	ViewObjetoUpdateMsj(float x, float y, float angulo, int id, char sel);
	virtual ~ViewObjetoUpdateMsj();
	virtual void serialize(YAML::Emitter & out);
	virtual NetworkMensaje * deserialize(YAML::const_iterator & it);
	virtual void getMensaje();
	virtual string getTag();
	void acept(ViewMsjVisitor *);
	float getAngulo() const;
	float getX() const;
	float getY() const;
	ViewMsj * clone(int dest);

protected:
	float x,y, angulo;
};

#endif /* VIEWOBJETOUPDATEMSJ_H_ */
