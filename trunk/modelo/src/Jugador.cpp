/*
 * Jugador.cpp
 *
 *  Created on: 27/10/2013
 *      Author: jonathan
 */

#include "Jugador.h"
#include <iostream>
using namespace std;

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
	this->area = new Area(jugador.getArea()->getX(),jugador.getArea()->getY(),jugador.getArea()->getAncho(),jugador.getArea()->getAlto());
	this->numero = jugador.getNumero();
	this->parametrosFactories = jugador.getParametrosFactories();
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

void Jugador::recibirTags(std::list<std::string>& lista){
	std::list<FactoryParam*>::iterator it;
	for(it = this->getParametrosFactories().begin(); it != this->getParametrosFactories().end(); it++){
		lista.push_back((*it)->getNombre());
	}
}
