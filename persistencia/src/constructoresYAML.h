/*
 * constructoresYAML.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef CONSTRUCTORESYAML_H_
#define CONSTRUCTORESYAML_H_

#include "src/Nivel.h"

namespace YAML {

template<>
struct convert<Nivel> {
	static Node encode(const Nivel& objeto) {
		Node node;
		node["Numero"] = objeto.getNumero();
		return node;
	}

	static bool decode(const Node& node, Nivel& objeto) {
		objeto.setNumero(node["Numero"].as<int>());
		return true;
	}
};

template<>
struct convert<Circulo> {
	static Node encode(const Circulo& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		node["radio"] = objeto.getRadio();
		return node;
	}

	static bool decode(const Node& node, Circulo& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		objeto.setRadio(node["radio"].as<float>());
		return true;
	}
};

template<>
struct convert<Cuadrado> {
	static Node encode(const Cuadrado& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["ancho"] = objeto.getAncho();
		node["alto"]=objeto.getAlto();
		return node;
	}

	static bool decode(const Node& node, Cuadrado& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setAncho(node["ancho"].as<float>());
		objeto.setAlto(node["alto"].as<float>());
		return true;
	}
};

template<>
struct convert<Triangulo> {
	static Node encode(const Triangulo& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["ancho"]=objeto.getAncho();
		node["alto"]=objeto.getAlto();
		return node;
	}

	static bool decode(const Node& node, Triangulo& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setAncho(node["ancho"].as<float>());
		objeto.setAlto(node["alto"].as<float>());
		return true;
	}
};
}

#endif /* CONSTRUCTORESYAML_H_ */
