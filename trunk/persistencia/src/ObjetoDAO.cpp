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
struct convert<Objeto> {
	static Node encode(const Objeto& objeto) {
		Node node;
		node.push_back(objeto.getPosX());
		node.push_back(objeto.getPosY());
		return node;
	}

	static bool decode(const Node& node, Objeto& objeto) {
		if (!node.IsSequence() || node.size() != 2)
			return false;

		objeto.setPosX(node[0].as<float>());
		objeto.setPosY(node[1].as<float>());
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

bool ObjetoDAO::guardar(Objeto* objeto) {
	YAML::Node nodoObjetos = YAML::LoadFile("config.yaml");
	YAML::Node node = nodoObjetos["objetos"];
	node.push_back( *objeto );

	std::ofstream fout("config.yaml");
	fout << nodoObjetos;
	fout.close();
	return true;
}

std::list<Objeto*> ObjetoDAO::obtenerTodos() {
	std::list<Objeto*> lista;
	YAML::Node primes = YAML::LoadFile("config.yaml");
	primes = primes["objetos"];

	for (std::size_t i = 0; i < primes.size(); i++) {
		Objeto obj = primes[i].as<Objeto>();
		lista.push_back(new Objeto(obj.getPosX(), obj.getPosY()));
	}
	return lista;
}
