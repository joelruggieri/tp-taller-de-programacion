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
	void procesar(UserEventVisitor *);
	virtual ~MouseMotionMsj();
	float getX();
	float getY();
};

#endif /* MOUSEMOTION_H_ */
