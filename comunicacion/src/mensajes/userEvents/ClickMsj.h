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
	void acept(UserEventVisitor *);
	virtual ~ClickMsj();
	bool isDown() const;
	bool isLeft() const;
	float getX() const;
	float getY() const;
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
};

#endif /* CLICKDOWNMSJ_H_ */
