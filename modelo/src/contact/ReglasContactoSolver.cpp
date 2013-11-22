/*
 * ReglasContactoSolver.cpp
 *
 *  Created on: 21/10/2013
 *      Author: jonathan
 */

#include "ReglasContactoSolver.h"
#include <iostream>
#include "../objeto/CintaTransportadora.h"
#include "../objeto/BolaBoliche.h"
#include "../objeto/PelotaJuego.h"
#include "../objeto/GloboHelio.h"
#include "../objeto/Yunque.h"
#include "../objeto/Clavo.h"
#include "../objeto/Polea.h"
#include "../objeto/Tijera.h"
#include "../objeto/Monitor.h"
#include "../objeto/Carrito.h"
#include "../objeto/Bomba.h"
using namespace std;

ReglasContactoSolver::ReglasContactoSolver() {
	clean();
}

void ReglasContactoSolver::visit(Gancho*) {
}

void ReglasContactoSolver::visit(Carrito* c) {
	carrito = c;
}

void ReglasContactoSolver::visit(Motor*) {
}

void ReglasContactoSolver::visit(Plataforma*) {
}

void ReglasContactoSolver::visit(Balancin*) {
}

void ReglasContactoSolver::visit(Tijera* t) {
	if (tijera1) {
		tijera2 = t;
	} else {
		tijera1 = t;
	}
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

void ReglasContactoSolver::visit(GloboHelio* g) {
	globo = g;
}

void ReglasContactoSolver::visit(Engranaje*) {
}

void ReglasContactoSolver::visit(Correa*) {
}

void ReglasContactoSolver::visit(Polea*) {
}
void ReglasContactoSolver::procesarContacto(CintaTransportadora* c, Figura* f,
		b2Contact* contact, const b2Manifold* oldManifold) {
	float velocidad = c->getVelocidadCinta();
	float signo = 1;
	if (contact->GetFixtureB()->GetUserData() == c) {
		signo = -1;
	}
	if (velocidad != 0) {
		contact->SetSurfaceVelocityModifier(signo * velocidad);
	}
}

void ReglasContactoSolver::clean() {
	cinta = NULL;
	pelota = NULL;
	bola = NULL;
	globo = NULL;
	clavo = NULL;
	yunque = NULL;
	tijera1 = NULL;
	tijera2 = NULL;
	monitor= NULL;
	carrito = NULL;
	bomba = NULL;
}

void ReglasContactoSolver::colisionar(b2Contact* contact,
		const b2Manifold* oldManifold) {
	//ACA CHEQUEA TODAS LAS REGLAS POSIBLES.


	if(cinta != NULL) {
		if (yunque != NULL) {
			procesarContacto(cinta, yunque, contact, oldManifold);
		}
		if (globo != NULL) {
			procesarContacto(cinta, globo, contact, oldManifold);
		}
		if (bola != NULL) {
			procesarContacto(cinta, bola, contact, oldManifold);
		}
		if (pelota != NULL) {
			procesarContacto(cinta, pelota, contact, oldManifold);
		}
		if(carrito != NULL){
			procesarContacto(cinta, carrito, contact, oldManifold);
		}
		if(bomba != NULL){
			procesarContacto(cinta, carrito, contact, oldManifold);
		}
	}
	if (globo != NULL && clavo != NULL) {
		procesarContacto(globo, clavo, contact, oldManifold);
	}
	if(tijera1 && tijera1 == tijera2){
		pendientesAccionar.push_back(tijera1);
	}

	if(monitor)
	{
		if(contact->GetFixtureA()->GetUserData() == monitor)
		this->monitor->contactar((Figura*)contact->GetFixtureB()->GetUserData());
		else
			this->monitor->contactar((Figura*)contact->GetFixtureA()->GetUserData());
	}
	clean();

}

ReglasContactoSolver::~ReglasContactoSolver() {
	clean();
}

void ReglasContactoSolver::visit(Soga*) {
}

void ReglasContactoSolver::visit(Yunque* y) {
	yunque = y;
}

void ReglasContactoSolver::visit(Clavo* c) {
	clavo = c;
}

void ReglasContactoSolver::procesarContacto(GloboHelio* g, Clavo* c,
		b2Contact* contact, const b2Manifold* oldManifold) {
	pendientesAccionar.push_back(g);
}

void ReglasContactoSolver::finalizarAcciones() {
	list<Figura*>::iterator it;
	for (it = pendientesAccionar.begin(); it != pendientesAccionar.end();
			++it) {
		(*it)->accionar();
	}
	pendientesAccionar.clear();
}

void ReglasContactoSolver::visit(ControlRemoto*) {
}

void ReglasContactoSolver::visit(Bomba*b) {
	bomba= b;
}

void ReglasContactoSolver::visit(Monitor* m) {
monitor= m;
}

void ReglasContactoSolver::PreSolve(b2Contact* contact,
		const b2Manifold* oldManifold) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();
	//si los shapes no tienen un user data es que no participan de los contactos custom.
	if (fixtureA->GetUserData() == NULL || fixtureB->GetUserData() == NULL) {
		return;
	}
	//todo en los tutoriales dice que es mejor agregar a un buffer de colisiones y dsps del step procesarlas, por ahora no es necesario.
	Figura * figA = (Figura *) fixtureA->GetUserData();
	Figura * figB = (Figura *) fixtureB->GetUserData();
	figA->acept(this);
	figB->acept(this);
	colisionar(contact, oldManifold);

//
	//check each fixture to see if surface velocity should be applied
//	b2WorldManifold worldManifold;
//	contact->GetWorldManifold(&worldManifold);
//	float surfaceVelocityModifier = 0;

//		b2Vec2 localNormal = fixtureA->GetBody()->GetLocalVector(worldManifold.normal);
//		float angle = b2Atan2( localNormal.y, localNormal.x );
//		if (segment->minAngle < angle && angle < segment->maxAngle)
//			surfaceVelocityModifier += segment->surfaceVelocity;
//
//	if (ConveyorSegment* segment = (ConveyorSegment*) fixtureB->GetUserData()) {
//		b2Vec2 localNormal = fixtureB->GetBody()->GetLocalVector(-worldManifold.normal);
//		float angle = b2Atan2( localNormal.y, localNormal.x );
//		if (segment->minAngle < angle && angle < segment->maxAngle)
//			surfaceVelocityModifier += segment->surfaceVelocity;
//	}
//	contact->SetSurfaceVelocityModifier(-5.0);
//	contact->SetEnabled(false);
}

void ReglasContactoSolver::PostSolve(b2Contact* contact,
		const b2ContactImpulse* impulso) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();
	//si los shapes no tienen un user data es que no participan de los contactos custom.
	if (fixtureA->GetUserData() == NULL || fixtureB->GetUserData() == NULL) {
		return;
	}

	Figura * figA = (Figura *) fixtureA->GetUserData();
	Figura * figB = (Figura *) fixtureB->GetUserData();
	if(figA->hacerContacto(impulso->normalImpulses[0])){
		pendientesAccionar.push_back(figA);
	}
	if(figB->hacerContacto(impulso->normalImpulses[0])){
		pendientesAccionar.push_back(figB);
	}
}
