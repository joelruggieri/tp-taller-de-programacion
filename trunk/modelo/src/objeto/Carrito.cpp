/*
 * Carrito.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "Carrito.h"
#include "../Constantes.h"

Carrito::Carrito(): Objeto(){
	ancho = 0;
	alto = 0;
}

Carrito::Carrito(const Carrito& figura){
	x = figura.getX();
	y = figura.getY();
	alto = figura.getAlto();
	ancho = figura.getAncho();
	body = figura.body;
	rotacion  = figura.getRotacion();
	vista = figura.vista;
	this->reg = figura.reg;
	this->ruedaDerecha = figura.ruedaDerecha;
	this->ruedaIzquierda = figura.ruedaIzquierda;
}

Carrito::Carrito(float x, float y, float ancho, float alto): Objeto(x,y) {
	this->ancho = ancho;
	this->alto = alto;
	Enganche* engancheDerecho = new Enganche(this,ancho/2.0,alto/2.0);
	Enganche* engancheIzquierdo = new Enganche(this,-1.0*ancho/2.0,alto/2.0);
	enganches.push_back(engancheIzquierdo);
	enganches.push_back(engancheDerecho);

}

float Carrito::getAlto() const{
	return this->alto;
}

float Carrito::getAncho() const{
	return this->ancho;
}

void Carrito::setAlto(float alto){
	this->alto = alto;
}

void Carrito::setAncho(float ancho){
	this->ancho = ancho;
}


void Carrito::acept(VisitorFigura* visitor){
	visitor->visit(this);
}


void Carrito::crearFisica(){
	/*float x = this->getX();
	float y = this->getY();
	float ancho = this->getAncho();
	float alto = this->getAlto();
	//b2Vec2 centro(x,y);
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(x,y);
	bd.fixedRotation = false;
	b2FixtureDef fixture;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	b2Body* body = myWorld->CreateBody(&bd);
	b2EdgeShape* shape = new b2EdgeShape();*/
	b2Vec2 extremoSuperiorIzquierdo(x -(ancho/2),y + (alto/2));
	b2Vec2 extremoInferiorIzquierdo(x -(ancho/2),y - (alto/2));
	b2Vec2 extremoSuperiorDerecho(x + (ancho/2),y + (alto/2));
	b2Vec2 extremoInferiorDerecho(x + (ancho/2),y - (alto/2));
	/*shape->Set(extremoSuperiorIzquierdo,extremoInferiorIzquierdo);
	shape->m_hasVertex3 = true;
	shape->m_vertex3 = extremoInferiorDerecho;
	fixture.shape = shape;
	body->CreateFixture(&fixture);
	//body->CreateFixture(shape,1.0);

	shape->Set(extremoInferiorIzquierdo,extremoInferiorDerecho);
	shape->m_hasVertex0 = true;
	shape->m_hasVertex3 = true;
	shape->m_vertex0 = extremoSuperiorIzquierdo;
	shape->m_vertex3 = extremoSuperiorDerecho;
	fixture.shape = shape;
	body->CreateFixture(&fixture);
	//body->CreateFixture(&fixture);
	//body->CreateFixture(shape,1.0);

	shape->Set(extremoInferiorDerecho,extremoSuperiorDerecho);
	shape->m_hasVertex0 = true;
	shape->m_vertex0 = extremoInferiorIzquierdo;
	fixture.shape = shape;
	body->CreateFixture(&fixture);
	//body->CreateFixture(&fixture);
	//body->CreateFixture(shape,1.0);
	body->SetUserData(this);*/
	//RUEDAS
	b2BodyDef bd;
	b2CircleShape* circle = new b2CircleShape();
	circle->m_radius = ancho/4;
	b2FixtureDef fd;
	fd.filter.categoryBits = CATEGORIA_FIGURAS;
	fd.filter.maskBits = CATEGORIA_FIGURAS;
	fd.shape = circle;
	fd.density = 1.0f;
	fd.friction = 0.9f;

	bd.position.Set(extremoInferiorIzquierdo.x + fd.shape->m_radius,extremoInferiorIzquierdo.y - (fd.shape->m_radius + 0.01));
	bd.type = b2_dynamicBody;
	b2Body* bodyRuedaIzquierda = myWorld->CreateBody(&bd);
	bodyRuedaIzquierda->CreateFixture(&fd);
	bodyRuedaIzquierda->SetUserData(this);
	this->setRuedaIzquierda(bodyRuedaIzquierda);

	bd.position.Set(extremoInferiorDerecho.x - fd.shape->m_radius,extremoInferiorDerecho.y - (fd.shape->m_radius + 0.01));
	b2Body* bodyRuedaDerecha = myWorld->CreateBody(&bd);
	bodyRuedaDerecha->CreateFixture(&fd);
	bodyRuedaDerecha->SetUserData(this);
	this->setRuedaDerecha(bodyRuedaDerecha);

	//plataforma
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape * polygon = new b2PolygonShape();

	b2MassData masa;
	polygon->SetAsBox(this->ancho / 2, this->alto / 2);

	b2FixtureDef fixture;
	fixture.density = 50.00f;
	fixture.shape = polygon;
	fixture.friction = 0.4f;
	fixture.restitution = 0.00f;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = false;

	double rotacionRad = this->getRotacion() * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	//body->CreateFixture(polygon, 10.0f);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);

	//JOINT
	b2WheelJointDef jd;

	jd.Initialize(body,bodyRuedaIzquierda,bodyRuedaIzquierda->GetPosition(),body->GetPosition());
	jd.motorSpeed = 0.0f;
	jd.maxMotorTorque = 20.0f;
	jd.enableMotor = true;
	jd.frequencyHz = 4.0;
	jd.dampingRatio = 0.7;
	//b2WheelJoint* m_spring1 = (b2WheelJoint*)myWorld->CreateJoint(&jd);

	jd.Initialize(body,bodyRuedaDerecha,bodyRuedaDerecha->GetPosition(),body->GetPosition());
	jd.motorSpeed = 0.0f;
	jd.maxMotorTorque = 10.0f;
	jd.enableMotor = false;
	jd.frequencyHz = 4.0;
	jd.dampingRatio = 0.7;
	//b2WheelJoint* m_spring2 = (b2WheelJoint*)myWorld->CreateJoint(&jd);
}

Carrito::~Carrito() {
	// TODO Auto-generated destructor stub
}

void Carrito::setRuedaDerecha(b2Body* bodyRuedaDerecha){
		this->ruedaDerecha = bodyRuedaDerecha;
}

void Carrito::setRuedaIzquierda(b2Body* bodyRuedaIzquierda){
		this->ruedaIzquierda = bodyRuedaIzquierda;
}


bool Carrito::crearFisicaEstatica() {
	if (myWorld != NULL) {
		this->crearFisicaEstaticaTemplate();
		bool hayContacto = false;
		for (b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()) {
			if (b != this->body && b != this->ruedaDerecha && b != this->ruedaIzquierda && b->GetFixtureList() != NULL && b->GetFixtureList()->GetShape() != NULL) {
				if (validarContacto(this->body, b) || validarContacto(this->ruedaDerecha, b) || validarContacto(this->ruedaIzquierda, b)) {
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
