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
class ReglasContactoSolver: public VisitorFigura {
private:
	CintaTransportadora * cinta;
	PelotaJuego * pelota;
	BolaBoliche * bola;
	void clean();
public:
	void visit(Motor*);
	void visit(Plataforma*);
	void visit(Balancin*);
	void visit(CintaTransportadora*);
	void visit(BolaBoliche*);
	void visit(PelotaJuego*);
	void visit(GloboHelio*);
	void visit(Engranaje*);
	void visit(Correa*);
	void colisionar(b2Contact * 	contact,
			const b2Manifold * 	oldManifold);
	void procesarContacto(CintaTransportadora * c, Figura *);
	ReglasContactoSolver();
	virtual ~ReglasContactoSolver();
};

#endif /* REGLASCONTACTOSOLVER_H_ */
