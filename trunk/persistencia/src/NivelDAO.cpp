/*
 * NivelDAO.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "NivelDAO.h"
#include "src/Logger.h"
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/exceptions.h>
#include "src/figura/Triangulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Circulo.h"
#include "constructoresYAML.h"
#include "ObjetoDAO.h"

NivelDAO::NivelDAO() {
	// TODO Auto-generated constructor stub

}

NivelDAO::~NivelDAO() {
	// TODO Auto-generated destructor stub
}

Nivel* NivelDAO::leerNivel(int numero) {
	Archivo *a = administrador.obtenerArchivoNivel(numero);
	if (!a) throw "Error: no existe el nivel";
	YAML::Node nodo = a->obtenerNodo("objetos");
	Nivel *n = new Nivel(numero);
	std::list<Figura*> figuras = leerFiguras(nodo);
	std::list<Figura*>::iterator it;
	for (it = figuras.begin(); it != figuras.end(); ++it){
		n->agregar(*it);
	}
	return n;
}

void NivelDAO::guardarNivel(Nivel &nivel) {
	Archivo *a = administrador.obtenerArchivoNivel(nivel.getNumero());
	YAML::Node nodo;
	nodo.push_back(nivel);
	YAML::Node nodoFiguras;
	std::list<Figura*>::iterator it;
	ObjetoDAO oDao;
//	for (it = nivel.getFiguras().begin(); it != nivel.getFiguras().end(); ++it) {
//		oDao.guardar(*it, nodoFiguras);
//	}
	a->sobreescribir(nodo);
}


std::list<Figura*> NivelDAO::leerFiguras(YAML::Node objetos){
	std::list<Figura*> lista;
	Logger logg;
		try{
		this->obtenerCirculos(lista,objetos);
		this->obtenerCuadrados(lista,objetos);
		this->obtenerTriangulos(lista,objetos);
		}catch(YAML::BadFile& exc){
			std::string mensaje = "No se pudo crear/abrir el archivo \n";
			mensaje.append(exc.what());
			logg.fatal(mensaje);
		}
	return lista;
}



void NivelDAO::obtenerCirculos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node circulos = objetos["Circulos"];
	Logger log;
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

void NivelDAO::obtenerCuadrados(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node cuadrados = objetos["Cuadrados"];
	Logger log;
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

void NivelDAO::obtenerTriangulos(std::list<Figura*> &lista, YAML::Node objetos){
	YAML::Node triangulos = objetos["Triangulos"];
	Logger log;
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
