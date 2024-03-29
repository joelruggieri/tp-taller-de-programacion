/*
 * Correa.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Correa.h"
#include "../Constantes.h"
Correa::Correa(float x, float y) :
		Union(x, y,4.0) {
}

Correa::Correa(const Correa& correa):Union(correa) {
//	this->body = correa.body;
//	this->enganches = correa.enganches;
////	this->figuraFin = correa.figuraFin;
////	this->figuraInicio = correa.figuraInicio;
//	b2Vec2 inicio(correa.getXInicial(), correa.getYInicial());
//	this->inicio = inicio;
//	b2Vec2 fin(correa.getXFinal(), correa.getYFinal());
//	this->fin = fin;
//	this->h = correa.h;
//	this->w = correa.getAncho();
//	this->reg = correa.reg;
//	this->rotacion = correa.getRotacion();
//	this->rotacionb = correa.rotacion;
//	this->traccionable = correa.traccionable;
//	this->vista = correa.vista;
//	this->x = correa.getX();
//	this->y = correa.getY();
//	this->xb = correa.xb;
//	this->yb = correa.yb;

}

Correa::Correa() :
		Union() {

}

Correa::~Correa() {
}

void Correa::crearFisica() {
	crearLazo((Engranaje*) this->figuraInicio, (Engranaje*) this->figuraFin, myWorld);
	estatica= false;
}

void Correa::crearLazo(Engranaje * a, Engranaje* b, b2World* w) {

	b2GearJointDef gear_joint;
	gear_joint.bodyA = a->getBody();
	gear_joint.bodyB = b->getBody();
	gear_joint.joint1 = a->getJointATierra();
	gear_joint.joint2 = b->getJointATierra();
	gear_joint.ratio = -1;
	joint = w->CreateJoint(&gear_joint);

}

bool Correa::crearFisicaEstatica() {
	if (!this->figuraInicio->esTraccionable()
			|| !figuraFin->esTraccionable()) {
		return false;
	}
	if(this->figuraFin == this->figuraInicio){
		return false;
	}
	if(myWorld != NULL){
		this->crearFisicaEstaticaTemplate();
	} else {
		return false;
	}

	((Engranaje *)figuraInicio)->ocupar();
	((Engranaje *)figuraFin)->ocupar();

	return true;
}

void Correa::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

void Correa::setearPuntoInicial(Figura*f) {
	this->figuraInicio =f;
	this->inicio = b2Vec2(f->getX(), f->getY());
}

void Correa::setearPuntoFinal(Figura* f) {
	this->figuraFin =f;
	this->fin= b2Vec2(f->getX(), f->getY());
}

bool Correa::isExtremoValido(Figura* f) {
	if(!f->esTraccionable()){
		return false;
	}
	bool libre = ((Engranaje *)f)->estaLibre();
	return  libre;
}

bool Correa::isInicioValido(Figura* f, float x, float y) {
	return isExtremoValido(f);
}

bool Correa::isFinValido(Figura* f, float x, float y) {
	return isExtremoValido(f);
}

void Correa::extraerPosInicial(Figura* f, float x, float y) {
	this->inicio = b2Vec2 (f->getX(),f->getY());
}

void Correa::extraerPosFinal(Figura* f, float x, float y) {
	this->fin = b2Vec2 (f->getX(),f->getY());
}

void Correa::removerFisica() {
	super::removerFisica();
	if(figuraInicio != NULL){
		((Engranaje *)figuraInicio)->liberar();
	}
	if(figuraFin){
		((Engranaje *)figuraFin)->liberar();
	}
}

float Correa::getRadioInicial() {
	if(figuraInicio != NULL){
		return ((Engranaje *)figuraInicio)->getRadio();
	}
	return this->h;
}

float Correa::getRadioFinal() {
	if(figuraFin != NULL){
		return ((Engranaje *)figuraFin)->getRadio();
	}
	return this->h;
}
