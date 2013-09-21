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
#include "src/figura/Cuadrado.h"
#include "src/figura/Figura.h"
#include "src/figura/Pelota.h"
#include "src/figura/Globo.h"
#include "src/figura/Resorte.h"
#include "src/figura/Martillo.h"
#include "src/figura/Bloque.h"
#include "src/figura/Cohete.h"
#include "src/figura/Rueda.h"
#include "src/figura/Carrito.h"


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

void ObjetoDAO::visit(Globo* globo) {
}

void ObjetoDAO::visit(Pelota* pelota) {
}

void ObjetoDAO::visit(Resorte* resorte) {
}

void ObjetoDAO::visit(Martillo* martillo) {
}

void ObjetoDAO::visit(Bloque* bloque) {
}

void ObjetoDAO::visit(Cohete* cohete) {
}

void ObjetoDAO::visit(Rueda* rueda) {
}

void ObjetoDAO::visit(Carrito* carrito) {
}
