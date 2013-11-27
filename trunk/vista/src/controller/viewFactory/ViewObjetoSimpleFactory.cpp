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
	GloboHelioView* viewReturn = new GloboHelioView(o->getX(), o->getY(),2*RADIO_GLOBO, 2*RADIO_GLOBO,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_GLOBO));
	return viewReturn;
}

View* ViewObjetoSimpleFactory::crearBola(ViewObjetoUpdateMsj* o) {
	BolaBolicheView* viewReturn = new BolaBolicheView(o->getX(), o->getY(),2*RADIO_BOLA, 2*RADIO_BOLA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_BOLA));
		return viewReturn;
}

View* ViewObjetoSimpleFactory::crearPelota(ViewObjetoUpdateMsj* o) {
	PelotaJuegoView* viewReturn = new PelotaJuegoView(o->getX(), o->getY(),2*RADIO_PELOTA, 2*RADIO_PELOTA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_PELOTA));
			return viewReturn;
}

View* ViewObjetoSimpleFactory::crearMotor(ViewObjetoUpdateMsj* o) {
	MotorView* viewReturn = new MotorView(o->getX(), o->getY(),2*RADIO_MOTOR, 2*RADIO_MOTOR,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_MOTOR));
	return viewReturn;
}

View* ViewObjetoSimpleFactory::crearBalancin(ViewObjetoUpdateMsj* o) {
	View* viewReturn = new BalancinView(o->getX(), o->getY(),ANCHO_BALANCIN, ALTO_BALANCIN,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_BALANCIN));
//	 viewReturn->update(o);
	 return viewReturn;
}


View* ViewObjetoSimpleFactory::crearCarrito(ViewObjetoUpdateMsj* o) {
	View* viewReturn = new CarritoView(o->getX(), o->getY(),ANCHO_CARRITO, ALTO_CARRITO,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CARRITO));
	viewReturn->update(o);
	return viewReturn;
}

View* ViewObjetoSimpleFactory::crearSogaEstatica(ViewObjetoUpdateMsj* o) {
	return new SogaEstaticaView(o->getX(), o->getY(),ANCHO_UNION_ESTATICA, ALTO_UNION_ESTATICA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CUERDA));
}

View* ViewObjetoSimpleFactory::crearCorreaEstatica(ViewObjetoUpdateMsj* o) {
	return new CorreaEstaticaView(o->getX(), o->getY(),ANCHO_UNION_ESTATICA, ALTO_UNION_ESTATICA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CORREA));

}


ViewObjetoSimpleFactory::~ViewObjetoSimpleFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewObjetoSimpleFactory::crearYunque(ViewObjetoUpdateMsj* o) {
	return new YunqueView(o->getX(), o->getY(),ANCHO_YUNQUE, ALTO_YUNQUE,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_YUNQUE));
}

View* ViewObjetoSimpleFactory::crearGancho(ViewObjetoUpdateMsj* o) {
	View* v =  new GanchoView(o->getX(), o->getY(),2*RADIO_GANCHO,2*RADIO_GANCHO,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_GANCHO));
	v->update(o);
	return v;
}

View* ViewObjetoSimpleFactory::crearPolea(ViewObjetoUpdateMsj* o) {
	View* v =  new PoleaView(o->getX(), o->getY(),2*RADIO_POLEA,2*RADIO_POLEA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_POLEA));
	v->update(o);
	return v;
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
	View* v = new ClavoView(o->getX(), o->getY(),ANCHO_CLAVO, ALTO_CLAVO,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CLAVO));
	v->update(o);
	return v;
}

View* ViewObjetoSimpleFactory::crearControlRemoto(ViewObjetoUpdateMsj* o) {
	View* viewReturn = new ControlRemotoView(o->getX(), o->getY(),ANCHO_CONTROL, ALTO_CONTROL,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CONTROL));
				return viewReturn;
}

View* ViewObjetoSimpleFactory::crearBomba(ViewObjetoUpdateMsj* o) {
	View* v = new BombaView(o->getX(), o->getY(),2*RADIO_PELOTA, 2*RADIO_PELOTA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_BOMBA));
			v->update(o);
			return v;
}
} /* namespace CLIENTE */



