/*
 * AdministradorDeArchivos.cpp
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#include "AdministradorDeArchivos.h"
#include <iostream>
#include <fstream>
#include <yaml-cpp/exceptions.h>
#include "AdministradorDeLoggers.h"
#include "constructoresYAML.h"

AdministradorDeArchivos::AdministradorDeArchivos(std::string nombre) {
	this->nombre = nombre;
	std::fstream fs;
	const char * nom = nombre.c_str();
	fs.open(nom, std::fstream::out);
	if(!fs.bad())
		fs.close();
	Logger &log = AdministradorDeLoggers::getLogger(FATAL);
	try{
		nodoRaiz = YAML::LoadFile(nombre);
	}catch(YAML::BadFile& exc){
		std::string mensaje = "No se pudo crear/abrir el archivo";
		mensaje.append(exc.what());
		log.fatal(mensaje);
	}


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

void AdministradorDeArchivos::obtenerCirculos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node circulos = objetos["Circulos"];
	Logger &log = AdministradorDeLoggers::getLogger(ERROR);
	for (std::size_t i = 0; i < circulos.size(); i++) {
		try {
			Circulo obj = circulos[i].as<Circulo>();
			lista.push_back(new Circulo(obj.getX(), obj.getY(), obj.getRadio()));
		} catch (YAML::InvalidNode &exc) {
			std::string mensaje = "Error al leer circulo ";
			mensaje.append(exc.what());
			log.error(mensaje);
		}
	}
}

void AdministradorDeArchivos::obtenerCuadrados(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node cuadrados = objetos["Cuadrados"];
	Logger &log = AdministradorDeLoggers::getLogger(ERROR);
	for (std::size_t i = 0; i < cuadrados.size(); i++) {
		try {
			Cuadrado obj = cuadrados[i].as<Cuadrado>();
			lista.push_back( new Cuadrado(obj.getX(), obj.getY(), obj.getAncho(), obj.getAlto()));
		} catch (YAML::InvalidNode &exc) {
			std::string mensaje = "Error al leer cuadrado ";
			mensaje.append(exc.what());
			log.error(mensaje);
		}
	}
}

void AdministradorDeArchivos::obtenerTriangulos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node triangulos = objetos["Triangulos"];
	Logger &log = AdministradorDeLoggers::getLogger(ERROR);
	for (std::size_t i = 0; i < triangulos.size(); i++) {
		try {
			Triangulo obj = triangulos[i].as<Triangulo>();
			lista.push_back( new Triangulo(obj.getX(), obj.getY(), obj.getAncho(), obj.getAlto()));
		} catch (YAML::InvalidNode &exc) {
			std::string mensaje = "Error al leer Triangulo ";
			mensaje.append(exc.what());
			log.error(mensaje);
		}
	}
}

std::list<Figura*> AdministradorDeArchivos::obtenerTodos() {
	std::list<Figura*> lista;
	YAML::Node objetos = YAML::LoadFile(nombre);
	Logger &logg = AdministradorDeLoggers::getLogger(FATAL);
		try{
			nodoRaiz = YAML::LoadFile(nombre);
		}catch(YAML::BadFile& exc){
			std::string mensaje = "No se pudo crear/abrir el archivo";
			mensaje.append(exc.what());
			logg.fatal(mensaje);
		}
		this->obtenerCirculos(lista,objetos);
		this->obtenerCuadrados(lista,objetos);
		this->obtenerTriangulos(lista,objetos);
	/*YAML::Node circulos = objetos["Circulos"];
	Logger &log = AdministradorDeLoggers::getLogger(ERROR);
	for (std::size_t i = 0; i < circulos.size(); i++) {
		try {
			Circulo obj = circulos[i].as<Circulo>();
			lista.push_back(new Circulo(obj.getX(), obj.getY(), obj.getRadio()));
		} catch (YAML::InvalidNode &exc) {
			std::string mensaje = "Error al leer circulo ";
			mensaje.append(exc.what());
			log.error(mensaje);
		}
	}*/

	/*YAML::Node cuadrados = objetos["Cuadrados"];
	for (std::size_t i = 0; i < cuadrados.size(); i++) {
		try {
			Cuadrado obj = cuadrados[i].as<Cuadrado>();
			lista.push_back( new Cuadrado(obj.getX(), obj.getY(), obj.getAncho(), obj.getAlto()));
		} catch (YAML::InvalidNode &exc) {
			std::string mensaje = "Error al leer cuadrado ";
			mensaje.append(exc.what());
			log.error(mensaje);
		}
	}*/

	/*YAML::Node triangulos = objetos["Triangulos"];
	for (std::size_t i = 0; i < triangulos.size(); i++) {
		try {
			Triangulo obj = triangulos[i].as<Triangulo>();
			lista.push_back( new Triangulo(obj.getX(), obj.getY(), obj.getAncho(), obj.getAlto()));
		} catch (YAML::InvalidNode &exc) {
			std::string mensaje = "Error al leer Triangulo ";
			mensaje.append(exc.what());
			log.error(mensaje);
		}
	}*/


	std::fstream fs;
	const char * nom = nombre.c_str();
	fs.open(nom, std::fstream::out);
	if(!fs.bad())
		fs.close();
	try{
		nodoRaiz = YAML::LoadFile(nombre);
	}catch(YAML::BadFile& exc){
		std::string mensaje = "No se pudo crear/abrir el archivo";
		mensaje.append(exc.what());
		logg.fatal(mensaje);
	}

	return lista;
}
