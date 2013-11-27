/*
 * Nivel.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "Nivel.h"
#include <iostream>
#include "Objetivos/ObjetivoDesdeHasta.h"
#include "Objetivos/Objetivo.h"
using namespace std;

Nivel::Nivel(std::string nombre, int cantJugadores, Objetivo * obj) {
	this->nombre = nombre;
	this->numeroMaximoDeJugadores = cantJugadores;
	objetivoJuego= new ObjetivoDesdeHasta(50,60,99,99,1);
}

Nivel::Nivel(std::string nombre){
	this->nombre = nombre;
	this->numeroMaximoDeJugadores = 0;
	objetivoJuego= new ObjetivoDesdeHasta(50,60,99,99,1);
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
//	objetivoJuego= new ObjetivoDesdeHasta(11,85,68.2,20,1);
//	objetivoJuego = new Objetivo(10,77,2);
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

void Nivel::setObjetivo(int obj) {
	if(obj == 3)
		objetivoJuego= new ObjetivoDesdeHasta(11,85,68.2,20,3);
	else if(obj == 2)
		objetivoJuego = new Objetivo(10,77,2);
//	else if(obj == 1)
//		3er objetivo
	else if(obj == 0)
		objetivoJuego = new Objetivo(0,0,0);
	else objetivoJuego = new Objetivo(0,0,0);
}
