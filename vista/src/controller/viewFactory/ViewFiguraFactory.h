/*
 * ViewFiguraFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWFIGURAFACTORY_H_
#define VIEWFIGURAFACTORY_H_
#include "../../vista/figura/FiguraView.h"
#include "../../vista/FactoryView.h"
#include <string>
#include "SDL2/SDL.h"
using namespace std;

namespace CLIENTE {
//ENTREGA3 CAMBIA LA IDEA DE ESTA FACTORIES, ESTAS FACTORIES AHORA SON PARA LO QUE VIENE DESDE EL SERVER PARA CREAR, NO PARA CREAR ACA EN CLIENTE.
//ASI QUE LE BORRO EL CREARVISTAPROPIA


class ViewFiguraFactory {
protected:
	SDL_Texture * textura;
public:
	ViewFiguraFactory(string path);
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(int,int)=0;
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
};
}
#endif /* VIEWFIGURAFACTORY_H_ */
