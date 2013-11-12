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
	void clean();
	void colisionar(b2Contact * 	contact,
			const b2Manifold * 	oldManifold);
public:
	void visit(Gancho*);
	void visit(Motor*);
	void visit(Plataforma*);
	void visit(Balancin*);
	void visit(CintaTransportadora*);
	void visit(BolaBoliche*);
	void visit(PelotaJuego*);
	void visit(GloboHelio*);
	void visit(Engranaje*);
	void visit(Correa*);
	void visit(Soga*);
	void procesarContacto(CintaTransportadora * c, Figura *,b2Contact* contact, const b2Manifold* oldManifold);
	ReglasContactoSolver();
	virtual ~ReglasContactoSolver();
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
};

#endif /* REGLASCONTACTOSOLVER_H_ */
