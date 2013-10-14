/*
 * constructoresYAML.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef CONSTRUCTORESYAML_H_
#define CONSTRUCTORESYAML_H_

#include "src/Nivel.h"
#include "src/figura/Registro.h"
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
struct convert<BolaBoliche> {
	static Node encode(const BolaBoliche& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		return node;
	}

	static bool decode(const Node& node, BolaBoliche& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("BolaBoliche");
		return true;
	}
};

template<>
struct convert<GloboHelio> {
	static Node encode(const GloboHelio& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		return node;
	}

	static bool decode(const Node& node, GloboHelio& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("GloboHelio");
		return true;
	}
};

template<>
struct convert<PelotaJuego> {
	static Node encode(const PelotaJuego& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		return node;
	}

	static bool decode(const Node& node, PelotaJuego& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("PelotaJuego");
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
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Plataforma& objeto) {
		if (node.size() != 4) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setAncho(node["ancho"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Plataforma");
		return true;
	}
};

template<>
struct convert<Balancin> {
	static Node encode(const Balancin& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["ancho"] = objeto.getAncho();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Balancin& objeto) {
		if (node.size() != 4) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setAncho(node["ancho"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Balancin");
		return true;
	}
};

template<>
struct convert<CintaTransportadora> {
	static Node encode(const CintaTransportadora& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		return node;
	}

	static bool decode(const Node& node, CintaTransportadora& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("CintaTransportadora");
		return true;
	}
};
template<>
struct convert<Engranaje> {
	static Node encode(const Engranaje & objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		return node;
	}

	static bool decode(const Node& node, Engranaje& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());

		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Engranaje");
		return true;
	}
};
template<>
struct convert<Motor> {
	static Node encode(const Motor& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["direccion"] = objeto.getDireccion();
		return node;
	}

	static bool decode(const Node& node, Motor& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setDireccion(node["direccion"].as<int>());

		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Motor");
		return true;
	}
};

}

#endif /* CONSTRUCTORESYAML_H_ */
