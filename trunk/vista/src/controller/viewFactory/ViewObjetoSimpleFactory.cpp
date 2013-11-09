/*
 * ViewObjetoSimpleFactory.cpp
 *
 *  Created on: 7/11/2013
 *      Author: jonathan
 */

#include "ViewObjetoSimpleFactory.h"

namespace CLIENTE {

ViewObjetoSimpleFactory::ViewObjetoSimpleFactory() {
	// TODO Auto-generated constructor stub

}

View* ViewObjetoSimpleFactory::crearGlobo(ViewObjetoUpdateMsj* o) {
	GloboHelioView* viewReturn = new GloboHelioView(o->getX(), o->getY(),2*RADIO_GLOBO, 2*RADIO_GLOBO,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_GLOBO));
	return viewReturn;
}

View* ViewObjetoSimpleFactory::crearBola(ViewObjetoUpdateMsj* o) {
	BolaBolicheView* viewReturn = new BolaBolicheView(o->getX(), o->getY(),2*RADIO_BOLA, 2*RADIO_BOLA,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_BOLA));
		return viewReturn;
}

View* ViewObjetoSimpleFactory::crearPelota(ViewObjetoUpdateMsj* o) {
	PelotaJuegoView* viewReturn = new PelotaJuegoView(o->getX(), o->getY(),2*RADIO_PELOTA, 2*RADIO_PELOTA,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_PELOTA));
			return viewReturn;
}

View* ViewObjetoSimpleFactory::crearMotor(ViewObjetoUpdateMsj* o) {
	MotorView* viewReturn = new MotorView(o->getX(), o->getY(),2*RADIO_MOTOR, 2*RADIO_MOTOR,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_MOTOR));
	return viewReturn;
}

View* ViewObjetoSimpleFactory::crearBalancin(ViewObjetoUpdateMsj* o) {
	BalancinView* viewReturn = new BalancinView(o->getX(), o->getY(),ANCHO_BALANCIN, ALTO_BALANCIN,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_MOTOR));
	return viewReturn;
}

View* ViewObjetoSimpleFactory::crearSogaEstatica(ViewObjetoUpdateMsj* o) {
	return new SogaEstaticaView(o->getX(), o->getY(),ANCHO_UNION_ESTATICA, ALTO_UNION_ESTATICA, CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CUERDA));
}

View* ViewObjetoSimpleFactory::crearCorreaEstatica(ViewObjetoUpdateMsj* o) {
	return new CorreaEstaticaView(o->getX(), o->getY(),ANCHO_UNION_ESTATICA, ALTO_UNION_ESTATICA, CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CORREA));

}


ViewObjetoSimpleFactory::~ViewObjetoSimpleFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewObjetoSimpleFactory::crear(ViewObjetoUpdateMsj* a) {
	View* viewRetorn;
	switch(a->getSelector())
	{
	case OBJ_SIMPLE_S_PELOTAJUEGO:
		viewRetorn = this->crearPelota(a);
		break;
	case OBJ_SIMPLE_S_BALANCIN:
		viewRetorn = this->crearBalancin(a);
		break;
	case OBJ_SIMPLE_S_GLOBO:
		viewRetorn = this->crearGlobo(a);
		break;
	case OBJ_SIMPLE_S_BOLABOLICHE:
		viewRetorn = this->crearBola(a);
		break;
	case OBJ_SIMPLE_S_MOTOR:
		viewRetorn = this->crearMotor(a);
		break;
	case OBJ_UNION_S_SOGA_ESTATICA:
		viewRetorn = this->crearSogaEstatica(a);
		break;
	case OBJ_UNION_S_CORREA_ESTATICA:
		viewRetorn = this->crearCorreaEstatica(a);
		break;
	}

	return viewRetorn;

}




} /* namespace CLIENTE */


