/*
 * AdministradorDeArchivos.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef ADMINISTRADORDEARCHIVOS_H_
#define ADMINISTRADORDEARCHIVOS_H_

#include <string>
#include <list>
#include <yaml-cpp/yaml.h>
#include "src/figura/Triangulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Circulo.h"

class AdministradorDeArchivos {
public:
	AdministradorDeArchivos(std::string nombre);
	virtual ~AdministradorDeArchivos();
	bool guardar(Triangulo* objeto);
	bool guardar(Circulo* objeto);
	bool guardar(Cuadrado* objeto);
	std::list<Figura*> obtenerTodos();
private:
	std::string nombre;
	YAML::Node nodoRaiz;
};

#endif /* ADMINISTRADORDEARCHIVOS_H_ */
