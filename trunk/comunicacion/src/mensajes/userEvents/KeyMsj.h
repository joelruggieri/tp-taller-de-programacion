/*
 * KeyMsj.h
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#ifndef KEYMSJ_H_
#define KEYMSJ_H_

#include "UserEventMsj.h"

class KeyMsj: public UserEventMsj {
private:
	char chara;
	bool pressed;
public:
	KeyMsj(char character, bool pressed, bool shift, bool ctrl);
	void procesar(UserEventVisitor *);
	virtual ~KeyMsj();
};

#endif /* KEYMSJ_H_ */
