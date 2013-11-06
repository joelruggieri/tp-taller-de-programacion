/*
 * ViewMsjVisitor.h
 *
 *  Created on: 5/11/2013
 *      Author: jonathan
 */

#ifndef VIEWMSJVISITOR_H_
#define VIEWMSJVISITOR_H_

class ViewMsj;

class ViewMsjVisitor {
public:
	virtual ~ViewMsjVisitor(){}
	virtual void visit(ViewMsj*) = 0;
};

#endif /* VIEWMSJVISITOR_H_ */
