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

class NivelDAO {
public:
	NivelDAO();
	virtual ~NivelDAO();
	Nivel* leerNivel(int numero);
	void guardarNivel(Nivel &nivel);
private:
	AdministradorDeArchivos administrador;
	std::list<Figura*> leerFiguras(YAML::Node objetos);
	void obtenerCirculos(std::list<Figura*> &lista , YAML::Node objetos);
	void obtenerCuadrados(std::list<Figura*> &lista, YAML::Node objetos);
	void obtenerTriangulos(std::list<Figura*> &lista, YAML::Node objetos);
};

#endif /* NIVELDAO_H_ */
