/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"
#include <iostream>
#include <fstream>

#include "constructoresYAML.h"

ObjetoDAO::ObjetoDAO(){

}

ObjetoDAO::~ObjetoDAO() {
}


void ObjetoDAO::guardar(Circulo* objeto, YAML::Node *nodoRaiz) {
	(*nodoRaiz)["Circulos"].push_back(*objeto);
}

void ObjetoDAO::guardar(Cuadrado* objeto, YAML::Node *nodoRaiz) {
	(*nodoRaiz)["Cuadrados"].push_back(*objeto);
}

void ObjetoDAO::guardar(Triangulo* objeto, YAML::Node *nodoRaiz) {
	(*nodoRaiz)["Triangulos"].push_back(*objeto);
}

void ObjetoDAO::guardarFigura(Figura* objeto, YAML::Node *nodoRaiz) {
	nodo = nodoRaiz;
	objeto->acept(this);
}

void ObjetoDAO::visit(Cuadrado* c) {
	guardar(c, nodo);
}

void ObjetoDAO::visit(Triangulo* t) {
	guardar(t, nodo);
}

void ObjetoDAO::visit(Circulo* c) {
	guardar(c, nodo);
}
