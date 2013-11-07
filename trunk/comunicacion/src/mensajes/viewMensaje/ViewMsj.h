/*
 * ViewMsj.h
 *
 *  Created on: 02/11/2013
 *      Author: jonathan
 */

#ifndef VIEWMSJ_H_
#define VIEWMSJ_H_
#include "../NetworkMensaje.h"
#include "ViewMsjVisitor.h"
class ViewMsj: public NetworkMensaje {
protected:
	int id;
	char selector;
public:
	ViewMsj(int id, char sel);
	virtual ~ViewMsj();
	void acept(MensajeVisitor *);
	virtual void acept(ViewMsjVisitor *)=0;
	char getSelector();
		int getId();
};

#endif /* VIEWMSJ_H_ */
