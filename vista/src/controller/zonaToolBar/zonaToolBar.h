/*
 * zonaToolBar.h
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#ifndef ZONATOOLBAR_H_
#define ZONATOOLBAR_H_
#include <list>
#include "../../vista/Herramientas.h"
#include "../../vista/BotonAgregar.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../../vista/Dibujable.h"
//#include "../../controller/Resizer.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/TextBox.h"



using namespace std;

class zonaToolBar  {
private:
	list<Herramientas* > herramientas ;

public:
	zonaToolBar(int x, int y, int w, int h, SDL_Texture* texture);
	virtual ~zonaToolBar();
	void agregarHerramienta(Herramientas* herramienta);
	void dibujarse(SDL_Renderer *render);
private:
	SDL_Texture* fondo ;
	int x,y,h,w;
	void agregarHerramientasAlToolBar(int x, int y, int w, int h);




};

#endif /* ZONATOOLBAR_H_ */
