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
	Enganche* engancheDerecho = new Enganche(this,0.9*ancho/2.0, 0);
	Enganche* engancheIzquierdo = new Enganche(this,-0.9*ancho/2.0, 0);
	enganches.push_back(engancheIzquierdo);
	enganches.push_back(engancheDerecho);
	xi= x -ancho/4.0;
	yi= y - alto/2;
	xd= x +ancho/4.0;
	yd= y - alto/2;
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
//	b2Vec2 extremoSuperiorIzquierdo(x -(ancho/2),y + (alto/2));
//	b2Vec2 extremoInferiorIzquierdo(x -(ancho/2),y - (alto/2));
//	b2Vec2 extremoSuperiorDerecho(x + (ancho/2),y + (alto/2));
//	b2Vec2 extremoInferiorDerecho(x + (ancho/2),y - (alto/2));
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
	//plataforma
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape * polygon = new b2PolygonShape();

	b2MassData masa;
	polygon->SetAsBox(this->ancho / 2, this->alto / 2);

	b2FixtureDef fixture;
	fixture.density = 10.00f;
	fixture.shape = polygon;
	fixture.friction = 10.0f;
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

	b2BodyDef bd;
	b2CircleShape* circle = new b2CircleShape();
	circle->m_radius =RADIO_RUEDA_CARRITO;
	b2FixtureDef fd;
	fd.filter.categoryBits = CATEGORIA_FIGURAS;
	fd.filter.maskBits = CATEGORIA_FIGURAS;
	fd.shape = circle;
	fd.density = 5.0f;
	fd.friction = 10.0f;
	bd.position =body->GetWorldPoint(b2Vec2(-ancho/4, -alto/2.0));
	bd.type = b2_dynamicBody;
	b2Body* bodyRuedaIzquierda = myWorld->CreateBody(&bd);
	bodyRuedaIzquierda->CreateFixture(&fd);
	bodyRuedaIzquierda->SetUserData(this);
	this->setRuedaIzquierda(bodyRuedaIzquierda);

	bd.position =body->GetWorldPoint(b2Vec2(ancho/4, -alto/2.0));
	b2Body* bodyRuedaDerecha = myWorld->CreateBody(&bd);
	bodyRuedaDerecha->CreateFixture(&fd);
	bodyRuedaDerecha->SetUserData(this);
	this->setRuedaDerecha(bodyRuedaDerecha);


	b2RevoluteJointDef rjd;
	rjd.Initialize(body,bodyRuedaIzquierda,bodyRuedaIzquierda->GetPosition());
	rjd.collideConnected= false;
	myWorld->CreateJoint(&rjd);
	b2RevoluteJointDef rjd2;
	rjd2.Initialize(body,bodyRuedaDerecha,bodyRuedaDerecha->GetPosition());
	rjd2.collideConnected= false;
	myWorld->CreateJoint(&rjd2);
	//JOINT
//	b2WheelJointDef jd;
//	jd.Initialize(body,bodyRuedaIzquierda,ruedaIzquierda->GetPosition(),b2Vec2(0, 1));
//	jd.motorSpeed = 0.0f;
//	jd.maxMotorTorque = 20.0f;
//	jd.collideConnected= false;
//	b2WheelJointDef jd2;
//	jd2.Initialize(body,bodyRuedaDerecha,ruedaDerecha->GetPosition(),b2Vec2(0,1));
//	jd2.maxMotorTorque = 20.0f;
//	jd2.collideConnected= false;
//	myWorld->CreateJoint(&jd2);
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


void Carrito::crearFisicaEstaticaTemplate() {

	b2BodyDef bd;
	b2PolygonShape shape;
	shape.SetAsBox(this->ancho / 2, this->alto / 2);
	b2FixtureDef plataformaDef;
	plataformaDef.filter.categoryBits = CATEGORIA_FIGURAS;
	plataformaDef.filter.maskBits = CATEGORIA_FIGURAS;
	plataformaDef.density = 1.0f;
	plataformaDef.friction = 0.9f;
	plataformaDef.shape = &shape;
	bd.position.Set(x,y);
	bd.angle= -gradosARadianes(this->getRotacion());
	body = myWorld->CreateBody(&bd);
	body->CreateFixture(&plataformaDef)->SetUserData(this);
	body->SetUserData(this);

	b2CircleShape shapeCircle;
	shapeCircle.m_radius = RADIO_RUEDA_CARRITO;
	b2FixtureDef ruedaDef;
	ruedaDef.filter.categoryBits = CATEGORIA_FIGURAS;
	ruedaDef.filter.maskBits = CATEGORIA_FIGURAS;
	ruedaDef.density = 1.0f;
	ruedaDef.friction = 0.9f;
	ruedaDef.shape = &shapeCircle;
	shapeCircle.m_p.Set(-ancho/4.0,- alto/2.0);
	body->CreateFixture(&ruedaDef);
	shapeCircle.m_p.Set(ancho/4.0, - alto/2.0);
	body->CreateFixture(&ruedaDef);

}

void Carrito::updateModelo() {
	super::updateModelo();
	if (this->body != 0) {
		const b2Vec2 p = body->GetPosition();
		this->setX(p.x);
		this->setY(p.y);
		this->rotacion = -1 * radianesAGrados(body->GetAngle());
		const b2Vec2 p2 = ruedaIzquierda->GetPosition();
		xi = p2.x;
		yi = p2.y;
		this->rotI =-1 * ruedaIzquierda->GetAngle();
		const b2Vec2 p3= ruedaDerecha->GetPosition();
		xd = p3.x;
		yd = p3.y;
		this->rotD =-1 * ruedaDerecha->GetAngle();

	}
}


float Carrito::getRotD() const {
	return rotD;
}

float Carrito::getRotI() const {
	return rotI;
}

float Carrito::getXd() const {
	return xd;
}

float Carrito::getXi() const {
	return xi;
}

float Carrito::getYd() const {
	return yd;
}

float Carrito::getYi() const {
	return yi;
}

void Carrito::setPosicion(float x, float y) {
	xi= -ancho/4.0;
	yi= -alto/2;
	xd= ancho/4.0;
	yd= -alto/2;
	b2Vec2 pos(xi,yi);
	b2Rot rotacion(-1 * gradosARadianes(getRotacion()));
	b2Vec2 rotado = b2Mul(rotacion, pos);
	xi = rotado.x + x ;
	yi = rotado.y + y;
	pos.x=xd;
	pos.y=yd;
	rotado = b2Mul(rotacion, pos);
	yd= rotado.y +y ;
	xd= rotado.x +x;
	super::setPosicion(x,y);
}

void Carrito::setRotacion(double rotation) {
	super::setRotacion(rotation);
	setPosicion(x,y);
}

void Carrito::makeBackUp() {
	super::makeBackUp();
	rotIb= rotI;
	rotDb=rotD;
	xib=xi;
	yib=yi;
	xdb=xd;
	ydb=yd;

}

void Carrito::restoreBackUp() {
	super::restoreBackUp();
	rotI= rotIb;
	rotD=rotDb;
	xi=xib;
	yi=yib;
	xd=xdb;
	yd=ydb;

}
