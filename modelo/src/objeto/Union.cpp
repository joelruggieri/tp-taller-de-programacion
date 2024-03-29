/*
 * Union.cpp
 *
 *  Created on: 14/10/2013
 *      Author: jonathan
 */

#include "Union.h"
#include "../figura/Mapa.h"
#include "../observer/ObservableModelo.h"
Union::Union(float x, float y, float h) :
		Objeto(x, y) {
	this->h = h;
	this->figuraFin = NULL;
	this->figuraInicio = NULL;
	this->wB = this->w;
	this->hB = this->h;
	eventHelper = new ObserverFiguraHelper(this);
	joint = NULL;
	estatica = true;
}

Union::Union() :
		Objeto() {
	figuraInicio = NULL;
	figuraFin = NULL;
	eventHelper = new ObserverFiguraHelper(this);
	joint = NULL;
	estatica = true;
}

Union::~Union() {
	//RESPONSABILIDAD DE LA CLASE HIJA QUE LO USA DE SACARLO DE DONDE SEA, SINO VUELA TODO CUANDO SE DELETEA LA UNION.
	if (figuraInicio != NULL) {
		figuraInicio->removeObserver(eventHelper);
	}
	if (figuraFin != NULL) {
		figuraFin->removeObserver(eventHelper);
	}

	delete eventHelper;
}

float Union::getXInicial() const {
	return inicio.x;
}

float Union::getYInicial() const {
	return inicio.y;
}

float Union::getXFinal() const {
	return fin.x;
}

float Union::getYFinal() const {
	return fin.y;
}

void Union::setXInicial(float xInicial) {
	this->inicio.x = xInicial;
}

void Union::setYInicial(float yInicial) {
	inicio.y = yInicial;
}

void Union::setXFinal(float xFinal) {
	fin.x = xFinal;
}

void Union::setYFinal(float yFinal) {
	fin.y = yFinal;
}

float Union::calcularDistancia(b2Vec2 a, b2Vec2 b) {
	b2Vec2 dif = a - b;
	return dif.Length();
}

void Union::calcularCentroCuadrado() {
	this->x = (this->inicio.x + this->fin.x) / 2;
	this->y = (this->inicio.y + this->fin.y) / 2;
}

void Union::calcularAnguloCuadrado() {
	b2Vec2 dist1, dist2, dist3, dist4;
	dist1.x = 0;
	dist1.y = this->fin.y;
	dist2.x = 0;
	dist2.y = this->inicio.y;
	dist3.x = this->fin.x;
	dist3.y = 0;
	dist4.x = this->inicio.x;
	dist4.y = 0;
	float distanciaA = (dist1 - dist2).Length();
	float distanciaB = (dist3 - dist4).Length();
	if (distanciaB == 0) {
		this->rotacion = 0;
	} else
		this->rotacion = atan(distanciaA / distanciaB);
}

//void Union::setFiguraInicio(Figura* a) {
//	this->figuraInicio = a;
//	this->inicio.x = a->getX();
//	this->inicio.y = a->getY();
//}
//
//void Union::setFiguraFin(Figura* a) {
//	this->figuraFin = a;
//	this->fin.x = a->getX();
//	this->fin.y = a->getY();
//}

void Union::calcularAnchoCuadrado() {
	this->w = this->calcularDistancia(this->inicio, this->fin);
}

void Union::crearFisicaEstaticaTemplate() {
	joint = NULL;
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2CircleShape shapeCircle;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(centro.x, centro.y);
	b2Body* body = myWorld->CreateBody(&bodyDef);
	shapeCircle.m_radius = this->h / 2;
	b2FixtureDef bodyBolaBoliche;
	bodyBolaBoliche.filter.categoryBits = CATEGORIA_UNION;
	bodyBolaBoliche.filter.maskBits = 0;
	bodyBolaBoliche.shape = &shapeCircle;
	body->CreateFixture(&bodyBolaBoliche);
	body->SetUserData(this);
	this->setBody(body);
	estatica = true;

}

void Union::setExtremos(Figura* f1, Figura* f2) {
	setearPuntoInicial(f1);
	f1->addObserver(this->eventHelper);
	setearPuntoFinal(f2);
	f2->addObserver(this->eventHelper);
	updateCaracteristicas();
}

void Union::updateCaracteristicas() {
	this->updatePosicionesFiguras();
	this->calcularAnchoCuadrado();
	this->calcularAnguloCuadrado();
	this->calcularCentroCuadrado();
}

void Union::updateModelo() {
	super::updateModelo();
	this->updateCaracteristicas();

}

