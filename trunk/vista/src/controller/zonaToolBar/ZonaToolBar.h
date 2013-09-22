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
#include "../../vista/View.h"
#include "../Resizer.h"



using namespace std;

class ZonaToolBar : public View   {
private:
	list<Herramientas* > herramientas ;

public:
	ZonaToolBar(int x, int y, int w, int h, SDL_Texture* texture): View(x,y,w,h)
{
		this->fondo = texture ;
		this->agregarHerramientasAlToolBar(x,y,w,h);
}
	virtual ~ZonaToolBar();
	void agregarHerramienta(Herramientas* herramienta);
	void dibujarse(SDL_Renderer *render);
	void dibujarse(SDL_Renderer *render, SDL_Rect &);
	void cliquearHerramienta(int x, int y);
	bool zonaFueSeleccionada(int x, int y);
	void desCliquearHerramienta(int x, int y);
	void teclearHerramienta(char key);
	void cliqueoEnOtroLado();	//feo
	void desTeclearHerramienta();
	void resizear();
	bool algunaHerramientaSeleccionada(int x, int y);
//	TextBox* getTextBox();
private:
	SDL_Texture* fondo ;
//	int x,y,h,w;
	void agregarHerramientasAlToolBar(int x, int y, int w, int h);





};

#endif /* ZONATOOLBAR_H_ */
