/*
 * Mapa.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Mapa.h"
#include <iostream>
#include "../Constantes.h"
#include "../objeto/Union.h"
#include "../figura/Figura.h"
#include "../contact/ReglasContactoSolver.h"
using namespace std;
#define JUGADOR_OFF -20
//#include "src/Logger.h"
Mapa::Mapa(float x, float y, float w, float h, float32 hz, int32 velocityIterations, int32 positionIterations) {
	inicializar(x, y, w, h, hz, velocityIterations, positionIterations);
}

Mapa::Mapa(float x, float y, float w, float h) {
	inicializar(x, y, w, h, TIEMPO_ITERACION, ITERACIONES_VELOCIDAD,
	ITERACIONES_POSICION);
}

Mapa::~Mapa() {
	delete myWorld;
	delete contactSolver;
	//TODO MEMORY LEAK: NO DELETEA LAS FIGURAS PERO SE DELETEAN EN EL NIVEL SI GUARDASTE. SEDEBERÍAN DELETEAR ACA SI DELETEAS EL MAPA Y EN EL NIVEL SE DEBERÍA HACER UNA COPIA.
}

bool Mapa::remove(Figura* figura) {

	return figura->remover(this);
}

bool Mapa::add(Figura* figura) {
	bool result = figura->agregar(this);
	return result;
}

list<Figura*>& Mapa::getFiguras() {
	return this->figuras;
}

class QueryCallback: public b2QueryCallback {
public:
	QueryCallback(const b2Vec2& point,uint16 mascara, int numero, bool estaticos, bool checknumero) {
		m_point = point;
		m_fixture = NULL;
		m_mascara = mascara;
		m_numero = numero;
		m_estaticos = estaticos;
		m_checknumero= checknumero;
	}

	bool ReportFixture(b2Fixture* fixture) {
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody || body->GetType() == b2_staticBody) {
			bool inside = fixture->TestPoint(m_point);
			if (inside
					&& ((fixture->GetFilterData().categoryBits & m_mascara) != 0)) {
				Figura* fig = (Figura*)body->GetUserData();
				if(fig != NULL && ((!m_checknumero || fig->getNumeroJugador() == m_numero )|| (m_estaticos && fig->getNumeroJugador() == NUMERO_JUGADOR_DEFECTO))){
					m_fixture = fixture;
					return false;
				}
			}
		}
		// Continue the query.
		return true;
	}

	b2Vec2 m_point;
	b2Fixture* m_fixture;
	uint16 m_mascara;
	int m_numero;
	bool m_estaticos;
	bool m_checknumero;
};

Figura* Mapa::pickUp(float x, float y, uint16 mascara, int numeroJugador, bool conEstaticos) {
	std::map<int,Area*>::iterator it = this->areasDeJugadores.find(numeroJugador);
	if (!isAdentro(x, y)|| !(it->second->isAdentro1D(x,it->second->getX(),it->second->getAncho()))
			|| !(it->second->isAdentro1D(y,it->second->getY(),it->second->getAlto()))) {
		return NULL;
	}
	b2Vec2 p(x, y);
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.003f, 0.003f);
	aabb.lowerBound = p - d;
	aabb.upperBound = p + d;

	//trae los que tienen el mismo numero y agrega o no los estaticos
	QueryCallback callback(p, mascara, numeroJugador,conEstaticos, true);
	myWorld->QueryAABB(&callback, aabb);
	if (callback.m_fixture) {
		b2Body* body = callback.m_fixture->GetBody();
		Figura* figura = (Figura*) (body->GetUserData());
		if(figura == NULL) {
			figura = NULL;
		}

		return figura;
	}
	return NULL;
}

Figura* Mapa::pickUp(float x, float y, uint16 mascara) {
	if (!isAdentro(x, y)) {
		return NULL;
	}
	b2Vec2 p(x, y);
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.001f, 0.001f);
	aabb.lowerBound = p - d;
	aabb.upperBound = p + d;
	//puede traer cualquier cosa, objetos del escenario de cualquier jugador
	QueryCallback callback(p, mascara,0, true, false);
	myWorld->QueryAABB(&callback, aabb);
	if (callback.m_fixture) {
		b2Body* body = callback.m_fixture->GetBody();
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
	return isAdentro1D(x, this->getX(), this->w) && isAdentro1D(y, this->getY(), this->h);
}

void Mapa::step() {
	myWorld->Step(this->frecuencia, this->velocidad, this->posicion);
//	cout << "joints " <<myWorld->GetJointCount() <<  endl;
	list<Figura*>::iterator it;
	//TODO VER OTRA FORMA DE HACER EL UPDATE.
	Figura * fig;
	for (it = this->figuras.begin(); it != this->figuras.end(); ++it) {
		fig = *it;
		fig->updateModelo();
		fig->updateVista();
	}
	list<Union*>::iterator it2;
	for (it2 = this->uniones.begin(); it2 != this->uniones.end(); ++it2) {
		fig = *it2;
		fig->updateModelo();
		fig->updateVista();
	}
	contactSolver->finalizarAcciones();
}

void Mapa::inicializar(float x, float y, float w, float h, float32 hz, int32 velocityIterations,
		int32 positionIterations) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->contactSolver = new ReglasContactoSolver();
	this->frecuencia = hz;
	this->velocidad = velocityIterations;
	this->posicion = positionIterations;

	//ENTREGA3 LEAK DONDE SE ELIMINA ESTA Y EL RESTO DE LAS AREAS?
	this->addArea(new Area(x,y,w,h),-1);
	crearMundo();
}

void Mapa::makeBackUp() {
	//TODO POR AHORA NO HAY FIGURAS QUE SE VAYAN EN LOS STEPS.
	list<Figura*>::iterator it;
	for (it = figuras.begin(); it != figuras.end(); ++it) {
		(*it)->makeBackUp();
	}
	list<Union*>::iterator it2;
	for (it2 = this->uniones.begin(); it2 != this->uniones.end(); ++it2) {
		(*it2)->makeBackUp();
	}
}

void Mapa::restoreBackUp() {
	list<Figura*>::iterator it;
	for (it = figuras.begin(); it != figuras.end(); ++it) {
		(*it)->restoreBackUp();
		(*it)->updateVista();
	}
	list<Union*>::iterator it2;
	for (it2 = this->uniones.begin(); it2 != this->uniones.end(); ++it2) {
		(*it2)->restoreBackUp();
		(*it2)->updateVista();
	}
	delete myWorld;
	crearMundo();
	for (it2 = uniones.begin(); it2!= uniones.end(); ++it2) {
		(*it2)->setWorld(NULL, NULL);
	}
	for (it = figuras.begin(); it != figuras.end(); ++it) {
		(*it)->setWorld(NULL, NULL);
	}
	for (it = figuras.begin(); it != figuras.end(); ++it) {
		(*it)->setWorld(myWorld, groundBody);
		(*it)->crearFisicaEstatica();
	}
	for (it2 = uniones.begin(); it2 != uniones.end(); ++it2) {
		(*it2)->setWorld(myWorld, groundBody);
		(*it2)->crearFisicaEstatica();
	}
}

void Mapa::crearMundo() {
	b2Vec2 gravity(0.0f, -10.0f);
	this->myWorld = new b2World(gravity);
	myWorld->SetContactListener(this->contactSolver);
	// Define the ground body.
	b2BodyDef groundBodyDef;
//	groundBodyDef.position.Set(50.0f, 50.0f);

	// Call the body mapa which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundBody = myWorld->CreateBody(&groundBodyDef);
	groundBody->SetUserData(this);
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
	for (it = figuras.begin(); it != figuras.end(); ++it) {
		(*it)->setWorld(myWorld, groundBody);
		(*it)->crearFisica();
	}
	list<Union*>::iterator it2;
	for (it2 = uniones.begin(); it2 != uniones.end(); ++it2) {
		(*it2)->setWorld(myWorld, groundBody);
		(*it2)->crearFisica();
	}

	for (it = figuras.begin(); it != figuras.end(); ++it) {
		(*it)->accionesPostFisica();
	}

}

bool Mapa::addFigura(Figura* figura) {
	int numero = figura->getNumeroJugador();
	std::map<int,Area*>::iterator it = this->areasDeJugadores.find(numero);
	if (!isAdentro(figura->getX(), figura->getY()) || !(it->second->isAdentro1D(figura->getX(),it->second->getX(),it->second->getAncho()))
			|| !(it->second->isAdentro1D(figura->getY(),it->second->getY(),it->second->getAlto()))) {
		return false;
	}
	figura->setWorld(myWorld, groundBody);
	bool result = figura->crearFisicaEstatica();
	if (result) {
		this->figuras.push_back(figura);
	}
	return result;

}

bool Mapa::removeFigura(Figura* figura) {
		figura->removerFisica();
		this->figuras.remove(figura);
		return true;
}

bool Mapa::addUnion(Union* u) {
//	int numero = u->getNumeroJugador();
//	std::map<int,Area*>::iterator it = this->areasDeJugadores.find(numero);
//	Area* area = it->second;
//	if (!isAdentro(u->getX(), u->getY()) || !(area->isAdentro1D(u->getXInicial(),area->getX(),area->getAncho())) ||
//			!(area->isAdentro1D(u->getXFinal(),area->getX(),area->getAncho())) || !(area->isAdentro1D(u->getYInicial(),area->getY(),area->getAlto())) ||
//			!(area->isAdentro1D(u->getYFinal(),area->getY(),area->getAlto()))) {
//		return false;
//	}
	u->setWorld(myWorld, groundBody);
	bool result = u->crearFisicaEstatica();
	if (result) {
		this->uniones.push_back(u);
		u->addObserver(this);
	}

	return result;

}

bool Mapa::removeUnion(Union* figura) {
	if (figura->getBody() != 0) {
		figura->removerFisica();
		this->uniones.remove(figura);
		figura->removeObserver(this);
		return true;
	}
	return false;

}

list<Union*>& Mapa::getUniones() {
	return uniones;
}

//solo me engancho a las uniones por ahora
void Mapa::notifyEvent(ObservableModelo* o, Evento_type type) {
	if(type == DESTRUCCION_FORZADA){
//		cout << "Se entera el mapa y agrega a los deleteables" << endl;;
		Union * u = dynamic_cast<Union*> (o);
		u->removerFisica();
		uniones.remove(u);
		figurasBorrar.push_back(u);
	}
}


void Mapa::cleanDeletes() {
//	cout << "deletea los deleteables el mapa antes" << endl;
	list<Figura*>::iterator it;
	for(it= this->figurasBorrar.begin(); it != figurasBorrar.end(); ++it){
		delete(*it);
	}
//	cout << "deletea los deleteables el mapa " << endl;
	figurasBorrar.clear();
}

void Mapa::addArea(Area* area, int numeroJugador){
	this->areasDeJugadores.insert(pair<int,Area*>(numeroJugador,area));
}

void Mapa::cortarUniones(b2Body*b) {
	list<Union*>::iterator it2;
	Union * fig;
	for (it2 = this->uniones.begin(); it2 != this->uniones.end(); ++it2) {
		fig = *it2;
		fig->cortar(b);
	}

}
