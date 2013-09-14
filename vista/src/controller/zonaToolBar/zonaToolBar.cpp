/*
 * zonaToolBar.cpp
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#include "zonaToolBar.h"
#define ANCHOBOTON 40
#define ALTOBOTON 40
#define ANCHOTEXTBOX 300
#define ALTOTEXTBOX 45
zonaToolBar::zonaToolBar(int x, int y, int w, int h, SDL_Texture* texture) {


	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->fondo = texture ;
	this->agregarHerramientasAlToolBar(x,y,w,h);

}

void zonaToolBar::agregarHerramientasAlToolBar(int x, int y, int w, int h){
	CargadorDeTextures *p1 = CargadorDeTextures::Instance();
	//TODO ver que hacer con las coordenadas definidas
		BotonAgregar* bAgregar = new BotonAgregar(x+350, y+20, ANCHOBOTON, ALTOBOTON, p1->cargarTexture("resource/botonAgregar.png"));
		BotonSalir* bSalir = new BotonSalir(x+400, y + 20, ANCHOBOTON, ALTOBOTON, p1->cargarTexture("resource/botonGuardar.png"));
		BotonGuardar* bGuardar = new BotonGuardar(x+450, y+ 20, ANCHOBOTON, ALTOBOTON, p1->cargarTexture("resource/pelota.PNG"));
		TextBox* textBox = new TextBox(x+10, y+20, ANCHOTEXTBOX, ALTOTEXTBOX, p1->cargarTexture("resource/textbox.jpg")) ;
		this->agregarHerramienta(bAgregar);
		this->agregarHerramienta(bSalir);
		this->agregarHerramienta(bGuardar);
		this->agregarHerramienta(textBox);
}

zonaToolBar::~zonaToolBar() {
	// TODO Auto-generated destructor stub
}

void zonaToolBar::agregarHerramienta(Herramientas* herramienta) {
	this->herramientas.push_back(herramienta);


}

void zonaToolBar::dibujarse(SDL_Renderer* render) {
	SDL_Rect dst;
	dst.x = this->x;
	dst.y = this->y;
	dst.h = this->h;
	dst.w= this->w;
	SDL_RenderCopy(render,this->fondo,NULL, &dst);

	list<Herramientas* >::iterator iter;
	 for(iter = this->herramientas.begin();iter != this->herramientas.end();iter++)
	{
		 	(*iter)->dibujarse(render);

	}

}
