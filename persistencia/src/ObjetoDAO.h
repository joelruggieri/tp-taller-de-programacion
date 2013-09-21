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
class Triangulo;
class Cuadrado;
class Figura;
class Pelota;
class Globo;
class Resorte;
class Martillo;
class Bloque;
class Cohete;
class Rueda;

#include "AdministradorDeArchivos.h"
#include "src/figura/VisitorFigura.h"

class ObjetoDAO: public VisitorFigura {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	void guardarFigura(Figura *objeto, YAML::Node *nodoRaiz);
	void visit(Cuadrado* c);
	void visit(Triangulo* t);
	void visit(Circulo* c);
	void visit(Globo* globo);
	void visit(Pelota* pelota);
	void visit(Resorte* resorte);
	void visit(Martillo* martillo);
	void visit(Bloque* bloque);
	void visit(Cohete* cohete);
	void visit(Rueda* rueda);
private:
	void guardar(Circulo *objeto, YAML::Node *nodoRaiz);
	void guardar(Cuadrado *objeto, YAML::Node *nodoRaiz);
	void guardar(Triangulo *objeto, YAML::Node *nodoRaiz);
	AdministradorDeArchivos administradorDeArchivos;
	YAML::Node *nodo;
};

#endif /* OBJETODAO_H_ */
