/*
 * Mapa.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Mapa.h"
#include <iostream>
#include "../Constantes.h"
using namespace std;
//#include "src/Logger.h"
Mapa::Mapa(float x, float y, float w, float h,	float32 hz, int32 velocityIterations,int32 positionIterations) {
	inicializar(x,y,w,h,hz,velocityIterations,positionIterations);
}

Mapa::Mapa(float x, float y, float w, float h) {
	inicializar(x,y,w,h,TIEMPO_ITERACION,ITERACIONES_VELOCIDAD,ITERACIONES_POSICION);
}

Mapa::~Mapa() {
	delete myWorld;
}

bool Mapa::removeFigura(Figura* figura) {
	if (figura->getBody() != 0) {

		figura->removerFisica(myWorld);
		this->figuras.remove(figura);
		return true;
	}
	return false;
}

bool Mapa::addFigura(Figura* figura) {
	if (!isAdentro(figura->getX(), figura->getY())) {
		return false;
	}
	bool result = figura->crearFisicaEstatica(this->myWorld, this->groundBody);
	if(result){
		this->figuras.push_back(figura);
	}
	return result;
}

list<Figura*>& Mapa::getFiguras() {
	return this->figuras;
}

class QueryCallback: public b2QueryCallback {
public:
	QueryCallback(const b2Vec2& point) {
		m_point = point;
		m_fixture = NULL;
	}

	bool ReportFixture(b2Fixture* fixture) {
//		Logger log;
//		log.debug("El world indica que existe colision con el punto");
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody || body->GetType() == b2_staticBody) {
			bool inside = fixture->TestPoint(m_point);
			if (inside && ((fixture->GetFilterData().categoryBits &  CATEGORIA_FIGURAS) != 0)){
				m_fixture = fixture;
//				log.debug("La figura confirma la colision");
				// We are done, terminate the query.
				return false;
			}
		}
//		log.debug("La figura cancela la colision");
		// Continue the query.
		return true;
	}

	b2Vec2 m_point;
	b2Fixture* m_fixture;
};

Figura* Mapa::pickUp(float x, float y) {
	if (!isAdentro(x, y)) {
		return NULL;
	}
	b2Vec2 p(x, y);
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.001f, 0.001f);
	aabb.lowerBound = p - d;
	aabb.upperBound = p + d;
	QueryCallback callback(p);
	myWorld->QueryAABB(&callback, aabb);
	if (callback.m_fixture) {
		b2Body* body = callback.m_fixture->GetBody();
		// TODO SI HUBIERA JOINTS HABRÍA QUE VER COMO MANEJARLAS, quizas no dejar draguear si hay un joint de soga o algo asi.
		Figura* figura = (Figura*) (body->GetUserData());
		return figura;
	}
	return NULL;

}
bool Mapa::isAdentro1D(float pos, float posCentro, float ancho) {
	return (pos <= (posCentro + ancho / 2)) && (pos >= posCentro - ancho / 2);

}

float Mapa::getX() const {
	return x;
}

void Mapa::setX(float x) {
	this->x = x;
}

float Mapa::getY() const {
	return y;
}

void Mapa::setY(float y) {
	this->y = y;
}

bool Mapa::isAdentro(float x, float y) {
	return isAdentro1D(x, this->getX(), this->w)
			&& isAdentro1D(y, this->getY(), this->h);
}

void Mapa::step(Transformacion & tl) {
	myWorld->Step(this->frecuencia,this->velocidad,this->posicion);
	cout << "joints " <<myWorld->GetJointCount() <<  endl;
	list<Figura*>::iterator it;
	//TODO VER OTRA FORMA DE HACER EL UPDATE.
	Figura * fig;
	for(it= this->figuras.begin(); it != this->figuras.end(); ++it){
		fig = *it;
		fig->updateModelo();
		fig->updateVista(tl);
	}

}

void Mapa::inicializar(float x, float y, float w, float h, float32 hz,
		int32 velocityIterations, int32 positionIterations) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->frecuencia = hz;
	this->velocidad = velocityIterations;
	this->posicion = positionIterations;
	crearMundo();
}

void Mapa::makeBackUp() {
	//TODO POR AHORA NO HAY FIGURAS QUE SE VAYAN EN LOS STEPS.
	list<Figura*>::iterator it;
	for(it = figuras.begin(); it != figuras.end(); ++it){
		(*it)->makeBackUp();
	}
}

void Mapa::restoreBackUp(Transformacion & tl) {
	list<Figura*>::iterator it;
	for(it = figuras.begin(); it != figuras.end(); ++it){
		(*it)->restoreBackUp();
		(*it)->updateVista(tl);
	}
	delete myWorld;
	crearMundo();
	for(it = figuras.begin(); it != figuras.end(); ++it){
		(*it)->crearFisicaEstatica(myWorld,groundBody);
	}
}

void Mapa::crearMundo() {
	b2Vec2 gravity(0.0f, -10.0f);
	this->myWorld = new b2World(gravity);
	// Define the ground body.
	b2BodyDef groundBodyDef;
//	groundBodyDef.position.Set(50.0f, 50.0f);

	// Call the body mapa which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundBody = myWorld->CreateBody(&groundBodyDef);

	// Define the ground box shape.
//	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
//	groundBox.SetAsBox(100.0f, 10.0f);

	// Add the ground fixture to the ground body.
//	groundBody->CreateFixture(&groundBox, 0.0f);
}

void Mapa::despertar() {
	delete myWorld;
	crearMundo();
	list<Figura*>::iterator it;
	for(it = figuras.begin(); it != figuras.end(); ++it){
		(*it)->crearFisica(myWorld,groundBody);
	}
	cout << myWorld->GetJointCount() << endl;

}
