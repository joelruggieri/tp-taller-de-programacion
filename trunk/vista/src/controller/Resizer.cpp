/*
 * Resizer.cpp
 *
 *  Created on: 08/09/2013
 *      Author: ezequiel
 */

#include "src/Logger.h"
#include "Resizer.h"
#include <iostream>
using namespace std;
#include <cmath>

Resizer* Resizer::pinstance = 0;// Inicializar el puntero
Resizer* Resizer::Instance (int x, int y, float xLogico, float yLogico )
{
  if (pinstance == 0)  // ¿Es la primera llamada?
  {
    pinstance = new Resizer(x,y, xLogico, yLogico); // Creamos la instancia
  }
  return pinstance; // Retornamos la dirección de la instancia
}

Resizer* Resizer::Instance ()
{
	Logger log;
	std::string mensaje_error = "Resizer no se encuentra correctamente inicializado";
	if(pinstance == 0){

		//TODO LANZAR EXCEPTION
		log.error(mensaje_error);
		//cout<< "ERROR"<<endl;
	}
  return pinstance; // Retornamos la dirección de la instancia
}



int Resizer::resizearDistanciaX(int valor) {
	float valorFloat = (float) valor ;
	return (this->relacionX * valorFloat)  ;
}

int Resizer::resizearDistanciaLogicaX(float valor)
{
		float valorFloat = (float)valor;
	return round(this->relacionXLogica * valorFloat);
}

int Resizer::resizearDistanciaLogicaY(float valor)
{
	float valorFloat = (float)valor;
	return round(this->relacionYLogica * valorFloat);
}

float Resizer::resizearDistanciaPixelX(int valor)
{
		float valorFloat = (float)valor;
	return (valorFloat / this->relacionXLogica);
}

float Resizer::resizearDistanciaPixelY(int valor)
{
	float valorFloat = (float)valor;
	return (valorFloat / this->relacionYLogica);
}


void Resizer::setearResizer(int xNuevo, int yNuevo) {
	this->xViejo = this->xNuevo;
	this->yViejo = this->yNuevo;
	this->xNuevo = xNuevo;	this->relacionX = this->xNuevo / this->xViejo;	this->relacionX = this->xNuevo / this->xViejo;
	this->yNuevo = yNuevo;
	this->relacionX = (float)this->xNuevo / (float) this->xViejo ;
	this->relacionY = (float)this->yNuevo / (float) this->yViejo ;
	this->relacionXLogica = (float)this->xNuevo / (float) this->xLogico;
	this->relacionYLogica = (float)this->yNuevo / (float) this->yLogico;

}



int Resizer::resizearDistanciaY(int valor) {
	return round(this->relacionY * valor);
}

Resizer::Resizer(int x, int y,float xLogico, float yLogico)
{
	this->xViejo = x;
	this->yViejo = y;
	this->xNuevo = x;
	this->yNuevo = y;
	this->relacionX = 1;
	this->relacionY = 1;
	this->xLogico = xLogico;
	this->yLogico = yLogico;
	this->relacionXLogica = (float)this->xNuevo / (float) this->xLogico;
	this->relacionYLogica = (float)this->yNuevo / (float) this->yLogico;


}

int Resizer::getAltoPantalla() {
	return this->yNuevo;
}
