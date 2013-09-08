/*
 * Resizer.cpp
 *
 *  Created on: 08/09/2013
 *      Author: ezequiel
 */

#include "Resizer.h"

Resizer* Resizer::pinstance = 0;// Inicializar el puntero
Resizer* Resizer::Instance (int x, int y)
{
  if (pinstance == 0)  // ¿Es la primera llamada?
  {
    pinstance = new Resizer(x,y); // Creamos la instancia
  }
  return pinstance; // Retornamos la dirección de la instancia
}

int Resizer::resizearDistanciaX(int valor) {
	float valorFloat = (float) valor ;
	return (this->relacionX * valorFloat)  ;
}


void Resizer::setearResizer(int xNuevo, int yNuevo) {
	this->xViejo = this->xNuevo;
	this->yViejo = this->yNuevo;
	this->xNuevo = xNuevo;	this->relacionX = this->xNuevo / this->xViejo;	this->relacionX = this->xNuevo / this->xViejo;
	this->yNuevo = yNuevo;
	this->relacionX = (float)this->xNuevo / (float) this->xViejo ;
	this->relacionY = (float)this->yNuevo / (float) this->yViejo ;
}

int Resizer::resizearDistanciaY(int valor) {
	return (this->relacionY * valor);
}

Resizer::Resizer(int x, int y)
{
	this->xViejo = x;
	this->yViejo = y;
	this->xNuevo = x;
	this->yNuevo = y;
	this->relacionX = 1;
	this->relacionY = 1;

}
