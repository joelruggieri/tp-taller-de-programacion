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
class ModeloController {
private:
	Mapa * mapa;
public:
	ModeloController();
	virtual ~ModeloController();
	//Instancia una figura en el modelo y retora true si la operacion fue correcta.
	bool crearFigura(Figura* figura);
	bool removerFigura(Figura* figura);
};

#endif /* EVENTOSMODELOCONTROLLER_H_ */
