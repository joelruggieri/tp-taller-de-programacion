/*
 * ClickDownMsj.h
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#ifndef CLICKDOWNMSJ_H_
#define CLICKDOWNMSJ_H_

#include "UserEventMsj.h"

class ClickMsj: public UserEventMsj {
private:
	float x, y;
	bool down, left;
public:
	ClickMsj(float x, float y, bool down, bool left, bool shift, bool ctrl);
	void procesar(UserEventVisitor *);
	virtual ~ClickMsj();
};

#endif /* CLICKDOWNMSJ_H_ */
