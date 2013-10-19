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
#include "objeto/Union.h"
#include <list>
#include "Box2D/Box2D.h"
using namespace std;

class ModeloController {
private:
	Mapa * mapa;
	Transformacion *tl;
	list<Figura*> figuras;
public:
	ModeloController();
	virtual ~ModeloController();
	//Instancia una figura en el modelo y retora true si la operacion fue correcta.
	bool crearFigura(Figura* figura);
	bool crearUnion(Union* figura);
	bool removerFigura(Figura* figura);
	list<Figura*>& getFiguras();
	Figura * pickUp(float, float, uint16 mascara);
	void start();
	void step();
	void stop();
	void setTransformacion(Transformacion *);
};

#endif /* EVENTOSMODELOCONTROLLER_H_ */
