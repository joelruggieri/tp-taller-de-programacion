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
#include "src/Jugador.h"
#include "src/FactoryParam.h"
#include "src/Area.h"
namespace YAML {

template<>
struct convert<Nivel> {
	static Node encode(const Nivel& objeto) {
		Node node;
		node["Nombre"] = objeto.getNombre();
		node["Fondo"] = objeto.getFondo();
		node["NumeroMaximoDeJugadores"] = objeto.getNumeroMaximoJugadores();
		return node;
	}

	static bool decode(const Node& node, Nivel& objeto) {
		if (node.size() != 3) return false;
		objeto.setNombre(node["Nombre"].as<std::string>());
		objeto.setFondo(node["Fondo"].as<std::string>());
		objeto.setNumeroMaximoJugadores(node["NumeroMaximoDeJugadores"].as<int>());
		return true;
	}
};


template<>
struct convert<FactoryParam> {
	static Node encode(const FactoryParam& objeto) {
		Node node;
		node["nombre"] = objeto.getNombre();
		node["cantidad"] = objeto.getCantidad();
		return node;
	}

	static bool decode(const Node& node, FactoryParam& objeto) {
		if (node.size() != 2) return false;
		objeto.setNombre(node["nombre"].as<std::string>());
		objeto.setCantidad(node["cantidad"].as<int>());
		return true;
	}
};

template<>
struct convert<Area> {
	static Node encode(const Area& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["ancho"] = objeto.getAncho();
		node["alto"] = objeto.getAlto();
		return node;
	}

	static bool decode(const Node& node, Area& objeto) {
		if (node.size() != 4) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setAncho(node["ancho"].as<float>());
		objeto.setAlto(node["alto"].as<float>());
		return true;
	}
};


template<>
struct convert<Jugador> {
	static Node encode(const Jugador& objeto) {
		Node node;
		node["numero"] = objeto.getNumero();
		node["Area"] = *(objeto.getArea());
		std::list<FactoryParam*> lista = objeto.getParametrosFactories();
		std::list<FactoryParam*>::iterator iterador;
		for(iterador = lista.begin(); iterador != lista.end(); ++iterador){
			node["ParametrosFactories"].push_back(**iterador);
		}
		return node;
	}

	static bool decode(const Node& node, Jugador& objeto) {
		if (node.size() != 3) return false;
		objeto.setNumero(node["numero"].as<int>());
		Area area = node["Area"].as<Area>();
		objeto.setArea(new Area(area));
		std::list<FactoryParam*> lista;
		YAML::Node nodoFactories = node["ParametrosFactories"];
		for (std::size_t i = 0; i < nodoFactories.size(); i++) {
			FactoryParam obj = nodoFactories[i].as<FactoryParam>();
			lista.push_back( new FactoryParam(obj));
		}
		objeto.setParametrosFactories(lista);
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
struct convert<Gancho> {
	static Node encode(const Gancho& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		return node;
	}

	static bool decode(const Node& node, Gancho& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Gancho");
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
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Balancin& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
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
		node["ancho"] = objeto.getAncho();
		return node;
	}

	static bool decode(const Node& node, CintaTransportadora& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setAncho(node["ancho"].as<float>());
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
		node["radio"] = objeto.getRadio();
		return node;
	}

	static bool decode(const Node& node, Engranaje& objeto) {
		if (node.size() != 3) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRadio(node["radio"].as<float>());
//		objeto
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

template<>
struct convert<Correa> {
	static Node encode(const Correa& objeto) {
		Node node;
		node["xDesde"] = objeto.getXInicial();
		node["yDesde"] = objeto.getYInicial();
		node["xHasta"] = objeto.getXFinal();
		node["yHasta"] = objeto.getYFinal();
		return node;
	}

	static bool decode(const Node& node, Correa& objeto) {
		if (node.size() != 4) return false;
		objeto.setXInicial(node["xDesde"].as<float>());
		objeto.setYInicial(node["yDesde"].as<float>());
		objeto.setXFinal(node["xHasta"].as<float>());
		objeto.setYFinal(node["yHasta"].as<float>());


		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Correa");
		return true;
	}
};


template<>
struct convert<Soga> {
	static Node encode(const Soga& objeto) {
		Node node;
		node["xDesde"] = objeto.getXInicial();
		node["yDesde"] = objeto.getYInicial();
		node["xHasta"] = objeto.getXFinal();
		node["yHasta"] = objeto.getYFinal();
		return node;
	}

	static bool decode(const Node& node, Soga& objeto) {
		if (node.size() != 4) return false;
		objeto.setXInicial(node["xDesde"].as<float>());
		objeto.setYInicial(node["yDesde"].as<float>());
		objeto.setXFinal(node["xHasta"].as<float>());
		objeto.setYFinal(node["yHasta"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Soga");
		return true;
	}
};

template<>
struct convert<Yunque> {
	static Node encode(const Yunque& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		return node;
	}

	static bool decode(const Node& node, Yunque& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Yunque");
		return true;
	}
};

template<>
struct convert<Clavo> {
	static Node encode(const Clavo& objeto) {
		Node node;
		node["x"] = objeto.getX();
		node["y"] = objeto.getY();
		node["rotacion"] = objeto.getRotacion();
		return node;
	}

	static bool decode(const Node& node, Clavo& objeto) {
		if (node.size() != 2) return false;
		objeto.setX(node["x"].as<float>());
		objeto.setY(node["y"].as<float>());
		objeto.setRotacion(node["rotacion"].as<float>());
		Mark marca = node.Mark();
		Registro & reg = objeto.getReg();
		reg.setLinea(marca.line);
		reg.setEtiqueta("Clavo");
		return true;
	}
};

}

#endif /* CONSTRUCTORESYAML_H_ */
