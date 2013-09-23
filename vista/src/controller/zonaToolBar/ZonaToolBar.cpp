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
//ZonaToolBar::ZonaToolBar(int x, int y, int w, int h, SDL_Texture* texture) {
//
//
//
//
//
//}

void ZonaToolBar::cliquearHerramienta(int x, int y) {

	list<Dibujable*>::iterator iter;
	Herramientas * herr;
	list<Dibujable*> dibujables = this->canvas->getDibujables();
	for (iter = dibujables.begin(); iter != dibujables.end();
			iter++) {
		herr = (Herramientas*) *iter;
		if ((herr)->fueSeleccionado(x, y))
			return (herr)->presionarMouse();

	}

}

void ZonaToolBar::desCliquearHerramienta(int x, int y) {
	list<Dibujable*>::iterator iter;
	Herramientas * herr;
	list<Dibujable*> dibujables = this->canvas->getDibujables();
	for (iter = dibujables.begin(); iter != dibujables.end();
			iter++) {
		herr = (Herramientas*) *iter;
		(herr)->desPresionarMouse();

	}
	return;
}

void ZonaToolBar::teclearHerramienta(char key) {
	list<Dibujable*>::iterator iter;
	Herramientas * herr;
	list<Dibujable*> dibujables = this->canvas->getDibujables();
	for (iter = dibujables.begin(); iter != dibujables.end();
			iter++) {
		herr = (Herramientas*) *iter;
		(herr)->ejecutarTecla(key);

	}
	return;
}

void ZonaToolBar::cliqueoEnOtroLado() {

	list<Dibujable*>::iterator iter;
	Herramientas * herr;
	list<Dibujable*> dibujables = this->canvas->getDibujables();
	for (iter = dibujables.begin(); iter != dibujables.end();
			iter++) {
		herr = (Herramientas*) *iter;
		(herr)->clickeoFueraDeHerramienta();

	}
	return;
}

void ZonaToolBar::resizear() {

	//Resizer::Instance()->adaptarPosicionPixel(this->getXCentro(),this->getYCentro(),xNuevo,yNuevo );
	this->setYc(Resizer::Instance()->resizearDistanciaY(this->getYCentro()));
	this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));

	this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
	this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
//	this->setH(Resizer::Instance()->resizearDistanciaX(this->getH()));
}

bool ZonaToolBar::algunaHerramientaSeleccionada(int x, int y) {
	bool result = false;
	list<Dibujable*>::iterator iter;
	Herramientas * herr;
	list<Dibujable*> dibujables = this->canvas->getDibujables();
	for (iter = dibujables.begin(); iter != dibujables.end();
			iter++) {
		herr = (Herramientas*) *iter;
		if ((herr)->fueSeleccionado(x, y))
			return true;

	}
	return result;
}

void ZonaToolBar::agregarHerramientasAlToolBar(int x, int y, int w, int h) {
	CargadorDeTextures *p1 = CargadorDeTextures::Instance();
	//TODO ver que hacer con las coordenadas definidas
	BotonAgregar* bAgregar = new BotonAgregar(x + ANCHOBOTON + 30, y,
			ANCHOBOTON, ALTOBOTON,
			p1->cargarTexture("resource/changeBackNormal.png"),
			p1->cargarTexture("resource/changeBackPressed.png"));
	BotonSalir* bSalir = new BotonSalir(x + 2 * ANCHOBOTON + 30, y, ANCHOBOTON,
			ALTOBOTON, p1->cargarTexture("resource/exitNormal.png"),
			p1->cargarTexture("resource/exitPressed.png"));
	BotonGuardar* bGuardar = new BotonGuardar(x + 3 * ANCHOBOTON + 30, y,
			ANCHOBOTON, ALTOBOTON, p1->cargarTexture("resource/saveNormal.png"),
			p1->cargarTexture("resource/savePressed.png"));
	TextBox* textBox = new TextBox(x - 130, y, ANCHOTEXTBOX, ALTOTEXTBOX,
			p1->cargarTexture("resource/textbox.jpg"));
	bAgregar->campo = textBox;
	this->agregarHerramienta(bAgregar);
	this->agregarHerramienta(bSalir);
	this->agregarHerramienta(bGuardar);
	this->agregarHerramienta(textBox);

}

ZonaToolBar::~ZonaToolBar() {
	delete view;
}

void ZonaToolBar::agregarHerramienta(Herramientas* herramienta) {
	this->canvas->agregar(herramienta);

}

void ZonaToolBar::dibujarse(SDL_Renderer* render) {
//	SDL_Rect dst;
//	dst.x = this->getX();
//	dst.y = this->getY();
//	dst.h = this->getH();
//	dst.w = this->getW();
//	this->dibujarse(render, dst);
	this->view->dibujarse(render);

}
//POS: true si alguna herramienta fue seleccionada
bool ZonaToolBar::zonaFueSeleccionada(int x, int y) {

	return (this->getX() <= x && getX() + this->getW() > x && this->getY() <= y
			&& this->getY() + this->getH() > y);
}

void ZonaToolBar::desTeclearHerramienta() {
	list<Dibujable*>::iterator iter;
	Herramientas * herr;
	list<Dibujable*> dibujables = this->canvas->getDibujables();
	for (iter = dibujables.begin(); iter != dibujables.end();
			iter++) {
		herr = (Herramientas*) *iter;
		(herr)->desEjecutarTecla();

	}
	return;
}

void ZonaToolBar::dibujarse(SDL_Renderer* render, SDL_Rect& dst) {
	SDL_RenderCopy(render, this->fondo, NULL, &dst);

	list<Dibujable*>::iterator iter;
	Herramientas * herr;
	list<Dibujable*> dibujables = this->canvas->getDibujables();
	for (iter = dibujables.begin(); iter != dibujables.end();
			iter++) {
		herr = (Herramientas*) *iter;
		(herr)->dibujarse(render);

	}
}
