
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
	this->rotacion = rotation;
	if(this->rotacion < 0){
		this->rotacion =  this->rotacion * -1;
		this->rotacion = 360 - (int)this->rotacion % 360;
	} else if(this->rotacion > 360){
		this->rotacion = (int)this->rotacion % 360;
	}
}

Figura::Figura() {
	x= 0;
	y=0;
	rotacion = 0;
	this->rotador = 0;
	vista= 0;
	this->body =0;
}

Figura::Figura(float x, float y, Rotador * rotador) {
	this->x = x;
	this->y = y;
	this->rotacion = 0;
	this->rotador = rotador;
	vista= 0;
	this->body =0;
}


Figura::~Figura() {
}

void Figura::setRotador(Rotador* rotador) {
	this->rotador = rotador;
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

Rotador* Figura::getRotador(){
	return this->rotador;
}

void Figura::updateModelo(Transformacion & tl) {
	if(this->body != 0){
		const b2Vec2 p = body->GetPosition();
		this->setX(p.x);
		this->setY(p.y);
		this->setRotacion( -1*radianesAGrados(body->GetAngle()));
		cout << "("<<p.x <<","<<p.y << ")"<<endl;
		if(vista != 0)
			this->vista->update(tl);
	}
}

double Figura::radianesAGrados(float r) {
	return r * 180 / 3.14;
}

double Figura::gradosARadianes(float g) {
	return g*3.14/180;
}
