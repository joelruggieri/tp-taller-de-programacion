/*
 * SimpleEditorCambiarRadio.cpp
 *
 *  Created on: 16/10/2013
 *      Author: ezequiel
 */

#include "SimpleEditorCambiarRadio.h"
#include "src/objeto/Estirable.h"
SimpleEditorCambiarRadio::SimpleEditorCambiarRadio(ModeloController * controller , ZonaTablero * zona,FiguraFactory* factory, int yMaxDrag): SimpleEditorEstirar(controller, zona, factory, yMaxDrag) {
	// TODO Auto-generated constructor stub

}

SimpleEditorCambiarRadio::~SimpleEditorCambiarRadio() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorCambiarRadio::mouseMotion(int x, int y) {
	super::mouseMotion(x,y);
//	this->finalizado = true;
//	return true;
}

void SimpleEditorCambiarRadio::rightClickDown(int x, int y) {
	super::rightClickDown(x,y);
//		const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
//	if (keyboardState[SDL_SCANCODE_LCTRL])
//	this->finalizado = true;



	this->actualizarRadio();
	cout << "actualizado" << endl;

}


void SimpleEditorCambiarRadio::actualizarRadio() {
	if(!finalizado){
	Estirable* figura = dynamic_cast<Estirable*>(this->editado->getModelo());//	Resizer*r = Resizer::Instance();
	figura->estirar(1); //siempre agranda
	this->editado->update();}
	//	Transformacion trans;
//	trans.traslacion(0, 100);
//	trans.escalar(r->getRelacionX(), r->getRelacionY());
//	trans.invertir(false, true);
//	this->editado->update(trans);	// La transformacion de donde la saco??
}
