/*
 * Soga.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Soga.h"

Soga::Soga(float x, float y):Objeto(x,y) {
	// TODO Auto-generated constructor stub
	modificado = true;
}

Soga::~Soga() {
	// TODO Auto-generated destructor stub
}


Soga::Soga(const Soga& figura):Objeto(x,y) {
	this->reg = figura.reg;
	this->modificado = figura.modificado;
}

bool Soga::crearFisicaEstatica(b2World*) {
	// Minga! La soga puede atravesar objetos
	return true;
}

void Soga::cargar(b2Body* origen, b2Body* destino, b2World *m_world) {

	b2Body* techo = origen;
	b2Body* ultimoEnlace = techo;
	b2Vec2 ultimoAnclaje = b2Vec2(0, -0.5);
	b2RevoluteJointDef *unionDeRevolucion = new b2RevoluteJointDef();
	float altura = 1.1;


	float deltaX = destino->GetPosition().x - origen->GetPosition().x;
	float deltaY = destino->GetPosition().y - origen->GetPosition().y;

	float mayor = (deltaX > deltaY ? deltaX : deltaY);

	float pasoX = deltaX / mayor;
	float pasoY = deltaY / mayor;

	b2Body* tramoActual;
	tramos.clear();

    for (int i = 1; i < mayor; ++i) {
        tramoActual = crear(m_world, origen->GetPosition().x + i * pasoX, origen->GetPosition().y + i * pasoY);

        //revolute joint
        unionDeRevolucion->bodyA = ultimoEnlace;
        unionDeRevolucion->bodyB = tramoActual;
        unionDeRevolucion->localAnchorA = ultimoAnclaje;
        unionDeRevolucion->localAnchorB = b2Vec2(0 , altura/2);

        ultimoAnclaje = b2Vec2(0, -1 * altura/2);

        //create the joint in world
        m_world->CreateJoint(unionDeRevolucion);

        // saving the reference of the last placed link
        ultimoEnlace = tramoActual;
        tramos.push_back(tramoActual);
    }

    unionDeRevolucion->bodyA = ultimoEnlace;
    unionDeRevolucion->bodyB = destino;
    unionDeRevolucion->localAnchorA = ultimoAnclaje;
    unionDeRevolucion->localAnchorB = b2Vec2(0 , altura/2);

    ultimoAnclaje = b2Vec2(0, -1 * altura/2);

    //create the joint in world
    m_world->CreateJoint(unionDeRevolucion);
}


b2Body *Soga::crear(b2World *m_world, int x, int y) {
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	b2FixtureDef myFixtureDef;
	myFixtureDef.friction = 1;
	myFixtureDef.density = 1;
	myFixtureDef.restitution = 0.5;
	b2PolygonShape boxShape;
	boxShape.SetAsBox(0.25 / 2,1.1 / 2);
	myFixtureDef.shape = &boxShape;
	myBodyDef.position.Set(x , y);
	b2Body *cuerpo = m_world->CreateBody(&myBodyDef);
	cuerpo->CreateFixture(&myFixtureDef);
	return cuerpo;
}

void Soga::updateModelo() {
	Figura::updateModelo();
//	actualizarMarcos();
//	actualizarAngulos();
}

void Soga::actualizarMarcos() {
	if (tramos.size() != marcosTramos.size()) {
		marcosTramos = std::vector<SDL_Rect>(tramos.size());
	}
	SDL_Rect aux;
	for (unsigned int i=0; i < tramos.size(); ++i){
		aux.x = (int) tramos[i]->GetPosition().x;
		aux.y = (int) tramos[i]->GetPosition().y;
		aux.w = 0.25;
		aux.h = 1.1;
		marcosTramos[i] = aux;
	}
	modificado = false;
}

void Soga::actualizarAngulos() {
	if (tramos.size() != angulosTramos.size()) {
		angulosTramos = std::vector<float>(tramos.size());
	}
	for (unsigned int i=0; i < tramos.size(); ++i){
		angulosTramos[i] =  tramos[i]->GetAngle();
	}
	modificado = false;
}

std::vector<float>& Soga::getAngulosTramos() {
	if (modificado) actualizarAngulos();
	return angulosTramos;
}

std::vector<SDL_Rect>& Soga::getMarcosTramos() {
	if (modificado) actualizarMarcos();
	return marcosTramos;
}
