/*
 * VisitorFigura.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef VISITORFIGURA_H_
#define VISITORFIGURA_H_
class Figura;
class Plataforma;
class Engranaje;
class Motor;
class Balancin;
class CintaTransportadora;
class BolaBoliche;
class PelotaJuego;
class GloboHelio;
class Soga;
class Carrito;
class Correa;
class Gancho;
class Yunque;
class Clavo;
class Polea;
class Tijera;
class ControlRemoto;
class Bomba;
class Monitor;
class VisitorFigura {
public:
	virtual ~VisitorFigura() {

	}
	virtual void visit(Gancho*) = 0;
	virtual void visit(Motor*) = 0;
	virtual void visit(Plataforma*) = 0;
	virtual void visit(Balancin*) = 0;
	virtual void visit(CintaTransportadora*) = 0;
	virtual void visit(BolaBoliche*) = 0;
	virtual void visit(PelotaJuego*) = 0;
	virtual void visit(GloboHelio*) = 0;
	virtual void visit(Engranaje*) = 0;
	virtual void visit(Carrito*) = 0;
	virtual void visit(Correa*) = 0;
	virtual void visit(Soga*) = 0;
	virtual void visit(Yunque*)=0;
	virtual void visit(Clavo*)=0;
	virtual void visit(Polea*)=0;
	virtual void visit(Tijera*) =0;
	virtual void visit(ControlRemoto*)=0;
	virtual void visit(Bomba*)=0;
};

#endif /* VISITORFIGURA_H_ */

