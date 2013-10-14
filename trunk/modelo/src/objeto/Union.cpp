/*
 * Union.cpp
 *
 *  Created on: 14/10/2013
 *      Author: jonathan
 */

#include "Union.h"

Union::Union() {
	// TODO Auto-generated constructor stub

}

Union::~Union() {
	// TODO Auto-generated destructor stub
}

void Union::setFin(const b2Vec2& fin) {
	this->fin = fin;
}

void Union::setInicio(const b2Vec2& inicio) {
	this->inicio = inicio;
}

float Union::getXInicial() {
	return inicio.x;
}

float Union::getYInicial() {
	return inicio.y;
}

float Union::getXFinal() {
	return fin.x;
}

float Union::getYFinal() {
	return fin.y;
}
