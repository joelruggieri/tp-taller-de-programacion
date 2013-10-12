
/*
 * Figura.cpp
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */
#include "Figura.h"
#include <iostream>
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

void Figura::setX(float x){
	this->x = x;
}

void Figura::setY(float y){
	this->y = y;
}

void Figura::setRotacion(double rotation){
//	int signo;
//	if(rotation <= -180 ){
//		signo = +1;
//	} else {
//		signo = -1;
//	}
	this->rotacion = rotation;
////	while(){
//	if(this->rotacion > 180 || this->rotacion <=  -180){
//		int multip = (int)this->rotacion % 360;
//		rotacion = rotacion + 360*signo * multip;
//		cout << "rotacion fig " << rotacion << endl;
//		if(this->rotacion > 180){
//			cout<< "mierda" << endl;
//		}
//	}

	//	this->rotacion = rotation;
//	if(this->rotacion < 0){
//		this->rotacion =  this->rotacion * -1;
//		this->rotacion = 360 - (int)this->rotacion % 360;
//	} else if(this->rotacion >= 360){
//		this->rotacion = (int)this->rotacion % 360;
//	}



}

Figura::Figura() {
	x= 0;
	y=0;
	rotacion = 0;
	vista= 0;
	this->body =0;
	xb = x;
	yb = y;
	rotacionb =0;
}

Figura::Figura(float x, float y) {
	this->x = x;
	this->y = y;
	this->rotacion = 0;
	vista= 0;
	this->body =0;
	xb = x;
	yb = y;
	rotacionb =0;
}


Figura::~Figura() {
	Lista_Enganches::iterator it;
	for(it= this->enganches.begin(); it!= enganches.end(); ++it){
		delete *it;
	}
}

 Vista* Figura::getVista(){
	return vista;
}

void Figura::setVista(Vista* vista) {
	this->vista = vista;
}


b2Body* Figura::getBody(){
	return this->body;
}

void Figura::setBody(b2Body* b){
	body = b;
}


void Figura::updateModelo() {
	if(this->body != 0){
		const b2Vec2 p = body->GetPosition();
		this->setX(p.x);
		this->setY(p.y);
		this->setRotacion( -1*radianesAGrados(body->GetAngle()));
	}
}

double Figura::radianesAGrados(float r) {
	return r * 180 / 3.14;
}

double Figura::gradosARadianes(float g) {
	return g*3.14/180;
}

void Figura::makeBackUp() {
	xb = x;
	yb =y;
	rotacionb = rotacion;
}

void Figura::restoreBackUp() {
	x= xb;
	y = yb;
	rotacion = rotacionb;
}

Lista_Enganches Figura::getEnganches(){
	return this->enganches;
}

Registro& Figura::getReg() {
	return reg;
}

void Figura::setReg(Registro r) {

	this->reg = r;
}

void Figura::updateVista(Transformacion& tl) {
			if(vista != 0)
				this->vista->update(tl);
}

void Figura::modificarSentido() {
}

void Figura::crearFisicaEstaticaTemplate(b2World* w, b2Body* ground) {
   this->crearFisica(w,ground);
}

bool Figura::crearFisicaEstatica(b2World*w, b2Body* ground) {
	this->crearFisicaEstaticaTemplate(w,ground);
	bool hayContacto = false;
	for (b2Body* b = w->GetBodyList(); b; b = b->GetNext()) {
		if (b != body && b->GetFixtureList()!= NULL  && b->GetFixtureList()->GetShape() != NULL){
			bool overlap = b2TestOverlap(body->GetFixtureList()->GetShape(), 0,
					b->GetFixtureList()->GetShape(), 0, body->GetTransform(),
					b->GetTransform());
			if(overlap ){
				hayContacto = true;
				break;
			}
		}
	}
	if (hayContacto) {
		w->DestroyBody(this->getBody());
		this->setBody(0);
		return false;
	}
	return true;
}