void Union::updatePosicionesFiguras() {
	this->inicio.x = this->figuraInicio->getX();
	this->inicio.y = this->figuraInicio->getY();
	this->fin.x = this->figuraFin->getX();
	this->fin.y = this->figuraFin->getY();

}

void Union::makeBackUp() {
	this->inicioB = this->inicio;
	this->finB = this->fin;
	this->wB = this->w;
	this->hB = this->h;
	super::makeBackUp();
}

void Union::restoreBackUp() {
	this->inicio = this->inicioB;
	this->fin = this->finB;
	this->w = this->wB;
	this->h = this->hB;
	super::restoreBackUp();
}

bool Union::agregar(Mapa* m) {
	return m->addUnion(this);
}

bool Union::remover(Mapa* m) {
	return m->removeUnion(this);
}

Union::Union(const Union& figura) :
		Objeto(figura) {
	this->inicio = figura.inicio;
	this->fin = figura.fin;
	this->calcularCentroCuadrado();
	this->reg = figura.reg;
	this->h = figura.h;
	this->calcularAnchoCuadrado();
	this->calcularAnguloCuadrado();
	this->calcularCentroCuadrado();
	this->figuraFin = NULL;
	this->figuraInicio = NULL;
	this->wB = this->w;
	this->hB = this->h;
	joint = NULL;
	eventHelper = new ObserverFiguraHelper(this);
	estatica = true;
}

uint16 Union::getMascaraExtremos() {
	return CATEGORIA_FIGURAS;
}

void Union::notifyEvent(Evento_type enumEvento) {
	ObservableModelo * o = this->eventHelper->getLastObservable();
	if (enumEvento == DESPUES_DESTRUCCION
			&& (o == figuraFin || o == figuraInicio)) {
		if (o == figuraFin) {
			figuraFin = NULL;
		}
		if (o == figuraInicio) {
			figuraInicio = NULL;
		}
//		cout << "la union se entera de la destruccion del extremo y solicita su destruccion" << endl;
		notify(DESTRUCCION_FORZADA);
	}
	if (enumEvento == FISICA_REMOVIDA) {
//		cout << "me entere remocion fisica" << endl;
		this->removerFisica();
	}
	if (enumEvento == CAMBIO_ESPACIAL_FORZADO) {
//		cout << "me entere cambio espacial forzado" << endl;
		updatePosicionesFigurasSinFisica();
		calcularCentroCuadrado();
//		vista->update();
	}
	if (enumEvento == FISICA_E_CREADA) {
//		cout << "me entere creacion fisica" << endl;
		updateCaracteristicas();
		this->crearFisicaEstatica();
//		vista->update();
	}

}

void Union::updatePosicionesFigurasSinFisica() {
	updatePosicionesFiguras();

}

bool Union::estaEstatica() {
	return estatica;
}

float Union::getRadio() {
	return this->h / 2;
}

void Union::cortar(b2Body*) {
	//por defecto ninguna union se corta.
}

bool Union::bodyEntre(b2Body* b, b2Vec2 inicio, b2Vec2 fin) {
	//Creo un cuerpo fake
//	b2Vec2 segmento = fin - inicio;
//	float norma = segmento.Length();
//	//calculo el director ya con el ancho del cuerpo prueba.
//	b2Vec2 director(segmento.x/ norma, segmento.y/norma);
//	director= b2Vec2(director.x*0.1, director.y*0.1);
//	b2Vec2 v1(-director.y, director.x);
//	b2Vec2 v2( v1.x * -1, v1.y * -1);
//
	b2Vec2 centro = inicio + fin;
	centro= b2Vec2(centro.x/2,centro.y/2);
//
//	b2Vec2 vertices[4];
//	vertices[0] = v2 + inicio - centro;
//	vertices[1] = v2 + fin - centro;
//	vertices[2] = v1 + fin -centro;
//	vertices[3] = v1 + inicio- centro ;

//	b2PolygonShape polygon;
//	polygon.Set(vertices, 4);

	b2EdgeShape polygon;
	polygon.Set(inicio- centro , fin-centro);




	b2FixtureDef fixture;
	fixture.filter.categoryBits = CATEGORIA_CUERPO_CORTE_TIJERA;
	fixture.filter.maskBits = CATEGORIA_CUERPO_CORTE_TIJERA;
	fixture.shape = &polygon;
	b2BodyDef bodyDef;
	bodyDef.position=centro;
	bodyDef.angle = 0;
	b2Body* bodyFake = myWorld->CreateBody(&bodyDef);
	bodyFake->CreateFixture(&fixture);
	bodyFake->SetUserData(this);
	//testeo el overlap

	bool result = validarContacto(bodyFake,b);

	myWorld->DestroyBody(bodyFake);
	return result;

	//deleteo el cuerpo fake.

}
