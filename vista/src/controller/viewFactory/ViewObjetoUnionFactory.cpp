/*
 * ViewObjetoUnionFactory.cpp
 *
 *  Created on: 07/11/2013
 *      Author: ezequiel
 */

#include "ViewObjetoUnionFactory.h"

namespace CLIENTE {

ViewObjetoUnionFactory::ViewObjetoUnionFactory() {
	// TODO Auto-generated constructor stub

}

View* ViewObjetoUnionFactory::crear(ViewObjetoUnionUpdateMsj* o) {
View* viewResult;
	switch(o->getSelector())
	{
	case OBJ_UNION_S_CORREA:
		viewResult = this->crearCorrea(o);
		break;
	case OBJ_UNION_S_SOGA:
		viewResult = this->crearSoga(o);
		break;
	}
return viewResult;
}

View* ViewObjetoUnionFactory::crearSoga(ViewObjetoUnionUpdateMsj* o) {
	SogaView * v = new SogaView(o->getX(), o->getY(),o->getXHasta(),o->getYHasta(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CUERDA));
	v->update(o);
	if(o->isConEslabon()){
		v->setPosEslabonL(o->getXEslb(), o->getYEslb());
	}
	return v;

}


View* ViewObjetoUnionFactory::crearCorrea(ViewObjetoUnionUpdateMsj* o) {
	return new CorreaView(o->getX(), o->getY(),o->getXHasta(),o->getYHasta(), o->getRadioInicial(), o->getRadioFinal(), CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CORREA));
}


} /* namespace CLIENTE */
