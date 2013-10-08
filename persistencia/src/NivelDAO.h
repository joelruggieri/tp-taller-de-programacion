/*
 * NivelDAO.h
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#ifndef NIVELDAO_H_
#define NIVELDAO_H_

#include "src/Nivel.h"
#include "AdministradorDeArchivos.h"
#include "src/Logger.h"

class NivelDAO {
public:
	NivelDAO();
	virtual ~NivelDAO();
	Nivel* leerNivel(const std::string &numero);
	Nivel* leerNivel(const char* numero);
	void guardarNivel(Nivel *nivel);
	Nivel* cargarPrimerNivel();
private:
	AdministradorDeArchivos administrador;
	std::list<Figura*> leerFiguras(YAML::Node objetos);
	void obtenerPlataformas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerBalancines(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerCintas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerBolasDeBoliche(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerGlobosHelio(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerPelotasJuego(std::list<Figura*> &lista, YAML::Node objetos);
	void imprimirLinea(std:: string & msj, YAML::Mark marca);
	Logger logg;
};

#endif /* NIVELDAO_H_ */
