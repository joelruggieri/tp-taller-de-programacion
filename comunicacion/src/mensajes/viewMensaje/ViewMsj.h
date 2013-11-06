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
public:
	ViewMsj(int id);
	virtual ~ViewMsj();
	void acept(MensajeVisitor *);
	void acept(ViewMsjVisitor *);
};

#endif /* VIEWMSJ_H_ */
