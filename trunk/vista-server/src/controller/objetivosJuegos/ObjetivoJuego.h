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
#include "src/observer/ObserverModelo.h"
class ObjetivoJuego : public ObserverModelo{
public:
	ObjetivoJuego();
	virtual ~ObjetivoJuego();
	 virtual void setConfig(Objetivo &);
	virtual void crearFiguras(std::list<Figura*>&);
protected:
	float xD,yD;
	int estado;
};

#endif /* OBJETIVOJUEGO_H_ */
