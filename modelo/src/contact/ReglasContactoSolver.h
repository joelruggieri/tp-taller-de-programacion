/*
 * ReglasContactoSolver.h
 *
 *  Created on: 21/10/2013
 *      Author: jonathan
 */

#ifndef REGLASCONTACTOSOLVER_H_
#define REGLASCONTACTOSOLVER_H_

#include "../figura/VisitorFigura.h"
#include "Box2D/Box2D.h"
#include "../figura/Figura.h"
class ReglasContactoSolver: public VisitorFigura, public b2ContactListener  {
private:
	CintaTransportadora * cinta;
	PelotaJuego * pelota;
	BolaBoliche * bola;
	GloboHelio * globo;
	Clavo* clavo;
	Yunque* yunque;
	Tijera * tijera1;
	Tijera * tijera2;
	void clean();
	void colisionar(b2Contact * 	contact,
			const b2Manifold * 	oldManifold);
	list<Figura *> pendientesAccionar;
public:
	void visit(Gancho*);
	void visit(Motor*);
	void visit(Plataforma*);
	void visit(Balancin*);
	void visit(Tijera*);
	void visit(Carrito*);
	void visit(CintaTransportadora*);
	void visit(BolaBoliche*);
	void visit(PelotaJuego*);
	void visit(GloboHelio*);
	void visit(Engranaje*);
	void visit(Correa*);
	void visit(Soga*);
	void visit(Yunque*);
	void visit(Clavo*);
	void visit(Polea*);
	void visit(ControlRemoto*);
	void visit(Bomba*);
	void procesarContacto(CintaTransportadora * c, Figura *,b2Contact* contact, const b2Manifold* oldManifold);
	void procesarContacto(GloboHelio * c, Clavo *,b2Contact* contact, const b2Manifold* oldManifold);
	ReglasContactoSolver();
	virtual ~ReglasContactoSolver();
	void finalizarAcciones();
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
};

#endif /* REGLASCONTACTOSOLVER_H_ */
