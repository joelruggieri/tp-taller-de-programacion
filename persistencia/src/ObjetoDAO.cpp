/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"
#include <iostream>
#include <fstream>


#include "src/figura/Figura.h"
#include "src/objeto/Plataforma.h"
#include "src/objeto/Balancin.h"
#include "src/objeto/Tijera.h"
#include "src/objeto/Carrito.h"
#include "src/objeto/CintaTransportadora.h"
#include "src/objeto/BolaBoliche.h"
#include "src/objeto/GloboHelio.h"
#include "src/objeto/Gancho.h"
#include "src/objeto/PelotaJuego.h"
#include "src/objeto/Engranaje.h"
#include "src/objeto/Motor.h"
#include "src/objeto/Correa.h"
#include "src/objeto/Soga.h"
#include "src/objeto/Yunque.h"
#include "src/objeto/Clavo.h"
#include "src/objeto/Polea.h"
#include "src/objeto/ControlRemoto.h"
#include "src/objeto/Bomba.h"
#include "constructoresYAML.h"

ObjetoDAO::ObjetoDAO(){
	nodo = NULL;
}

ObjetoDAO::~ObjetoDAO() {
}

void ObjetoDAO::guardarFigura(Figura* objeto, YAML::Node *nodoRaiz) {
	nodo = nodoRaiz;
	objeto->acept(this);
}

void ObjetoDAO::guardarJugador(Jugador* objeto, YAML::Node *nodoRaiz) {
	(*nodoRaiz).push_back(*objeto);
}




void ObjetoDAO::visit(Motor* motor) {
	guardar(motor,nodo);
}

void ObjetoDAO::visit(Plataforma* plataforma){
	guardar(plataforma,nodo);
}

void ObjetoDAO::visit(Balancin* balancin){
	guardar(balancin,nodo);
}

void ObjetoDAO::visit(Tijera* tijera){
//	guardar(tijera,nodo);
}

void ObjetoDAO::visit(Carrito* carrito){
	guardar(carrito,nodo);
}

void ObjetoDAO::visit(Correa* correa){
	guardar(correa,nodo);
}

void ObjetoDAO::visit(Soga* soga){
	guardar(soga,nodo);
}

void ObjetoDAO::visit(Gancho* gancho) {
	guardar(gancho,nodo);
}


void ObjetoDAO::guardar(Plataforma* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Plataformas"].push_back(*objeto);
}

void ObjetoDAO::guardar(Balancin* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Balancines"].push_back(*objeto);
}

void ObjetoDAO::guardar(Tijera* objeto, YAML::Node* nodoRaiz) {
//	(*nodoRaiz)["Tijeras"].push_back(*objeto);
}

void ObjetoDAO::guardar(Carrito* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Carritos"].push_back(*objeto);
}

void ObjetoDAO::guardar(Correa* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Correas"].push_back(*objeto);
}

void ObjetoDAO::guardar(Soga* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Sogas"].push_back(*objeto);
}

void ObjetoDAO::guardar(Gancho* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Ganchos"].push_back(*objeto);
}

void ObjetoDAO::visit(CintaTransportadora* cinta) {
	guardar(cinta, nodo);
}

void ObjetoDAO::guardar(CintaTransportadora* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Cintas"].push_back(*objeto);
}

void ObjetoDAO::guardar(BolaBoliche* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["BolasBoliche"].push_back(*objeto);
}
void ObjetoDAO::visit(BolaBoliche* bolaBoliche) {
	guardar(bolaBoliche, nodo);
}

void ObjetoDAO::guardar(GloboHelio* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["GlobosHelio"].push_back(*objeto);
}
void ObjetoDAO::visit(GloboHelio* globoHelio) {
	guardar(globoHelio, nodo);
}

void ObjetoDAO::visit(PelotaJuego* pelotaJuego) {
	guardar(pelotaJuego, nodo);
}

void ObjetoDAO::guardar(PelotaJuego* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["PelotasJuego"].push_back(*objeto);
}

void ObjetoDAO::visit(Engranaje* engranaje) {
	guardar(engranaje, nodo);
}


void ObjetoDAO::guardar(Engranaje* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Engranajes"].push_back(*objeto);
}

void ObjetoDAO::guardar(Motor* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Motores"].push_back(*objeto);
}



void ObjetoDAO::visit(Yunque* objeto) {
	guardar(objeto, nodo);
}

void ObjetoDAO::guardar(Yunque* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Yunques"].push_back(*objeto);
}

void ObjetoDAO::visit(Clavo* c) {
	guardar(c,nodo);

}

void ObjetoDAO::guardar(Clavo* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Clavos"].push_back(*objeto);
}

void ObjetoDAO::visit(Polea*c) {
	guardar(c,nodo);
}

void ObjetoDAO::guardar(Polea* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Poleas"].push_back(*objeto);
}

void ObjetoDAO::visit(ControlRemoto*) {
}

void ObjetoDAO::visit(Bomba* c) {
	guardar(c,nodo);
}

void ObjetoDAO::guardar(Bomba* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Bombas"].push_back(*objeto);
}
