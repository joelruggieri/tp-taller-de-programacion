/*
 * NivelDAO.h
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#ifndef NIVELDAO_H_
#define NIVELDAO_H_

#include "src/Nivel.h"
#include "src/Logger.h"
#include "src/FactoryParam.h"

//ENTREGA3 HAY QUE PERSISTIR/LEVANTAR LAS COSAS NUEVAS DEL NIVEL
class NivelDAO {
public:
	NivelDAO();
	virtual ~NivelDAO();
	Nivel* leerNivel(const std::string &numero);
	Nivel* leerNivel(const char* numero);
	void guardarNivel(Nivel *nivel);
	Nivel* cargarPrimerNivel();
private:
	std::list<Figura*> leerFiguras(YAML::Node objetos);
	std::list<Jugador*> leerJugadores(YAML::Node jugadores);
	//Area* leerArea (YAML::Node nodoJugador);
	//std::list<FactoryParam*> leerParametrosDeFactories(YAML::Node nodoJugador);
	YAML::Node getNodoObjetos(YAML::Node nodoRaiz);
	YAML::Node getNodoJugadores(YAML::Node nodoRaiz);
	void obtenerPlataformas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerBalancines(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerCintas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerBolasDeBoliche(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerGlobosHelio(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerGanchos(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerPelotasJuego(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerEngranajes(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerMotores(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerCorreas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerSogas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerYunques(std::list<Figura*> &lista, YAML::Node objetos);
	void imprimirLinea(std:: string & msj, YAML::Mark marca);
	Logger logg;
};

#endif /* NIVELDAO_H_ */
