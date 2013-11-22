/*
 * ObjetivoJuego.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVOJUEGO_H_
#define OBJETIVOJUEGO_H_
#include "src/Objetivos/Objetivo.h"
#include "src/figura/Figura.h"
class ObjetivoJuego {
public:
	ObjetivoJuego();
	virtual ~ObjetivoJuego();
	void setConfig(Objetivo &);
	void crearFiguras(std::list<Figura*>&);
};

#endif /* OBJETIVOJUEGO_H_ */
