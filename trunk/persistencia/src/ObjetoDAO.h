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
class Figura;
class Engranaje;
class Motor;
class Plataforma;
class Balancin;
class CintaTransportadora;
class BolaBoliche;
class PelotaJuego;
class GloboHelio;
class Correa;
class Soga;
class Yunque;
#include "src/Jugador.h"
#include "AdministradorDeArchivos.h"
#include "src/figura/VisitorFigura.h"

class ObjetoDAO: public VisitorFigura {
public:
	ObjetoDAO();
	virtual ~ObjetoDAO();
	void guardarJugador(Jugador* objeto, YAML::Node *nodoRaiz);
	void guardarFigura(Figura *objeto, YAML::Node *nodoRaiz);
	void visit (Motor * motor);
	void visit (Plataforma * plataforma);
	void visit (Balancin * balancin);
	void visit(CintaTransportadora*);
	void visit (BolaBoliche* bolaBoliche);
	void visit (PelotaJuego* PelotaJuego);
	void visit (GloboHelio* globoHelio);
	void visit (Engranaje* engranaje);
	void visit (Correa* correa);
	void visit (Soga* correa);
	void visit (Gancho*);
	void visit (Yunque*);
private:
	void guardar(Plataforma *objeto, YAML::Node *nodoRaiz);
	void guardar(Balancin *objeto, YAML::Node *nodoRaiz);
	void guardar(CintaTransportadora *objeto, YAML::Node *nodoRaiz);
	void guardar(BolaBoliche *objeto, YAML::Node *nodoRaiz);
	void guardar(GloboHelio *objeto, YAML::Node *nodoRaiz);
	void guardar(PelotaJuego* objeto, YAML::Node* nodoRaiz);
	void guardar(Engranaje* objeto, YAML::Node* nodoRaiz);
	void guardar(Motor* objeto, YAML::Node* nodoRaiz);
	void guardar(Correa* objeto, YAML::Node* nodoRaiz);
	void guardar(Soga* objeto, YAML::Node* nodoRaiz);
	void guardar(Yunque* objeto, YAML::Node* nodoRaiz);
	AdministradorDeArchivos administradorDeArchivos;
	YAML::Node *nodo;
};

#endif /* OBJETODAO_H_ */
