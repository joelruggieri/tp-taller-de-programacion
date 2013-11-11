/*
 * MensajeInternoVisitor.h
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#ifndef MENSAJEINTERNOVISITOR_H_
#define MENSAJEINTERNOVISITOR_H_
class DrawEvent;
class ConexionUsuario;
class StepModelo;
class MensajeInternoVisitor {
public:
	virtual ~MensajeInternoVisitor(){}
	virtual void visit(DrawEvent *) =0;
	virtual void visit (ConexionUsuario*)=0;
	virtual void visit (StepModelo*)=0;
};

#endif /* MENSAJEINTERNOVISITOR_H_ */
