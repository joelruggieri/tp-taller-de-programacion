/*
 * Herramientas.h
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_
#include "Dibujable.h"
class Herramientas : public Dibujable {
public:
	virtual void dibujarse(SDL_Renderer *) = 0;
};

#endif /* HERRAMIENTAS_H_ */
