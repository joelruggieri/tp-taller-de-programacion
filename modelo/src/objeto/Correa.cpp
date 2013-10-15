/*
 * Correa.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Correa.h"
#include "../Constantes.h"
Correa::Correa(float x, float y):Union(x,y){

}

Correa::~Correa() {
	// TODO Auto-generated destructor stub
}


void Correa::crearFisica(b2World* w, b2Body* ground) {
		b2Vec2 centro(x,y);
		crearLazo((Engranaje*)this->figuraInicio, (Engranaje*)this->figuraFin,w);
}

void Correa::crearLazo(Engranaje * a, Engranaje* b, b2World* w) {

	//    b2RevoluteJointDef the_rev_joint = new b2RevoluteJointDef();

	//	the_rev_joint.Initialize(ground, body, body->GetPosition());
	//	b2RevoluteJoint first_joint = (b2RevoluteJoint) w->CreateJoint(the_rev_joint);
	//    the_rev_joint.Initialize(wground.GetGroundBody(), gear2, new b2Vec2(11,6.5));
	//    var second_joint:b2RevoluteJoint=m_world.CreateJoint(the_rev_joint) as b2RevoluteJoint;
	    // gear joint
	    b2GearJointDef  gear_joint;
	    gear_joint.bodyA=a->getBody();
	    gear_joint.bodyB= b->getBody();
	    gear_joint.joint1= a->getJointATierra();
	    gear_joint.joint2= b->getJointATierra();
	    gear_joint.ratio=-1;
	    w->CreateJoint(&gear_joint);



}

//void Correa::setInicio(b2Vec2 b2Vec2) {
//	this->inicio = b2Vec2;
//}
//
//void Correa::setFin(b2Vec2 b2Vec2) {
//	this->fin = b2Vec2;
//}

float Correa::calcularDistancia(b2Vec2 a,b2Vec2 b) {
	return (float)sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));

}

b2Vec2 Correa::calcularCentroCuadrado() {
b2Vec2 vecResult;
vecResult.x = (this->inicio.x + this->fin.x)/2;
vecResult.y = (this->inicio.y + this->fin.y)/2;
return vecResult;
}

/// POS: devuelve en RADIANES el angulo
float Correa::calcularAnguloCuadrado() {
	b2Vec2 dist1, dist2, dist3, dist4;
dist1.x = 0;
dist1.y = this->fin.y;
dist2.x = 0;
dist2.y = this->inicio.y;
dist3.x = this->fin.x;
dist3.y = 0 ;
dist4.x = this->inicio.x;
dist4.y= 0;
return -atan(calcularDistancia(dist1, dist2)/ calcularDistancia(dist3, dist4));
}

void Correa::setFiguraInicio(Figura* a) {
this->figuraInicio = a ;

}

void Correa::setFiguraFin(Figura* a) {
	this->figuraFin = a ;
}

void Correa::crearFisicaEstaticaTemplate(b2World* w, b2Body* ground) {

	b2PolygonShape cuadrado;
	b2BodyDef bodyDef;

//	bodyDef.type = b2_dynamicBody;	//dynamic??
	bodyDef.position = (this->calcularCentroCuadrado());
	bodyDef.angle = this->calcularAnguloCuadrado();
	bodyDef.fixedRotation = true;
	b2Body* body = w->CreateBody(&bodyDef);
	cuadrado.SetAsBox(this->calcularAnchoCuadrado(),2);
	b2FixtureDef bodyCuadrado;
	bodyCuadrado.shape = &cuadrado;
	bodyCuadrado.filter.categoryBits = CATEGORIA_CORREA;
	bodyCuadrado.filter.maskBits = CATEGORIA_CORREA;
	body->CreateFixture(&bodyCuadrado);
	  this->crearFisica(w,ground);

}

float Correa::calcularAnchoCuadrado() {
	return this->calcularDistancia(this->inicio, this->fin);
}


bool Correa::crearFisicaEstatica(b2World* w, b2Body* ground) {
	if (!this->figuraInicio->esTraccionable() || !this-figuraFin->esTraccionable())
	{
		return false;
	}
	this->crearFisicaEstaticaTemplate(w,ground);
	bool hayContacto = false;
	for (b2Body* b = w->GetBodyList(); b && !hayContacto; b = b->GetNext()) {
		if (b != this->body && b->GetFixtureList()!= NULL  && b->GetFixtureList()->GetShape() != NULL){
			if(validarContacto(w,body,b) && this->coincidenMascaras(b) && this->coincidenCategorias(b)){
				hayContacto = true;
				break;
			}

		}
	}
	if(hayContacto) {
		removerFisica(w);
		/// remover joint tambien
					}


	return !hayContacto;
}




