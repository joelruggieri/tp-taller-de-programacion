/*
 * SimpleEditorAnguloFijo.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */
#include <cmath>
#include "SimpleEditorAnguloFijo.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConIcono.h"
#include "src/Logger.h"
SimpleEditorAnguloFijo::SimpleEditorAnguloFijo(ModeloController * c,
		ZonaTablero *t, FiguraFactory* f, int yMaxDrag, list<float>& angulos) :
		SimpleEditorNivel(c, t, f, yMaxDrag) {
	angulosPermitidos = angulos;
}

SimpleEditorAnguloFijo::~SimpleEditorAnguloFijo() {
	// TODO Auto-generated destructor stub
}

/*void SimpleEditorAnguloFijo::rightClickUp(int x, int y) {
 if (rotando) {
 tablero->agregarFigura(this->editado);
 rotando = false;
 delete visor;
 finalizado = true;
 }
 }*/

//void SimpleEditorAnguloFijo::rightClickDown(int x, int y) {
/*const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
 if (keyboardState[SDL_SCANCODE_LSHIFT]){
 this->tablero->removerFigura(this->editado);
 this->modeloController->removerFigura(this->editado->getModelo());
 super::cleanAndDelete();
 return;

 }else*/
//super::rightClickDown(x,y);
/*if (!rotando && !finalizado && !dragueando) {
 if (editado->getModelo() != NULL){
 Resizer* r = Resizer::Instance();
 this->tablero->removerFigura(this->editado);
 this->rot = new Rotacion(this->editado->getXCentro(),
 r->getAltoPantalla() - this->editado->getYCentro(), x,
 r->getAltoPantalla() - y, 0);
 rotando = true;
 CargadorDeTextures* l = CargadorDeTextures::Instance();
 this->visor = new ViewConIcono(editado, l->cargarTexture("resource/rotacion.png"), 2);
 }
 }*/

//}
float SimpleEditorAnguloFijo::anguloPermitidoMasCercano(float angulo) {
	list<float>::iterator it;
//	for(it= angulosPermitidos.begin(); it != angulosPermitidos.end(); ++it){
//		if( *it == angulo){
//			cout << *it << endl;
//			encontrado = true;
//			break;
//		}
//	}

	if (this->rot->getDireccion() < 0 && indice > 0)
		indice--;
	else if (this->rot->getDireccion() > 0
			&& indice < (angulosPermitidos.size() - 1))
		indice++;
	it = angulosPermitidos.begin();
	advance(it, indice);
	float anguloPermitidoMasCercano = *it;
//	if (anguloPermitidoMasCercano > 10000) {
//		cout << "m2" << endl;
//	}
	return anguloPermitidoMasCercano;

	/*list<float>::iterator it;
	 float anguloPermitidoMasCercano = angulosPermitidos.front();
	 float diferencia = 0;
	 float menorDiferencia = abs(anguloPermitidoMasCercano - angulo);
	 float anguloActual = 0;
	 for(it = angulosPermitidos.begin() ; it != angulosPermitidos.end() ; ++it){
	 anguloActual = it.operator *();
	 diferencia = abs(angulo - anguloActual);
	 if(diferencia < menorDiferencia){
	 anguloPermitidoMasCercano = anguloActual;
	 menorDiferencia = diferencia;
	 }
	 }
	 std::cout << " h" << anguloPermitidoMasCercano << std::endl;
	 it = angulosPermitidos.begin();
	 while(it.operator *() != anguloPermitidoMasCercano)
	 ++it;

	 if(this->rot->getDireccion() < 0 && it != angulosPermitidos.begin())
	 it.operator --();
	 if(this->rot->getDireccion() > 0 && it != angulosPermitidos.end())
	 it.operator ++();

	 anguloPermitidoMasCercano = it.operator *();
	 return anguloPermitidoMasCercano;*/
}

void SimpleEditorAnguloFijo::mouseMotion(int x, int y) {
	if (dragueando)
		super::mouseMotion(x, y);
	if (rotando) {
		if (!angulosPermitidos.empty()) {
			Resizer* r = Resizer::Instance();
			this->rot->rotar(x, r->getAltoPantalla() - y);
			if (abs(rot->getAngulo() - start) > 1.7) {
				Logger log;
				log.debug("Supera humbral de rotacion, se cambia de angulo");
				float angulo = anguloPermitidoMasCercano(
						this->editado->getModelo()->getRotacion());
				this->editado->getModelo()->setRotacion(angulo);
//				start = rot->getAngulo();
				this->rightClickUp(x,y);
			}
		}

	}
}

void SimpleEditorAnguloFijo::setFigura(FiguraView*f) {
	super::setFigura(f);
	this->start = 0;
	int i = 0;
	list<float>::iterator it;
	if (f->getModelo() != NULL) {
		for (it = angulosPermitidos.begin(); it != angulosPermitidos.end();
				++it) {
			if (*it == f->getModelo()->getRotacion()) {
				indice = i;
				break;
			}
			i++;
		}
	}
}


void SimpleEditorAnguloFijo::dropNuevaFigura(BalancinView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearBalancin(x, 100 - y));
}


void SimpleEditorAnguloFijo::dropNuevaFigura(BolaBolicheView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearBolaBoliche(x, 100 - y));
}

void SimpleEditorAnguloFijo::dropNuevaFigura(GloboHelioView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearGloboHelio(x, 100 - y));
}
void SimpleEditorAnguloFijo::dropNuevaFigura(PelotaJuegoView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearPelotaJuego(x, 100 - y));
}
void SimpleEditorAnguloFijo::dropNuevaFigura(VistaEngranaje* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearEngranaje(x, 100 - y));
}
