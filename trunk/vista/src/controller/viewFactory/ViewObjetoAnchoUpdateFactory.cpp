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
	return new VistaEngranaje(o->getX(), o->getY(), o->getAncho(), o->getAncho(),o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_ENGRANAJE));
	 }

View* ViewObjetoAnchoUpdateFactory::crearPlataforma(
		ViewObjetoConAnchoUpdateMsj* o) {
	return new PlataformaView(o->getX(), o->getY(), o->getAncho(),ALTO_PLATAFORMA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_PLATAFORMA));
}

View* ViewObjetoAnchoUpdateFactory::crearCinta(ViewObjetoConAnchoUpdateMsj* o ) {
	View* v = new CintaTransportadoraView(o->getX(), o->getY(), o->getAncho(), ALTO_CINTA,o->getIdEvento(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CINTA_PLATAF));
	v->update(o);
	return v;
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
