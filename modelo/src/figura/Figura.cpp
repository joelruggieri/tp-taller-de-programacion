/*
 * Figura.cpp
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */
#include "Figura.h"
#include <iostream>
#include "Mapa.h"
#include "../interaccion/ValidadorNoInteraccion.h"
using namespace std;

float Figura::getX() const {
	return x;
}

float Figura::getY() const {
	return y;
}

double Figura::getRotacion() const {
	return rotacion;
}

void Figura::setX(float x) {
	this->x = x;
}

void Figura::setY(float y) {
	this->y = y;
}

void Figura::setRotacion(double rotation) {
	this->rotacion = rotation;
	notify(CAMBIO_ESPACIAL_FORZADO);
}

Figura::Figura() {
	x = 0;
	y = 0;
	rotacion = 0;
	vista = 0;
	this->body = 0;
	xb = x;
	yb = y;
	rotacionb = 0;
	traccionable = false;
	numeroJugadorDuenio = -1;
	validador = new ValidadorNoInteraccion(this);
	ground = NULL;
	myWorld = NULL;
	accionado =false;
	viva = true;
}

Figura::Figura(float x, float y) {
	traccionable = false;
	this->x = x;
	this->y = y;
	this->rotacion = 0;
	vista = 0;
	this->body = 0;
	xb = x;
	yb = y;
	rotacionb = 0;
	numeroJugadorDuenio = -1;
	validador = new ValidadorNoInteraccion(this);
	ground = NULL;
	myWorld = NULL;
	accionado = false;
	viva = true;
}


Figura::Figura(float x, float y, ValidadorInteraccion* validador) {
	traccionable = false;
	this->x = x;
	this->y = y;
	this->rotacion = 0;
	vista = 0;
	this->body = 0;
	xb = x;
	yb = y;
	rotacionb = 0;
	numeroJugadorDuenio = -1;
	this->validador = validador;
	ground = NULL;
	myWorld = NULL;
	accionado = false;
	viva = true;
}

Figura::~Figura() {
	Lista_Enganches::iterator it;
	for (it = this->enganches.begin(); it != enganches.end(); ++it) {
		delete *it;
	}
	notify(DESPUES_DESTRUCCION);
	delete validador;

}

Vista* Figura::getVista() {
	return vista;
}

void Figura::setVista(Vista* vista) {
	this->vista = vista;
}

b2Body* Figura::getBody() {
	return this->body;
}

void Figura::setBody(b2Body* b) {
	body = b;
}

void Figura::updateModelo() {
	if (this->body != 0) {
		const b2Vec2 p = body->GetPosition();
		this->setX(p.x);
		this->setY(p.y);
		this->rotacion = -1 * radianesAGrados(body->GetAngle());
	}
}

double Figura::radianesAGrados(float r) {
	return r * 180 / 3.14;
}

double Figura::gradosARadianes(float g) {
	return g * 3.14 / 180;
}

void Figura::makeBackUp() {
	xb = x;
	yb = y;
	rotacionb = rotacion;
}

void Figura::restoreBackUp() {
	x = xb;
	y = yb;
	rotacion = rotacionb;
	accionado = false;
	viva = true;
}

Lista_Enganches & Figura::getEnganches() {
	return this->enganches;
}

Registro& Figura::getReg() {
	return reg;
}

void Figura::setReg(Registro r) {

	this->reg = r;
}

void Figura::updateVista() {
//			if(vista != 0)
//				this->vista->update();
}

void Figura::modificarSentido() {
}

void Figura::crearFisicaEstaticaTemplate() {
	this->crearFisica();
}

bool Figura::crearFisicaEstatica() {
	if (myWorld != NULL) {
		this->crearFisicaEstaticaTemplate();
		bool hayContacto = false;
		for (b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()) {
			if (b != this->body && b->GetFixtureList() != NULL && b->GetFixtureList()->GetShape() != NULL) {
				if (validarContacto(this->body, b)) {
					hayContacto = true;
					break;
				}
			}
		}
		if (hayContacto) {
			removerFisica();
		} else {
			notify(FISICA_E_CREADA);
		}
		return !hayContacto;
	} else {
		return false;
	}
}

