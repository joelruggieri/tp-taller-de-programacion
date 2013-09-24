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
#include <yaml-cpp/exceptions.h>

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
	void obtenerCirculos(std::list<Figura*> &lista , YAML::Node objetos);
	void obtenerCuadrados(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerTriangulos(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerPelotas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerGlobos(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerResortes(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerMartillos(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerBloques(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerCohetes(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerRuedas(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerCarritos(std::list<Figura*> &lista, YAML::Node objetos);
	void imprimirLinea(YAML::Exception &exc);
	Logger logg;
};

#endif /* NIVELDAO_H_ */
