/*
 * MouseMotion.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "MouseMotionMsj.h"

MouseMotionMsj::MouseMotionMsj(float x, float y, bool shift, bool ctrl):UserEventMsj(shift, ctrl) {
	this->x = x;
	this->y = y;
}

MouseMotionMsj::~MouseMotionMsj() {
	// TODO Auto-generated destructor stub
}

