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
class Motor;
class Plataforma;
class Balancin;
class CintaTransportadora;
class BolaBoliche;
class PelotaJuego;
class GloboHelio;

#include "AdministradorDeArchivos.h"
#include "src/figura/VisitorFigura.h"

class ObjetoDAO: public VisitorFigura {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	void guardarFigura(Figura *objeto, YAML::Node *nodoRaiz);
	void visit (Motor * motor);
	void visit (Plataforma * plataforma);
	void visit (Balancin * balancin);
	void visit(CintaTransportadora*);
	void visit (BolaBoliche* bolaBoliche);
	void visit (PelotaJuego* PelotaJuego);
	void visit (GloboHelio* globoHelio);
private:
	void guardar(Circulo *objeto, YAML::Node *nodoRaiz);
	void guardar(Plataforma *objeto, YAML::Node *nodoRaiz);
	void guardar(Balancin *objeto, YAML::Node *nodoRaiz);
	void guardar(CintaTransportadora *objeto, YAML::Node *nodoRaiz);
	void guardar(BolaBoliche *objeto, YAML::Node *nodoRaiz);
	void guardar(GloboHelio *objeto, YAML::Node *nodoRaiz);
	void guardar(PelotaJuego* objeto, YAML::Node* nodoRaiz);
	AdministradorDeArchivos administradorDeArchivos;
	YAML::Node *nodo;
};

#endif /* OBJETODAO_H_ */
