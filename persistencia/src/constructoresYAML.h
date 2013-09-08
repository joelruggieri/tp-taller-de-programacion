/*
 * constructoresYAML.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef CONSTRUCTORESYAML_H_
#define CONSTRUCTORESYAML_H_



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
		if (!node.IsSequence() || node.size() != 4)
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
		if (!node.IsSequence() || node.size() != 5)
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
		if (!node.IsSequence() || node.size() != 3)
			return false;

		objeto.setX(node[0].as<float>());
		objeto.setY(node[1].as<float>());
		objeto.setRotacion(node[2].as<float>());
		return true;
	}
};
}

#endif /* CONSTRUCTORESYAML_H_ */
