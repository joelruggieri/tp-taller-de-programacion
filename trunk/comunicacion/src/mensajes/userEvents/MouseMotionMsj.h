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
	virtual ~MouseMotionMsj();
};

#endif /* MOUSEMOTION_H_ */
