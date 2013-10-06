/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"
#include <iostream>
#include <fstream>

#include "src/figura/Circulo.h"

#include "src/figura/Figura.h"
#include "src/figura/Pelota.h"
#include "src/figura/Rueda.h"
#include "src/objeto/Plataforma.h"
#include "src/objeto/Balancin.h"

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



void ObjetoDAO::visit(Circulo* c) {
	guardar(c, nodo);
}

void ObjetoDAO::visit(Pelota* pelota) {
	guardar(pelota, nodo);
}


void ObjetoDAO::visit(Rueda* rueda) {
	guardar(rueda, nodo);
}

void ObjetoDAO::visit(Motor* motor) {
}

void ObjetoDAO::visit(Plataforma* plataforma){
	guardar(plataforma,nodo);
}

void ObjetoDAO::visit(Balancin* balancin){
	guardar(balancin,nodo);
}

void ObjetoDAO::guardar(Circulo* objeto, YAML::Node *nodoRaiz) {
	(*nodoRaiz)["Circulos"].push_back(*objeto);
}

void ObjetoDAO::guardar(Pelota* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Pelotas"].push_back(*objeto);
}


void ObjetoDAO::guardar(Rueda* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Ruedas"].push_back(*objeto);
}

void ObjetoDAO::guardar(Plataforma* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Plataformas"].push_back(*objeto);
}

void ObjetoDAO::guardar(Balancin* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Balancines"].push_back(*objeto);
}

void ObjetoDAO::visit(BolaBoliche* bolaBoliche) {
}
