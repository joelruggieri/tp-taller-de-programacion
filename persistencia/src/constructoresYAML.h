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
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Cuadrado> {
	static Node encode(const Cuadrado& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Cuadrado& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Carrito> {
	static Node encode(const Carrito& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Carrito& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Resorte> {
	static Node encode(const Resorte& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Resorte& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Martillo> {
	static Node encode(const Martillo& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Martillo& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Bloque> {
	static Node encode(const Bloque& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Bloque& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};

template<>
struct convert<Cohete> {
	static Node encode(const Cohete& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Cohete& objeto) {
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
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
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		return true;
	}
};
}

#endif /* CONSTRUCTORESYAML_H_ */