void Figura::removerFisica() {

	if (body != NULL) {
		notify(FISICA_REMOVIDA);
		myWorld->DestroyBody(this->getBody());
	}
	this->setBody(NULL);
}

Figura::Figura(const Figura& fig) {
	this->reg = fig.reg;
	this->x = fig.x;
	this->xb = fig.xb;
	this->y = fig.y;
	this->yb = fig.y;
	this->rotacion = fig.rotacion;
	this->rotacionb = fig.rotacion;
	this->numeroJugadorDuenio = fig.numeroJugadorDuenio;
	ground = fig.ground;
	myWorld = fig.myWorld;
	validador = fig.validador->clone(this);
	body = fig.body ;
	vista = NULL;
	traccionable = fig.traccionable;
	accionado = false;
	viva = true;
}

bool Figura::esTraccionable() {
	return this->traccionable;
}

bool Figura::agregar(Mapa* m) {
	return m->addFigura(this);
}

bool Figura::remover(Mapa*m) {
	return m->removeFigura(this);
}

void Figura::setWorld(b2World* w, b2Body * g) {
	this->myWorld = w;
	this->ground = g;
	limpiarReferenciasB2D();
}

void Figura::setPosicion(float x, float y) {
	setX(x);
	setY(y);
	notify(CAMBIO_ESPACIAL_FORZADO);
}

void Figura::setNumeroJugador(int jugadorDuenio) {
	this->numeroJugadorDuenio = jugadorDuenio;
}

int Figura::getNumeroJugador() {
	return numeroJugadorDuenio;
}

void Figura::interactuarTemplate() {
	this->accionar();
}

void Figura::accionar() {
}

void Figura::interactuar(Area& area, int jugador) {
	if(validador->validar(area,jugador)){
		interactuarTemplate();
		accionado = true;
	}
}

bool Figura::isViva() {
	return viva;
}

void Figura::limpiarReferenciasB2D() {
//	setBody(NULL);
}

void Figura::accionesPostFisica() {
}

void Figura::desenganchado(Enganche*) {
}

void Figura::explotar() {
}

void Figura::recibirImpacto(b2Vec2 direccion) {
}
//ENTREGA3 EZE PASANDOSE POR LAS BOLAS EL STRATEGY DE VALIDACION
void Figura::interactuarNoArea(Area& area, int jugador) {
	if(!validador->validar(area,jugador)){
		interactuarTemplate();
		accionado = true;
	}
}

void Figura::realizarImpacto(b2Vec2 direccion) {
	b2Vec2 centro(this->getX(), this->getY());
	b2Vec2 versor = (centro - direccion);
	float modulo = (centro - direccion).Length();
	versor.x = versor.x / modulo;
	versor.y = versor.y / modulo;
	this->body->ApplyLinearImpulse(7500*versor, b2Vec2(this->getX(), this->getY()));
}

bool Figura::validarContacto(b2Fixture* prim,const b2Transform& trfprim, b2Fixture* sec, const b2Transform& trfsec) {
	uint16 catA = prim->GetFilterData().categoryBits;
	uint16 maskA = prim->GetFilterData().maskBits;
	uint16 catB = sec->GetFilterData().categoryBits;
	uint16 maskB = sec->GetFilterData().maskBits;
	return b2TestOverlap(prim->GetShape(), 0, sec->GetShape(), 0,
			trfprim, trfsec) && (catA & maskB) != 0 && (catB & maskA) != 0;


}


bool Figura::validarContacto(b2Body * verf, b2Body * b) {
	if( verf->GetUserData() == b->GetUserData() && b->GetUserData() != NULL){
		return false;
	}
	b2Fixture* prim = verf->GetFixtureList();
	b2Fixture* sec;
	while(prim != NULL){
		sec = b->GetFixtureList();
		while(sec != NULL){
			if(validarContacto(prim, verf->GetTransform(), sec, b->GetTransform())){
				return true;
			}
			sec = sec->GetNext();
		}
		prim = prim->GetNext();
	}

	return false;

}
