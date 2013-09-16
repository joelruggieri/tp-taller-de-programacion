/*
 * ObjetoDAO.h
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#ifndef OBJETODAO_H_
#define OBJETODAO_H_

#include <list>
#include <string>
#include "src/figura/Circulo.h"
#include "src/figura/Triangulo.h"
#include "src/figura/Cuadrado.h"
#include "src/figura/Figura.h"
#include "AdministradorDeArchivos.h"

class ObjetoDAO {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	YAML::Node guardar(Circulo *objeto, YAML::Node nodoRaiz);
	YAML::Node guardar(Cuadrado *objeto, YAML::Node nodoRaiz);
	YAML::Node guardar(Triangulo *objeto, YAML::Node nodoRaiz);
	std::list<Figura*> obtenerTodos();
private:
	AdministradorDeArchivos administradorDeArchivos;
};

#endif /* OBJETODAO_H_ */
