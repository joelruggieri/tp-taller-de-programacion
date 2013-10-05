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
class Circulo;
class Figura;
class Pelota;
class Globo;
class Rueda;
class Motor;
class Plataforma;
class Balancin;

#include "AdministradorDeArchivos.h"
#include "src/figura/VisitorFigura.h"

class ObjetoDAO: public VisitorFigura {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	void guardarFigura(Figura *objeto, YAML::Node *nodoRaiz);
	void visit(Circulo* c);
	void visit(Globo* globo);
	void visit(Pelota* pelota);
	void visit(Rueda* rueda);
	void visit (Motor * motor);
	void visit (Plataforma * plataforma);
	void visit (Balancin * balancin);
private:
	void guardar(Circulo *objeto, YAML::Node *nodoRaiz);
	void guardar(Globo *objeto, YAML::Node *nodoRaiz);
	void guardar(Pelota *objeto, YAML::Node *nodoRaiz);
	void guardar(Rueda *objeto, YAML::Node *nodoRaiz);
	void guardar(Plataforma *objeto, YAML::Node *nodoRaiz);
	void guardar(Balancin *objeto, YAML::Node *nodoRaiz);
	AdministradorDeArchivos administradorDeArchivos;
	YAML::Node *nodo;
};

#endif /* OBJETODAO_H_ */
