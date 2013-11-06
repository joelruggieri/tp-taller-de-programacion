/*
 * MensajePlanoVisitor.h
 *
 *  Created on: 5/11/2013
 *      Author: jonathan
 */

#ifndef MENSAJEPLANOVISITOR_H_
#define MENSAJEPLANOVISITOR_H_

class MensajePlano;
class MensajePlanoVisitor {
public:
	virtual ~MensajePlanoVisitor(){}
	virtual void visit (MensajePlano *)=0;
};

#endif /* MENSAJEPLANOVISITOR_H_ */
