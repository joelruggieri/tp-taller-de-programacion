/*
 * zonaToolBar.h
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */
//TODO ENCARGARME DE HACER UN DESELECCIONAR PARA DISTINTOS EVENTOS
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

class ZonaToolBar  {
private:
	list<Herramientas* > herramientas ;

public:
	ZonaToolBar(int x, int y, int w, int h, SDL_Texture* texture);
	virtual ~ZonaToolBar();
	void agregarHerramienta(Herramientas* herramienta);
	void dibujarse(SDL_Renderer *render);
	void cliquearHerramienta(int x, int y);
	bool zonaFueSeleccionada(int x, int y);
	void desCliquearHerramienta(int x, int y);
	void teclearHerramienta(char key);
	void cliqueoEnOtroLado();	//feo
//	TextBox* getTextBox();
private:
	SDL_Texture* fondo ;
	int x,y,h,w;
	void agregarHerramientasAlToolBar(int x, int y, int w, int h);





};

#endif /* ZONATOOLBAR_H_ */