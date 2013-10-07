/*
 * VisitorFigura.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef VISITORFIGURA_H_
#define VISITORFIGURA_H_

class Plataforma;
class Motor;
class Balancin;
class CintaTransportadora;
class BolaBoliche;
class PelotaJuego;
class GloboHelio;
class VisitorFigura {
public:
	virtual ~VisitorFigura(){

	}
	virtual void visit(Motor*) = 0;
	virtual void visit(Plataforma*) = 0;
	virtual void visit(Balancin*) = 0;
	virtual void visit(CintaTransportadora*) = 0;
	virtual void visit (BolaBoliche*) = 0;
	virtual void visit(PelotaJuego*) = 0;
	virtual void visit (GloboHelio*) = 0;
};

#endif /* VISITORFIGURA_H_ */

