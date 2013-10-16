/*
 * Correa.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Correa.h"
#include "../Constantes.h"
Correa::Correa(float x, float y):Union(x,y){
	this->h = 2; 	//harcodeado
}

Correa::~Correa() {
	// TODO Auto-generated destructor stub
}


void Correa::crearFisica(b2World* w, b2Body* ground) {
		crearLazo((Engranaje*)this->figuraInicio, (Engranaje*)this->figuraFin,w);
}

void Correa::crearLazo(Engranaje * a, Engranaje* b, b2World* w) {

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


/// POS: devuelve en RADIANES el angulo


//void Correa::crearFisicaEstaticaTemplate(b2World* w, b2Body* ground) {
//b2Vec2 centro(x,y);
//	b2PolygonShape cuadrado;
//	b2BodyDef bodyDef;
//
////	bodyDef.type = b2_dynamicBody;	//dynamic??
//	bodyDef.position = centro;
//	bodyDef.angle = this->rotacion;
//	bodyDef.fixedRotation = true;
//	b2Body* body = w->CreateBody(&bodyDef);
//	cuadrado.SetAsBox(this->w,this->h);
//	b2FixtureDef bodyCuadrado;
//	bodyCuadrado.shape = &cuadrado;
//	bodyCuadrado.filter.categoryBits = CATEGORIA_CORREA;
//	bodyCuadrado.filter.maskBits = CATEGORIA_CORREA;
//	body->CreateFixture(&bodyCuadrado);
//	  this->crearFisica(w,ground);
//
//}


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


void Correa::acept(VisitorFigura*){

}

bool Correa::puntoInicialValido(Figura*f ) {
	return f->esTraccionable();
}
