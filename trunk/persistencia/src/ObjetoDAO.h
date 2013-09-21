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
#include "src/figura/Bloque.h"
#include "src/figura/Cohete.h"
#include "src/figura/Globo.h"
#include "src/figura/Martillo.h"
#include "src/figura/Pelota.h"
#include "src/figura/Resorte.h"
#include "src/figura/Rueda.h"
#include "AdministradorDeArchivos.h"

class ObjetoDAO: public VisitorFigura {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	void guardarFigura(Figura *objeto, YAML::Node *nodoRaiz);
	void visit(Cuadrado* c);
	void visit(Triangulo* t);
	void visit(Circulo* c);
	void visit(Rueda*);
	void visit(Globo*);
	void visit(Pelota*);
	void visit(Resorte*);
	void visit(Martillo*);
	void visit(Bloque*);
	void visit(Cohete*);
private:
	void guardar(Circulo *objeto, YAML::Node *nodoRaiz);
	void guardar(Cuadrado *objeto, YAML::Node *nodoRaiz);
	void guardar(Triangulo *objeto, YAML::Node *nodoRaiz);
	AdministradorDeArchivos administradorDeArchivos;
	YAML::Node *nodo;
};
#endif /* OBJETODAO_H_ */
