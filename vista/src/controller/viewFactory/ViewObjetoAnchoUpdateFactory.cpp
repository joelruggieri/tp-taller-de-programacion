/*
 * ViewObjetoAnchoUpdateFactory.cpp
 *
 *  Created on: 07/11/2013
 *      Author: ezequiel
 */

#include "ViewObjetoAnchoUpdateFactory.h"

namespace CLIENTE {

View* ViewObjetoAnchoUpdateFactory::crearEngranaje(
		ViewObjetoConAnchoUpdateMsj* o) {
	return new VistaEngranaje(o->getX(), o->getY(), o->getAncho(), o->getAncho(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_ENGRANAJE));
	 }

View* ViewObjetoAnchoUpdateFactory::crearPlataforma(
		ViewObjetoConAnchoUpdateMsj* o) {
	return new PlataformaView(o->getX(), o->getY(), o->getAncho(), ANCHO_PLATAFORMA,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_PLATAFORMA));
}

View* ViewObjetoAnchoUpdateFactory::crearCinta(ViewObjetoConAnchoUpdateMsj* o ) {
	return new CintaTransportadoraView(o->getX(), o->getY(), o->getAncho(), ANCHO_CINTA, ANCHO_CINTA,ANCHO_CINTA,CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CINTA));
}

ViewObjetoAnchoUpdateFactory::ViewObjetoAnchoUpdateFactory() {
	// TODO Auto-generated constructor stub

}

View* ViewObjetoAnchoUpdateFactory::crear(ViewObjetoConAnchoUpdateMsj* o ) {
	View* viewRetorn;
	switch (o->getSelector()) {
		case OBJ_CON_ANCHO_S_PLATAFORMA:
			viewRetorn = this->crearPlataforma(o);
			break;
		case OBJ_CON_ANCHO_S_ENGRANAJE:
			viewRetorn = this->crearEngranaje(o);
			break;
		case OBJ_CON_ANCHO_S_CINTA:
			viewRetorn  = this->crearCinta(o);
			break;
	}
return viewRetorn;
}

} /* namespace CLIENTE */
