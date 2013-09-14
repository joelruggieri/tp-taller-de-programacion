/*
 * VisitorFigura.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef VISITORFIGURA_H_
#define VISITORFIGURA_H_

class Cuadrado;
class Circulo;
class Triangulo;
class VisitorFigura {
public:
	virtual ~VisitorFigura(){

	}
	virtual void visit(Cuadrado*) = 0;
	virtual void visit(Triangulo*) = 0;
	virtual void visit(Circulo*) = 0;
};

#endif /* VISITORFIGURA_H_ */

