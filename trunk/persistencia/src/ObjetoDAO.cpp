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
#include "src/figura/Triangulo.h"
#include "src/figura/Figura.h"
#include "src/figura/Pelota.h"
#include "src/figura/Globo.h"
#include "src/figura/Rueda.h"


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




void ObjetoDAO::visit(Triangulo* t) {
	guardar(t, nodo);
}

void ObjetoDAO::visit(Circulo* c) {
	guardar(c, nodo);
}

void ObjetoDAO::visit(Globo* globo) {
	guardar(globo, nodo);
}

void ObjetoDAO::visit(Pelota* pelota) {
	guardar(pelota, nodo);
}


void ObjetoDAO::visit(Rueda* rueda) {
	guardar(rueda, nodo);
}


void ObjetoDAO::guardar(Circulo* objeto, YAML::Node *nodoRaiz) {
	(*nodoRaiz)["Circulos"].push_back(*objeto);
}

void ObjetoDAO::guardar(Triangulo* objeto, YAML::Node *nodoRaiz) {
	(*nodoRaiz)["Triangulos"].push_back(*objeto);
}

void ObjetoDAO::guardar(Globo* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Globos"].push_back(*objeto);
}

void ObjetoDAO::guardar(Pelota* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Pelotas"].push_back(*objeto);
}


void ObjetoDAO::guardar(Rueda* objeto, YAML::Node* nodoRaiz) {
	(*nodoRaiz)["Ruedas"].push_back(*objeto);
}

void ObjetoDAO::visit(Motor* motor) {
}
