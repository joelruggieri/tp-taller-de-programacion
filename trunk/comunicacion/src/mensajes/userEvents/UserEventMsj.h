/*
 * UserEventMsj.h
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#ifndef USEREVENTMSJ_H_
#define USEREVENTMSJ_H_
#include "../NetworkMensaje.h"
#include "UserEventVisitor.h"
class UserEventMsj {
private:
	bool shift,ctrl;
public:
	UserEventMsj(bool shift, bool ctrl);
	virtual void procesar(UserEventVisitor *) = 0;
	virtual ~UserEventMsj();
};

#endif /* USEREVENTMSJ_H_ */
