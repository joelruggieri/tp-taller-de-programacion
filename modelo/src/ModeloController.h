/*
 * ModeloController.h
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#ifndef EVENTOSMODELOCONTROLLER_H_
#define EVENTOSMODELOCONTROLLER_H_
#include "figura/Figura.h"
#include "figura/Mapa.h"
#include "Transformacion.h"
#include <list>
using namespace std;

class ModeloController {
private:
	Mapa * mapa;
	Transformacion *tl;
public:
	ModeloController();
	virtual ~ModeloController();
	//Instancia una figura en el modelo y retora true si la operacion fue correcta.
	bool crearFigura(Figura* figura);
	bool removerFigura(Figura* figura);
	list<Figura*>& getFiguras();
	Figura * pickUp(float, float);
	void start();
	void step();
	void stop();
	void setTransformacion(Transformacion *);
};

#endif /* EVENTOSMODELOCONTROLLER_H_ */
