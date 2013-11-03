/*
 * MensajeVisitor.h
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#ifndef MENSAJEVISITOR_H_
#define MENSAJEVISITOR_H_

class UserEventMsj;
class ViewMsj;
class MensajePlano;
class MensajeVisitor {
public:
	virtual ~MensajeVisitor(){}
	virtual void visit(UserEventMsj *) = 0;
	virtual void visit(ViewMsj *) = 0;
	virtual void visit(MensajePlano *) = 0;
};

#endif /* MENSAJEVISITOR_H_ */
