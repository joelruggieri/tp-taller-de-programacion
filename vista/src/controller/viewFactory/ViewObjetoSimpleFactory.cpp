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
	BalancinView* viewReturn = new BalancinView(o->getX(), o->getY(),ANCHO_BALANCIN, ALTO_BALANCIN,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_BALANCIN));
	return viewReturn;
}


View* ViewObjetoSimpleFactory::crearCarrito(ViewObjetoUpdateMsj* o) {
	CarritoView* viewReturn = new CarritoView(o->getX(), o->getY(),ANCHO_CARRITO, ALTO_CARRITO,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CARRITO));
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

View* ViewObjetoSimpleFactory::crearYunque(ViewObjetoUpdateMsj* o) {
	return new YunqueView(o->getX(), o->getY(),ANCHO_YUNQUE, ANCHO_YUNQUE,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_YUNQUE));
}

View* ViewObjetoSimpleFactory::crearGancho(ViewObjetoUpdateMsj* o) {
	return new GanchoView(o->getX(), o->getY(),2*RADIO_GANCHO,2*RADIO_GANCHO,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_GANCHO));
}

View* ViewObjetoSimpleFactory::crearPolea(ViewObjetoUpdateMsj* o) {
	return new PoleaView(o->getX(), o->getY(),2*RADIO_POLEA,2*RADIO_POLEA,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_POLEA));
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
	case OBJ_SIMPLE_S_YUNQUE:
		viewRetorn = this->crearYunque(a);
		break;
	case OBJ_SIMPLE_S_CLAVO:
		viewRetorn = this->crearClavo(a);
		break;
	case OBJ_SIMPLE_S_GANCHO:
		viewRetorn = this->crearGancho(a);
		break;
	case OBJ_SIMPLE_S_POLEA:
		viewRetorn = this->crearPolea(a);
		break;
	case OBJ_SIMPLE_S_CARRITO:
		viewRetorn = this->crearCarrito(a);
		break;
	case OBJ_SIMPLE_S_CONTROL:
		viewRetorn = this->crearControlRemoto(a);
		break;
	case OBJ_SIMPLE_S_BOMBA:
		viewRetorn = this->crearBomba(a);
		break;
	}

	return viewRetorn;

}


View* ViewObjetoSimpleFactory::crearClavo(ViewObjetoUpdateMsj* o) {
	ClavoView* viewReturn = new ClavoView(o->getX(), o->getY(),ANCHO_CLAVO, ALTO_CLAVO,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CLAVO));
	return viewReturn;
}

View* ViewObjetoSimpleFactory::crearControlRemoto(ViewObjetoUpdateMsj* o) {
	ControlRemotoView* viewReturn = new ControlRemotoView(o->getX(), o->getY(),ANCHO_CONTROL, ALTO_CONTROL,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CONTROL));
				return viewReturn;
}

View* ViewObjetoSimpleFactory::crearBomba(ViewObjetoUpdateMsj* o) {
	BombaView* viewReturn = new BombaView(o->getX(), o->getY(),2*RADIO_PELOTA, 2*RADIO_PELOTA,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_BOMBA));
			return viewReturn;
}
} /* namespace CLIENTE */



