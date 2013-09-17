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

class ObjetoDAO: public VisitorFigura {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	void guardarFigura(Figura *objeto, YAML::Node *nodoRaiz);
	void visit(Cuadrado* c);
	void visit(Triangulo* t);
	void visit(Circulo* c);
private:
	void guardar(Circulo *objeto, YAML::Node *nodoRaiz);
	void guardar(Cuadrado *objeto, YAML::Node *nodoRaiz);
	void guardar(Triangulo *objeto, YAML::Node *nodoRaiz);
	AdministradorDeArchivos administradorDeArchivos;
	YAML::Node *nodo;
};

#endif /* OBJETODAO_H_ */
