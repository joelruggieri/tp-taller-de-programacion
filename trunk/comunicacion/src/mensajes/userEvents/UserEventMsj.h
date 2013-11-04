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
class UserEventMsj: public NetworkMensaje {
private:
	bool shift,ctrl;
public:
	UserEventMsj(bool shift, bool ctrl);
	virtual void procesar(UserEventVisitor *) = 0;
	virtual ~UserEventMsj();
	bool isCtrl() const;
	bool isShift() const;
};

#endif /* USEREVENTMSJ_H_ */
