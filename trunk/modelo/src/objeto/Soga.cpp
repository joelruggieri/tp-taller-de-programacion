/*
 * Soga.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Soga.h"
#include <cfloat>
#include  <iostream>
Soga::Soga(float x, float y) :
		Union(x, y, 1.5) {
	joint2 = NULL;
	origen = NULL;
	destino = NULL;
	eslabon = NULL;
}

Soga::~Soga() {
	// TODO Auto-generated destructor stub
}

Soga::Soga(const Soga& figura) :
		Union(figura) {
	origen = NULL;
	destino = NULL;
	eslabon = NULL;
	joint2 = NULL;
}

bool Soga::crearFisicaEstatica() {
	if (figuraInicio == figuraFin) {
		return false;
	}
	if (myWorld == NULL)
		return false;
	origen->ocupar(this);
	destino->ocupar(this);
	this->crearFisicaEstaticaTemplate();
	return true;
}

void Soga::acept(VisitorFigura*v) {
	v->visit(this);
}

void Soga::crearFisica() {
	this->crearLazo(myWorld);
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

	if (conEslabon()) {
		float x = this->getX();
		float y = this->getY();
		b2Vec2 centro(x, y);
		b2CircleShape shapeCircle;

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(centro.x, centro.y);
		bodyDef.linearDamping = 1;
		eslabon = myWorld->CreateBody(&bodyDef);
		shapeCircle.m_radius = 1;
		b2FixtureDef bodyBolaBoliche;
		bodyBolaBoliche.filter.categoryBits = CATEGORIA_ESLABON;
		bodyBolaBoliche.filter.maskBits = CATEGORIA_ESLABON;
		bodyBolaBoliche.shape = &shapeCircle;
		//ENTREGA3 CUANDO FUNCIONE LA POLEA VER ESTO PARA EL GLOBO.
		bodyBolaBoliche.density = 5.0f;
		eslabon->CreateFixture(&bodyBolaBoliche)->SetUserData(this);

		//y ahora hago las uniones.
		//primero el inicio al eslabon.
		b2RopeJointDef ropeJoint;
		ropeJoint.bodyA = this->figuraInicio->getBody();
		ropeJoint.bodyB = eslabon;
		ropeJoint.collideConnected = true;
		b2Vec2 dif = inicio - centro;
		ropeJoint.maxLength = dif.Length(); // el maximo sale del calculo de la distancia en union
		ropeJoint.localAnchorA = origen->getPos();
		ropeJoint.localAnchorB = b2Vec2(0, 0);
		joint = w->CreateJoint(&ropeJoint);

		origen->setEslabon(eslabon);
//		//luego el eslabon al fin
		b2RopeJointDef ropeJoint2;
		ropeJoint2.bodyA = eslabon;
		ropeJoint2.bodyB = this->figuraFin->getBody();
		ropeJoint2.collideConnected = true;
		b2Vec2 dif2 =  centro - fin;
		ropeJoint2.maxLength = dif2.Length(); // el maximo sale del calculo de la distancia en union
		ropeJoint2.localAnchorA = b2Vec2(0,0);
		ropeJoint2.localAnchorB = destino->getPos();
		joint2 = w->CreateJoint(&ropeJoint2);
		destino->setEslabon(eslabon);
		body = NULL;
		eslabon->SetUserData(this);
		this->setBody(body);

	} else {
		b2RopeJointDef ropeJoint;
		ropeJoint.bodyA = this->figuraInicio->getBody();
		ropeJoint.bodyB = this->figuraFin->getBody();
		ropeJoint.collideConnected = true;
		b2Vec2 dif = inicio - fin;
		ropeJoint.maxLength = dif.Length(); // el maximo sale del calculo de la distancia en union
		ropeJoint.localAnchorA = origen->getPos();
		ropeJoint.localAnchorB = destino->getPos();
		joint = w->CreateJoint(&ropeJoint);
		body = NULL;
	}

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
	if (this->figuraInicio->getBody()) {
		this->inicio = this->figuraInicio->getBody()->GetWorldPoint(origen->getPos());
	}
	if (this->figuraFin->getBody()) {
		this->fin = this->figuraFin->getBody()->GetWorldPoint(destino->getPos());
	}

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
	eslabon = NULL;
	joint2 = NULL;
}
void Soga::removerFisica() {
	if (joint != NULL) {
		myWorld->DestroyJoint(joint);
		joint = NULL;
		viva = false;
	}
	if (eslabon != NULL) {
		myWorld->DestroyJoint(joint2);
		myWorld->DestroyBody(eslabon);
		eslabon = NULL;
	}
	super::removerFisica();
	if (origen != NULL) {
		origen->liberar();
	}
	if (destino) {
		destino->liberar();
	}
}

void Soga::updatePosicionesFigurasSinFisica() {
	this->inicio = this->origen->getWorldPos();
	this->fin = this->destino->getWorldPos();
}

bool Soga::conEslabon() {
	bool result = false;
	if (origen) {
		result = result || origen->getRequiereEslabon();
	}
	if (destino) {
		result = result || destino->getRequiereEslabon();
	}
	return result;
}

void Soga::calcularCentroCuadrado() {
	super::calcularCentroCuadrado();
	if (conEslabon()) {
		posEslabon.Set(this->x, this->y);
	}
}

void Soga::limpiarReferenciasB2D() {
	joint = NULL;
	joint2 = NULL;
	body = NULL;
	eslabon = NULL;
}

void Soga::desactivarJoint(Enganche* e) {
	if (eslabon) {

		if (e == origen && joint) {
			myWorld->DestroyJoint(joint);
			joint = NULL;
		}
		if (e == destino && joint2) {
			myWorld->DestroyJoint(joint2);
			joint2 = NULL;
		}
	} else {
		myWorld->DestroyJoint(joint);
		joint = NULL;
	}
}
