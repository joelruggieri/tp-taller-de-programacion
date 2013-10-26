/*
 * Disponibilidad.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "Disponibilidad.h"

Disponibilidad::Disponibilidad() {
	// TODO Auto-generated constructor stub

}

Disponibilidad::~Disponibilidad() {
	// TODO Auto-generated destructor stub
}

void Disponibilidad::setDisponibilidad(int jug, int dispo) {
	std::map<int,int>::iterator elemento = relaciones.find(jug);

	if(elemento != relaciones.end()){
		(*elemento).second = dispo;
	} else {
		relaciones.insert(pair<int,int>(jug,dispo));
	}
}
