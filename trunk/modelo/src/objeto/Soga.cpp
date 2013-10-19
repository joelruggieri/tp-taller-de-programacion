/*
 * Soga.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Soga.h"
#include <cfloat>
Soga::Soga(float x, float y) :
		Union(x, y, 1.5) {

	origen = NULL;
	destino = NULL;
}

Soga::~Soga() {
	// TODO Auto-generated destructor stub
}

Soga::Soga(const Soga& figura) :
		Union(figura) {
	origen = NULL;
	destino = NULL;
}

bool Soga::crearFisicaEstatica(b2World* w, b2Body * ground) {
	if (figuraInicio == figuraFin) {
		return false;
	}
	origen->ocupar();
	destino->ocupar();
	this->crearFisicaEstaticaTemplate(w, ground);
	return true;
}

void Soga::acept(VisitorFigura*v) {
	v->visit(this);
}

void Soga::crearFisica(b2World* w, b2Body* g) {
	this->crearLazo(w);
}

void Soga::setearPuntoInicial(Figura* f) {
	this->figuraInicio = f;
	this->origen = getEngancheMasCercano(f, inicio.x, inicio.y, true);
	this->inicio = f->getBody()->GetWorldPoint(origen->getPos());

}

void Soga::setearPuntoFinal(Figura* f) {
	this->figuraFin = f;
	this->destino = getEngancheMasCercano(f, fin.x, fin.y, true);
	this->fin = f->getBody()->GetWorldPoint(destino->getPos());
}

void Soga::crearLazo(b2World* w) {
	b2RopeJointDef ropeJoint;
	ropeJoint.bodyA = this->figuraInicio->getBody();
	ropeJoint.bodyB = this->figuraFin->getBody();
	ropeJoint.collideConnected = true;
	b2Vec2 dif = inicio - fin;
	ropeJoint.maxLength = dif.Length(); // el maximo sale del calculo de la distancia en union
	ropeJoint.localAnchorA = origen->getPos();
	ropeJoint.localAnchorB = destino->getPos();

	w->CreateJoint(&ropeJoint);

}


Enganche* Soga::getEngancheMasCercano(Figura* figura, float x, float y, bool desocupado) {
	Enganche * eng = NULL;
	float distanciaMin = FLT_MAX;
	Lista_Enganches::iterator it;
	b2Vec2 pos(x, y);
	for (it = figura->getEnganches().begin(); it != figura->getEnganches().end(); ++it) {
		b2Body* bd = figura->getBody();

		b2Vec2 posicionEnganche = bd->GetWorldPoint(b2Vec2((*it)->getPosX(), (*it)->getPosY()));

		b2Vec2 diferencia = posicionEnganche - pos;
		float distancia = diferencia.Length();
		if (distancia < distanciaMin && !((*it)->estaOcupado() && desocupado)) {
			eng = *it;
			distanciaMin = distancia;
		}
	}
	return eng;

}

void Soga::updatePosicionesFiguras() {
	this->inicio = this->figuraInicio->getBody()->GetWorldPoint(origen->getPos());
	this->fin = this->figuraFin->getBody()->GetWorldPoint(destino->getPos());

}

bool Soga::isInicioValido(Figura* f, float x, float y) {
	Enganche* eng = getEngancheMasCercano(f, x, y, true);
	return eng != NULL;
}

bool Soga::isFinValido(Figura* f, float x, float y) {
	Enganche* eng = getEngancheMasCercano(f, x, y, true);
	return eng != NULL;
}

void Soga::extraerPosInicial(Figura* f, float x, float y) {
	Enganche * en = getEngancheMasCercano(f, x, y, true);
	this->inicio = f->getBody()->GetWorldPoint(en->getPos());
}

void Soga::extraerPosFinal(Figura* f, float x, float y) {
	Enganche * en = getEngancheMasCercano(f, x, y, true);
	this->fin = f->getBody()->GetWorldPoint(en->getPos());

}

Soga::Soga() {
	origen = NULL;
	destino = NULL;
}

void Soga::removerFisica(b2World* w) {
	if(origen != NULL){
		origen->liberar();
	}
	if(destino){
		destino->liberar();
	}
}
