/*
 * Jugador.cpp
 *
 *  Created on: 27/10/2013
 *      Author: jonathan
 */

#include "Jugador.h"

Jugador::Jugador() {
	area= new Area(50,50,100,100);
	numero = 0;
}

Area* Jugador::getArea() const{
	return area;
}

int Jugador::getNumero() const{
	return numero;
}

void Jugador::setNumero(int numero){
	this->numero = numero;
}

void Jugador::setArea(Area* unArea){
	this->area = unArea;
}
Jugador::~Jugador() {
	delete area;
}

Jugador::Jugador(const Jugador& jugador){
	this->area = jugador.area;
	this->numero = jugador.getNumero();
}

void Jugador::agregarParametroFactory(FactoryParam* parametro){
	this->parametrosFactories.push_back(parametro);
}

std::list<FactoryParam*> Jugador::getParametrosFactories() const{
	return this->parametrosFactories;
}

void Jugador::setParametrosFactories(std::list<FactoryParam*> lista){
	this->parametrosFactories = lista;
}
