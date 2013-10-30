/*
 * SimpleEditorAnguloFijo.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */
#include <cmath>
#include "SimpleEditorAnguloFijo.h"
#include "src/Logger.h"
#include "../../vista/objeto/BalancinView.h"
SimpleEditorAnguloFijo::SimpleEditorAnguloFijo(ModeloController * c, ZonaTablero *t, FiguraFactory* f, float yMaxDrag,
		list<float>& angulos) :
		SimpleEditorNivel(c, t, f, yMaxDrag) {
	angulosPermitidos = angulos;
}

SimpleEditorAnguloFijo::~SimpleEditorAnguloFijo() {
	// TODO Auto-generated destructor stub
}


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
	else if (this->rot->getDireccion() > 0 && indice < (angulosPermitidos.size() - 1))
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

void SimpleEditorAnguloFijo::mouseMotion(float x, float y) {
	if (dragueando)
		super::mouseMotion(x, y);
	if (rotando) {
		if (!angulosPermitidos.empty()) {
			this->rot->rotar(x, y);
			if (abs(rot->getAngulo() - start) > 1.7) {
				Logger log;
				log.debug("Supera humbral de rotacion, se cambia de angulo");
				float angulo = anguloPermitidoMasCercano(this->editado->getModelo()->getRotacion());
				this->editado->getModelo()->setRotacion(angulo);
//				start = rot->getAngulo();
				this->rightClickUp(x, y);
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
		for (it = angulosPermitidos.begin(); it != angulosPermitidos.end(); ++it) {
			if (*it == f->getModelo()->getRotacion()) {
				indice = i;
				break;
			}
			i++;
		}
	}
}

void SimpleEditorAnguloFijo::dropNuevaFigura(BalancinView* view) {
	dropear(view, this->figurasFactory->crearBalancin(view->getXCentro(), view->getYCentro()));
}

void SimpleEditorAnguloFijo::dropNuevaFigura(BolaBolicheView* view) {

	dropear(view, this->figurasFactory->crearBolaBoliche(view->getXCentro(), view->getYCentro()));
}

void SimpleEditorAnguloFijo::dropNuevaFigura(GloboHelioView* view) {

	dropear(view, this->figurasFactory->crearGloboHelio(view->getXCentro(), view->getYCentro()));
}
void SimpleEditorAnguloFijo::dropNuevaFigura(PelotaJuegoView* view) {

	dropear(view, this->figurasFactory->crearPelotaJuego(view->getXCentro(), view->getYCentro()));
}
void SimpleEditorAnguloFijo::dropNuevaFigura(VistaEngranaje* view) {

	dropear(view, this->figurasFactory->crearEngranaje(view->getXCentro(), view->getYCentro()));
}
