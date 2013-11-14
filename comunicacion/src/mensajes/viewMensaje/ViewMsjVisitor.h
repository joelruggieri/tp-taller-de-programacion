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
class FinDibujado;
class ViewBotonStartMsj;
class Highlight;

class ViewMsjVisitor {
public:
	virtual ~ViewMsjVisitor(){};
	virtual void visit(ViewObjetoConAnchoUpdateMsj*) = 0;
	virtual void visit(ViewObjetoUpdateMsj*) = 0;
	virtual void visit(ViewObjetoUnionUpdateMsj*) = 0;
	virtual void visit(FinDibujado*) = 0;
	virtual void visit(ViewBotonStartMsj*) = 0;
	virtual void visit(Highlight*) = 0;
};

#endif /* VIEWMSJVISITOR_H_ */
