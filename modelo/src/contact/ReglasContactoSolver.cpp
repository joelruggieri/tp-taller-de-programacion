/*
 * ReglasContactoSolver.cpp
 *
 *  Created on: 21/10/2013
 *      Author: jonathan
 */

#include "ReglasContactoSolver.h"
#include <iostream>
using namespace std;


ReglasContactoSolver::ReglasContactoSolver() {
	clean();
}

void ReglasContactoSolver::visit(Motor*) {
}

void ReglasContactoSolver::visit(Plataforma*) {
}

void ReglasContactoSolver::visit(Balancin*) {
}

void ReglasContactoSolver::visit(CintaTransportadora* c) {
	cinta = c;
}

void ReglasContactoSolver::visit(BolaBoliche* b) {
	this->bola = b;
}

void ReglasContactoSolver::visit(PelotaJuego* p) {
	pelota = p;
}

void ReglasContactoSolver::visit(GloboHelio*) {
}

void ReglasContactoSolver::visit(Engranaje*) {
}

void ReglasContactoSolver::visit(Correa*) {
}

void ReglasContactoSolver::procesarContacto(CintaTransportadora* c, Figura*) {
}

void ReglasContactoSolver::clean() {
}

void ReglasContactoSolver::colisionar(b2Contact* contact,
		const b2Manifold* oldManifold) {


}

ReglasContactoSolver::~ReglasContactoSolver() {
	cinta = NULL;
	bola = NULL;
	pelota = NULL;
}

