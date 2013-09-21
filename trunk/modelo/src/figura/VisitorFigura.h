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
class Rueda;
class Globo;
class Pelota;
class Resorte;
class Martillo;
class Resorte;
class Bloque;
class Cohete;
class Carrito;

class VisitorFigura {
public:
	virtual ~VisitorFigura(){

	}
	virtual void visit(Cuadrado*) = 0;
	virtual void visit(Triangulo*) = 0;
	virtual void visit(Circulo*) = 0;
	virtual void visit(Rueda*) = 0;
	virtual void visit(Globo*) = 0;
	virtual void visit(Pelota*) = 0;
	virtual void visit(Resorte*) = 0;
	virtual void visit(Martillo*) = 0;
	virtual void visit(Bloque*) = 0;
	virtual void visit(Cohete*) = 0;
	virtual void visit(Carrito*) = 0;
};

#endif /* VISITORFIGURA_H_ */

