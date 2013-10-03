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
		node["Nombre"] = objeto.getNombre();
		node["Fondo"] = objeto.getFondo();
		return node;
	}

	static bool decode(const Node& node, Nivel& objeto) {
		if (node.size() != 2) return false;
		objeto.setNombre(node["Nombre"].as<std::string>());
		objeto.setFondo(node["Fondo"].as<std::string>());
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
		return node;
	}

	static bool decode(const Node& node, Circulo& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Rueda> {
	static Node encode(const Rueda& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Rueda& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Globo> {
	static Node encode(const Globo& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Globo& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Pelota> {
	static Node encode(const Pelota& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Pelota& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Plataforma> {
	static Node encode(const Plataforma& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["ancho"] = objeto.getAncho();
		node["alto"] = objeto.getAlto();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Plataforma& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setAncho(node["ancho"].as<float>());
		objeto.setAlto(node["alto"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Triangulo> {
	static Node encode(const Triangulo& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Triangulo& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};
}

#endif /* CONSTRUCTORESYAML_H_ */
