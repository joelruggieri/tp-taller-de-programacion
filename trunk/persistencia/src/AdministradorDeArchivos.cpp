/*
 * AdministradorDeArchivos.cpp
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#include "AdministradorDeArchivos.h"
#include <iostream>
#include <fstream>

#include "constructoresYAML.h"

AdministradorDeArchivos::AdministradorDeArchivos(std::string nombre) {
	this->nombre = nombre;
	nodoRaiz = YAML::LoadFile(nombre);
}

AdministradorDeArchivos::~AdministradorDeArchivos() {
	// TODO Auto-generated destructor stub
}

bool AdministradorDeArchivos::guardar(Triangulo* objeto) {
	YAML::Node node = nodoRaiz["Triangulos"];
	node.push_back(*objeto);
	std::ofstream fout("config.yaml");
	fout << nodoRaiz;
	fout.close();
	return true;
}

bool AdministradorDeArchivos::guardar(Circulo* objeto) {
	YAML::Node node = nodoRaiz["Circulos"];
	node.push_back(*objeto);
	std::ofstream fout("config.yaml");
	fout << nodoRaiz;
	fout.close();
	return true;
}

bool AdministradorDeArchivos::guardar(Cuadrado* objeto) {
	YAML::Node node = nodoRaiz["Cuadrados"];
	node.push_back(*objeto);
	std::ofstream fout("config.yaml");
	fout << nodoRaiz;
	fout.close();
	return true;
}

std::list<Figura*> AdministradorDeArchivos::obtenerTodos() {
	std::list<Figura*> lista;
	YAML::Node objetos = YAML::LoadFile(nombre);

	YAML::Node circulos = objetos["Circulos"];
	for (std::size_t i = 0; i < circulos.size(); i++) {
		Circulo obj = circulos[i].as<Circulo>();
		lista.push_back(new Circulo(obj.getX(), obj.getY(),obj.getRadio()));
	}

	YAML::Node cuadrados = objetos["Cuadrados"];
	for (std::size_t i = 0; i < cuadrados.size(); i++) {
		Cuadrado obj = cuadrados[i].as<Cuadrado>();
		lista.push_back(new Cuadrado(obj.getX(), obj.getY(),obj.getAncho(),obj.getAlto()));
	}

	YAML::Node triangulos = objetos["Triangulos"];
	for (std::size_t i = 0; i < triangulos.size(); i++) {
		Triangulo obj = triangulos[i].as<Triangulo>();
		lista.push_back(new Triangulo(obj.getX(),obj.getY()));
	}

	return lista;
}
