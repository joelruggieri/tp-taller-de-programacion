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
enum ESTADOS { GANADO, PERDIDO , NOTERMINADO };
#include "src/threading/ObjetoCompartido.h"
class ObjetivoJuego : public ObserverModelo, private ObjetoCompartido{
public:
	ObjetivoJuego();
	virtual ~ObjetivoJuego();
	 virtual void setConfig(Objetivo &);
	virtual void crearFiguras(std::list<Figura*>&)=0;
	bool isCumplido();
	void cumplir();
protected:
	float xD,yD;
private:
	bool cumplido;
};

#endif /* OBJETIVOJUEGO_H_ */
