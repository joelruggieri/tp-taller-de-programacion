/*
 * ObjetivoAccionar.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVOACCIONAR_H_
#define OBJETIVOACCIONAR_H_
#include "ObjetivoJuego.h"
class ObjetivoAccionar : public ObjetivoJuego{
public:
	ObjetivoAccionar();
	virtual ~ObjetivoAccionar();
	  void setConfig(Objetivo &);
	 void crearFiguras(std::list<Figura*>&);
};

#endif /* OBJETIVOACCIONAR_H_ */
