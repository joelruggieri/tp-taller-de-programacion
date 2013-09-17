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

class Nivel {
public:
	Nivel(int numero);
	virtual ~Nivel();
	void agregar(Figura* figura);
	int cantidadFiguras() const;
	std::list<Figura*>& getFiguras();
	int getNumero() const;
	void setNumero(int numero);
private:
	std::list<Figura*> objetos;
	int numero;
};

#endif /* NIVEL_H_ */
