/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"
#include <yaml-cpp/yaml.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>



namespace YAML {
template<>
struct convert<Circulo> {
	static Node encode(const Circulo& objeto) {
		Node node;
		node.push_back(objeto.getX());
		node.push_back(objeto.getY());
		node.push_back(objeto.getRotacion());
		node.push_back(objeto.getRadio());
		return node;
	}

	static bool decode(const Node& node, Circulo& objeto) {
		if (!node.IsSequence() || node.size() != 2)
			return false;

		objeto.setX(node[0].as<float>());
		objeto.setY(node[1].as<float>());
		objeto.setRotacion(node[2].as<float>());
		objeto.setRadio(node[3].as<float>());
		return true;
	}
};

template<>
struct convert<Cuadrado> {
	static Node encode(const Cuadrado& objeto) {
		Node node;
		node.push_back(objeto.getX());
		node.push_back(objeto.getY());
		node.push_back(objeto.getRotacion());
		node.push_back(objeto.getAncho());
		node.push_back(objeto.getAlto());
		return node;
	}

	static bool decode(const Node& node, Cuadrado& objeto) {
		if (!node.IsSequence() || node.size() != 2)
			return false;

		objeto.setX(node[0].as<float>());
		objeto.setY(node[1].as<float>());
		objeto.setRotacion(node[2].as<float>());
		objeto.setAncho(node[3].as<float>());
		objeto.setAlto(node[4].as<float>());
		return true;
	}
};

template<>
struct convert<Triangulo> {
	static Node encode(const Triangulo& objeto) {
		Node node;
		node.push_back(objeto.getX());
		node.push_back(objeto.getY());
		node.push_back(objeto.getRotacion());
		return node;
	}

	static bool decode(const Node& node, Triangulo& objeto) {
		if (!node.IsSequence() || node.size() != 2)
			return false;

		objeto.setX(node[0].as<float>());
		objeto.setY(node[1].as<float>());
		objeto.setRotacion(node[2].as<float>());
		return true;
	}
};
}

ObjetoDAO::ObjetoDAO() {
	// TODO Auto-generated constructor stub

}

ObjetoDAO::~ObjetoDAO() {
	// TODO Auto-generated destructor stub
}

std::string convert(float f) {
	std::ostringstream ss;
	ss << f;
	return ss.str();
}

bool ObjetoDAO::guardarCirculo(Circulo* circulo){
	YAML::Node nodoObjetos = YAML::LoadFile("config.yaml");
	YAML::Node node = nodoObjetos["Circulos"];
	node.push_back(*circulo);
	std::ofstream fout("config.yaml");
	fout << nodoObjetos;
	fout.close();
	return true;
}

bool ObjetoDAO::guardarCuadrado(Cuadrado* cuadrado){
	YAML::Node nodoObjetos = YAML::LoadFile("config.yaml");
	YAML::Node node = nodoObjetos["Cuadrados"];
	node.push_back(*cuadrado);
	std::ofstream fout("config.yaml");
	fout << nodoObjetos;
	fout.close();
	return true;
}

bool ObjetoDAO::guardarTriangulo(Triangulo* triangulo){
	YAML::Node nodoObjetos = YAML::LoadFile("config.yaml");
	YAML::Node node = nodoObjetos["Triangulos"];
	node.push_back(*triangulo);
	std::ofstream fout("config.yaml");
	fout << nodoObjetos;
	fout.close();
	return true;
}


bool ObjetoDAO::guardar(Figura* objeto) {
	//YAML::Node nodoObjetos = YAML::LoadFile("config.yaml");
	//YAML::Node node = nodoObjetos["Figuras"];
	bool resultado;
	if (strcmp(typeid(*objeto).name(),"Circulo") == 0)
		resultado = this->guardarCirculo(static_cast<Circulo*>(objeto));
	else{
		if (strcmp(typeid(*objeto).name(),"Cuadrado") == 0)
			resultado = this->guardarCuadrado(static_cast<Cuadrado*>(objeto));

		else{
			resultado = this->guardarTriangulo(static_cast<Triangulo*>(objeto));
		}
	}
	/*node.push_back(*objeto);
	std::ofstream fout("config.yaml");
	fout << nodoObjetos;
	fout.close();*/
	return resultado;
}



std::list<Figura*> ObjetoDAO::obtenerTodos() {
	std::list<Figura*> lista;
	YAML::Node primes = YAML::LoadFile("config.yaml");

	primes = primes["Circulos"];
	for (std::size_t i = 0; i < primes.size(); i++) {
		Circulo obj = primes[i].as<Circulo>();
		lista.push_back(new Circulo(obj.getX(), obj.getY(),obj.getRadio()));
	}

	primes = primes["Cuadrados"];
	for (std::size_t i = 0; i < primes.size(); i++) {
		Cuadrado obj = primes[i].as<Cuadrado>();
		lista.push_back(new Cuadrado(obj.getX(), obj.getY(),obj.getAncho(),obj.getAlto()));
	}

	primes = primes["Triangulos"];
	for (std::size_t i = 0; i < primes.size(); i++) {
		Triangulo obj = primes[i].as<Triangulo>();
		lista.push_back(new Triangulo(obj.getX(),obj.getY()));
	}
	return lista;
}
