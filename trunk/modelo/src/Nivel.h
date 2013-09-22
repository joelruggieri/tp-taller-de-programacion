/*
 * Nivel.h
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#ifndef NIVEL_H_
#define NIVEL_H_

#include <list>
#include "figura/Figura.h"
#include <string>

class Nivel {
public:
	Nivel(std::string nombre);
	virtual ~Nivel();
	void agregar(Figura* figura);
	int cantidadFiguras() const;
	std::list<Figura*>& getFiguras();
	const std::string& getNombre() const;
	void setNombre(const std::string& nombre);

private:
	std::list<Figura*> objetos;
	std::string nombre;
};

#endif /* NIVEL_H_ */
