/*
 * UserEventVisitor.h
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#ifndef USEREVENTVISITOR_H_
#define USEREVENTVISITOR_H_

class ClickMsj;
class KeyMsj;
class MouseMotionMsj;
class JugadorListo;
class CreacionMsj;
class UserEventVisitor {
public:
	virtual ~UserEventVisitor(){}
	virtual void visit(MouseMotionMsj *) = 0;
	virtual void visit(ClickMsj *) = 0;
	virtual void visit(KeyMsj *) = 0;
	virtual void visit(JugadorListo *) = 0;
	virtual void visit(CreacionMsj*) = 0;
};

#endif /* USEREVENTVISITOR_H_ */
