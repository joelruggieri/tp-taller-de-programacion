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
using namespace std;

ReglasContactoSolver::ReglasContactoSolver() {
	clean();
}

void ReglasContactoSolver::visit(Gancho*) {
}

void ReglasContactoSolver::visit(Carrito*) {
}

void ReglasContactoSolver::visit(Motor*) {
}

void ReglasContactoSolver::visit(Plataforma*) {
}

void ReglasContactoSolver::visit(Balancin*) {
}

//TODO ENTREGA3 HAY QUE SOLCIONAR EL TEMA DEL CONTACTO DE LA TIJERA CON LA SOGA
void ReglasContactoSolver::visit(Tijera*) {
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
	globo =  g;
}

void ReglasContactoSolver::visit(Engranaje*) {
}

void ReglasContactoSolver::visit(Correa*) {
}

void ReglasContactoSolver::visit(Polea*) {
}
void ReglasContactoSolver::procesarContacto(CintaTransportadora* c, Figura* f,b2Contact* contact, const b2Manifold* oldManifold) {
	float velocidad = c->getVelocidadCinta();
	float signo = 1;
	if(contact->GetFixtureB()->GetUserData() == c){
		signo = -1;
	}
	if(velocidad != 0){
		contact->SetSurfaceVelocityModifier(signo * velocidad);
	}
}

void ReglasContactoSolver::clean() {
	 cinta = NULL;
	 pelota= NULL;
	 bola= NULL;
	 globo= NULL;
	 clavo= NULL;
	 yunque= NULL;
}

void ReglasContactoSolver::colisionar(b2Contact* contact, const b2Manifold* oldManifold) {
	//ACA CHEQUEA TODAS LAS REGLAS POSIBLES.
   if(cinta != NULL && pelota != NULL ){
	   procesarContacto(cinta, pelota,contact,oldManifold );
   }
   if(cinta != NULL && bola != NULL ){
	   procesarContacto(cinta, bola,contact,oldManifold);
   }

   if(cinta != NULL && globo != NULL ){
	   procesarContacto(cinta, globo,contact,oldManifold);
   }

   if(cinta != NULL && yunque != NULL){
	   procesarContacto(cinta,yunque,contact,oldManifold);
   }

   if(globo != NULL && clavo !=NULL)
   {
	   procesarContacto(globo, clavo, contact, oldManifold);
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
	for(it=pendientesAccionar.begin(); it != pendientesAccionar.end(); ++ it){
		(*it)->accionar();
	}
	pendientesAccionar.clear();
}

void ReglasContactoSolver::visit(ControlRemoto*) {
}

void ReglasContactoSolver::visit(Bomba*) {
}

void ReglasContactoSolver::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();
	//si los shapes no tienen un user data es que no participan de los contactos custom.
	if(fixtureA->GetUserData() == NULL || fixtureB->GetUserData() == NULL) {
		return;
	}
	//todo en los tutoriales dice que es mejor agregar a un buffer de colisiones y dsps del step procesarlas, por ahora no es necesario.
	Figura * figA = (Figura *)fixtureA->GetUserData();
	Figura * figB = (Figura *)fixtureB->GetUserData();
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
