/*
 * VisitorFigura.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef VISITORFIGURA_H_
#define VISITORFIGURA_H_

class Plataforma;
class Circulo;
class Rueda;
class Globo;
class Pelota;
class Motor;
class Balancin;

class VisitorFigura {
public:
	virtual ~VisitorFigura(){

	}
	virtual void visit(Circulo*) = 0;
	virtual void visit(Rueda*) = 0;
	virtual void visit(Globo*) = 0;
	virtual void visit(Pelota*) = 0;
	virtual void visit(Motor*) = 0;
	virtual void visit(Plataforma*) = 0;
	virtual void visit(Balancin*) = 0;
};

#endif /* VISITORFIGURA_H_ */

