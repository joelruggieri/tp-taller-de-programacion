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

/* Esta clase */

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
};

#endif /* NIVELDAO_H_ */
