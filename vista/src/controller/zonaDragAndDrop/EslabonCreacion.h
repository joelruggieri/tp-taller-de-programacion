/*
 * EslabonCreacion.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef ESLABONCREACION_H_
#define ESLABONCREACION_H_

#include "../../vista/figura/FiguraView.h"
#include "../../vista/FactoryView.h"
#include "../../modelo/Cuadrado.h"
#include <string>
using namespace std;
namespace CLIENTE {
class EslabonCreacion {
private:
	EslabonCreacion * siguiente;
	string tag;
	Cuadrado * cuerpo;
public:
	EslabonCreacion(string tag, Cuadrado *cuerpo);
	virtual ~EslabonCreacion();
	void setSiguiente(EslabonCreacion * sig);
	string atender(float posX, float posY, float corrimientoScroll);
	string getTag();
	View * crearView(string textura);
	EslabonCreacion * getsiguiente();
};

}
#endif /* ESLABONCREACION_H_ */
