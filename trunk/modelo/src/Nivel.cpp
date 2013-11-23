/*
 * Nivel.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "Nivel.h"
#include <iostream>
#include "Objetivos/ObjetivoDesdeHasta.h"
using namespace std;

Nivel::Nivel(std::string nombre, int cantJugadores, Objetivo * obj) {
	this->nombre = nombre;
	this->numeroMaximoDeJugadores = cantJugadores;
	objetivoJuego= new ObjetivoDesdeHasta(50,60,50,50,1);
}

Nivel::Nivel(std::string nombre){
	this->nombre = nombre;
	this->numeroMaximoDeJugadores = 0;
	objetivoJuego= new ObjetivoDesdeHasta(50,60,50,50,1);
}

Nivel::~Nivel() {
	std::list<Figura*>::iterator it;
	for (it = this->objetos.begin(); it != this->objetos.end(); ++it) {
		delete (*it);
	}

}

void Nivel::agregar(Figura* figura) {
	objetos.push_back(figura);
}

int Nivel::cantidadFiguras() const {
	return objetos.size();
}

std::list<Figura*> &Nivel::getFiguras() {
	return objetos;
}

const std::string& Nivel::getNombre() const {
	return nombre;
}

void Nivel::setNombre(const std::string& nombre) {
	this->nombre = nombre;
}

void Nivel::setFondo(std::string fondo) {
	this->fondo = fondo;
}

std::string Nivel::getFondo() const {
	return fondo;
}

Nivel::Nivel() {
	numeroMaximoDeJugadores = 0;
	objetivoJuego= new ObjetivoDesdeHasta(50,60,50,50,1);
}

std::list<Jugador*>& Nivel::getJugadores(){
	return jugadores;
}

void Nivel::agregarJugador(Jugador* unJugador){
	this->jugadores.push_back(unJugador);
}

void Nivel::setNumeroMaximoJugadores(int jugadores) {
	this->numeroMaximoDeJugadores = jugadores;
}

int Nivel::getNumeroMaximoJugadores() const{
	return numeroMaximoDeJugadores;
}

int Nivel::getNumeroJugadores() const{
	return jugadores.size();
}

Objetivo* Nivel::getObjetivo() {
	return objetivoJuego;
}
