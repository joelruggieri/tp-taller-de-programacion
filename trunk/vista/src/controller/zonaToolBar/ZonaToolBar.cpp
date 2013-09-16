/*
 * zonaToolBar.cpp
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#include "ZonaToolBar.h"
#define ANCHOBOTON 40
#define ALTOBOTON 40
#define ANCHOTEXTBOX 300
#define ALTOTEXTBOX 45
ZonaToolBar::ZonaToolBar(int x, int y, int w, int h, SDL_Texture* texture) {


	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->fondo = texture ;
	this->agregarHerramientasAlToolBar(x,y,w,h);

}

void ZonaToolBar::seleccionarHerramienta(int x, int y) {

	list<Herramientas* >::iterator iter;
		 for(iter = this->herramientas.begin();iter != this->herramientas.end();iter++)
		{
			 if ((*iter)->fueSeleccionado(x, y)) return (*iter)->ejecutar();


		}

}

void ZonaToolBar::desSeleccionarHerramienta(int x, int y) {
	list<Herramientas* >::iterator iter;
		 for(iter = this->herramientas.begin();iter != this->herramientas.end();iter++)
		{
			  (*iter)->desEjecutar();

		}
		 return;
}

void ZonaToolBar::agregarHerramientasAlToolBar(int x, int y, int w, int h){
	CargadorDeTextures *p1 = CargadorDeTextures::Instance();
	//TODO ver que hacer con las coordenadas definidas
		BotonAgregar* bAgregar = new BotonAgregar(x+350, y+20, ANCHOBOTON, ALTOBOTON, p1->cargarTexture("resource/changeBackNormal.png"), p1->cargarTexture("resource/changeBackPressed.png"));
		BotonSalir* bSalir = new BotonSalir(x+400, y + 20, ANCHOBOTON, ALTOBOTON, p1->cargarTexture("resource/exitNormal.png"),p1->cargarTexture("resource/exitPressed.png") );
		BotonGuardar* bGuardar = new BotonGuardar(x+450, y+ 20, ANCHOBOTON, ALTOBOTON, p1->cargarTexture("resource/saveNormal.png"),p1->cargarTexture("resource/savePressed.png") );
		TextBox* textBox = new TextBox(x+10, y+20, ANCHOTEXTBOX, ALTOTEXTBOX, p1->cargarTexture("resource/textbox.jpg")) ;
		this->agregarHerramienta(bAgregar);
		this->agregarHerramienta(bSalir);
		this->agregarHerramienta(bGuardar);
		this->agregarHerramienta(textBox);
}

ZonaToolBar::~ZonaToolBar() {
	// TODO Auto-generated destructor stub
}

void ZonaToolBar::agregarHerramienta(Herramientas* herramienta) {
	this->herramientas.push_back(herramienta);


}

void ZonaToolBar::dibujarse(SDL_Renderer* render) {
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

bool ZonaToolBar::zonaFueSeleccionada(int x, int y) {
	if (this->x <= x && this->x + this->w > x && this->y <= y && this->y + this->h > y )
				return true;
		else
			return false;
}
