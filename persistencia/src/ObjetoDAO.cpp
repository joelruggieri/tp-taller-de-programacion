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


YAML::Node ObjetoDAO::guardar(Circulo* objeto, YAML::Node nodoRaiz) {
	YAML::Node node = nodoRaiz["Circulos"];
	node.push_back(*objeto);
	return node;
}

YAML::Node ObjetoDAO::guardar(Cuadrado* objeto, YAML::Node nodoRaiz) {
	YAML::Node node = nodoRaiz["Cuadrados"];
	node.push_back(*objeto);
	return node;
}

YAML::Node ObjetoDAO::guardar(Triangulo* objeto, YAML::Node nodoRaiz) {
	YAML::Node node = nodoRaiz["Triangulos"];
	node.push_back(*objeto);
	return node;
}

