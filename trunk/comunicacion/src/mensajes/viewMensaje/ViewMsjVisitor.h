/*
 * ViewMsjVisitor.h
 *
 *  Created on: 5/11/2013
 *      Author: jonathan
 */

#ifndef VIEWMSJVISITOR_H_
#define VIEWMSJVISITOR_H_

class ViewObjetoConAnchoUpdateMsj;
class ViewObjetoUnionUpdateMsj;
class ViewObjetoUpdateMsj;

class ViewMsjVisitor {
public:
	virtual ~ViewMsjVisitor(){}
	virtual void visit(ViewObjetoConAnchoUpdateMsj*) = 0;
	virtual void visit(ViewObjetoUpdateMsj*) = 0;
	virtual void visit(ViewObjetoUnionUpdateMsj*) = 0;
};

#endif /* VIEWMSJVISITOR_H_ */