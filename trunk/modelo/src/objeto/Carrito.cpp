/*
 * Carrito.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "Carrito.h"
#include "../Constantes.h"
#include "Densidades.h"
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
	//plataforma
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape * polygon = new b2PolygonShape();

	b2MassData masa;
	polygon->SetAsBox(this->ancho / 2, this->alto / 2);

	b2FixtureDef fixture;
	fixture.density = DENSIDAD_CARRITO_PLATAFORMA;
	fixture.shape = polygon;
	fixture.friction = 1.0f;
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
	body->CreateFixture(&fixture)->SetUserData(this);
	body->SetUserData(this);
	this->setBody(body);

	b2BodyDef bd;
	b2CircleShape* circle = new b2CircleShape();
	circle->m_radius =RADIO_RUEDA_CARRITO;
	b2FixtureDef fd;
	fd.filter.categoryBits = CATEGORIA_FIGURAS;
	fd.filter.maskBits = CATEGORIA_FIGURAS;
	fd.shape = circle;
	fd.density = DENSIDAD_CARRITO_RUEDA;
	fd.friction = 10.0f;
	bd.position =body->GetWorldPoint(b2Vec2(-ancho/4, -alto/2.0));
	bd.type = b2_dynamicBody;
	b2Body* bodyRuedaIzquierda = myWorld->CreateBody(&bd);
	bodyRuedaIzquierda->CreateFixture(&fd)->SetUserData(this);
	bodyRuedaIzquierda->SetUserData(this);
	this->setRuedaIzquierda(bodyRuedaIzquierda);

	bd.position =body->GetWorldPoint(b2Vec2(ancho/4, -alto/2.0));
	b2Body* bodyRuedaDerecha = myWorld->CreateBody(&bd);
	bodyRuedaDerecha->CreateFixture(&fd)->SetUserData(this);
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
	super::setPosicion(x,y);
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

void Carrito::recibirImpacto(b2Vec2 direccion) {
	this->realizarImpacto(direccion);
}

void Carrito::limpiarReferenciasB2D() {
	ruedaIzquierda= NULL;
	ruedaDerecha = NULL;
}
