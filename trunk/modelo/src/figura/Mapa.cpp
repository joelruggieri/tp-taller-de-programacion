/*
 * Mapa.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Mapa.h"
#include <iostream>
using namespace std;

Mapa::Mapa(float x, float y, float w, float h,	float32 hz, int32 velocityIterations,int32 positionIterations) {
	inicializar(x,y,w,h,hz,velocityIterations,positionIterations);
}

Mapa::Mapa(float x, float y, float w, float h) {
	inicializar(x,y,w,h,1.0/60.0,8,3);
}

Mapa::~Mapa() {
	delete myWorld;
}

bool Mapa::removeFigura(Figura* figura) {
	if (figura->getBody() != 0) {

		this->myWorld->DestroyBody(figura->getBody());
		figura->setBody(0);
		this->figuras.remove(figura);
		return true;
	}
	return false;
}

bool Mapa::addFigura(Figura* figura) {
	if (!isAdentro(figura->getX(), figura->getY())) {
		return false;
	}
	figura->crearFisica(this->myWorld);
	this->figuras.push_back(figura);
	return true;
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
		cout << "reporta" << endl;
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody || body->GetType() == b2_staticBody) {
			bool inside = fixture->TestPoint(m_point);
			if (inside) {
				m_fixture = fixture;

				// We are done, terminate the query.
				return false;
			}
		}
		cout << "se va" << endl;
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
		cout
				<< (body->GetUserData() == 0 ?
						"------------------No hay interseccion" :
						"--------------Contacto") << endl;
		// TODO SI HUBIERA JOINTS HABRÍA QUE VER COMO MANEJARLAS, quizas no dejar draguear si hay un joint de soga o algo asi.
		Figura* figura = (Figura*) (body->GetUserData());
		return figura;
	}
//	return NULL;
//	for(b2Body *b = myWorld->GetBodyList(); b; b=b->GetNext()){
//
//		if(b->GetUserData() != 0){
//			Figura * fig = (Figura*) b->GetUserData();
//			double xC = x;
//			double yC = 100 - y;
//			fig->getRotador()->rotar(fig,xC,yC);
//			b2Vec2 vec(xC,100 - yC);
//			b2Shape* shape = b->GetFixtureList()->GetShape();
//			bool contacto = shape->TestPoint(b->GetTransform(), vec);
//			if(contacto){
//				return fig;
//			}
//
//		}
//	}
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
	list<Figura*>::iterator it;
	//TODO VER OTRA FORMA DE HACER EL UPDATE.
	Figura * fig;
	for(it= this->figuras.begin(); it != this->figuras.end(); ++it){
		fig = *it;
		fig->updateModelo(tl);
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
	}
	delete myWorld;
	crearMundo();
	for(it = figuras.begin(); it != figuras.end(); ++it){
		(*it)->crearFisica(myWorld);
	}

	for(it = figuras.begin(); it != figuras.end(); ++it){
		(*it)->updateModelo(tl);
	}
}

void Mapa::crearMundo() {
	b2Vec2 gravity(0.0f, -10.0f);
	this->myWorld = new b2World(gravity);
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 0.0f);

	// Call the body mapa which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = myWorld->CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(100.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
}
