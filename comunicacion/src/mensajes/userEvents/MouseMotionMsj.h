/*
 * MouseMotion.h
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#ifndef MOUSEMOTION_H_
#define MOUSEMOTION_H_

#include "UserEventMsj.h"

class MouseMotionMsj: public UserEventMsj {
private:
	float x, y;
public:
	MouseMotionMsj(float x, float y, bool shift, bool ctrl);
	void acept(UserEventVisitor *);
	virtual ~MouseMotionMsj();
	float getX();
	float getY();
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
};

#endif /* MOUSEMOTION_H_ */
