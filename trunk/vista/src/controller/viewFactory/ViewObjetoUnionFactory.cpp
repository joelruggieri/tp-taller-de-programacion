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
//	case OBJ_UNION_S_CORREA_ESTATICA:
//		viewResult = this->crearCorreaEstatica(o);
//		break;
	case OBJ_UNION_S_SOGA:
		viewResult = this->crearSoga(o);
		break;
//	case OBJ_UNION_S_SOGA_ESTATICA:
//		viewResult = this->crearSogaEstatica(o);
//		break;
	}
return viewResult;
}

View* ViewObjetoUnionFactory::crearSoga(ViewObjetoUnionUpdateMsj* o) {
	return new SogaView(o->getX(), o->getY(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CUERDA));
}

//View* ViewObjetoUnionFactory::crearSogaEstatica(ViewObjetoUnionUpdateMsj* o) {
//	return new SogaEstaticaView(o->getX(), o->getY(),ANCHO_UNION_ESTATICA, ALTO_UNION_ESTATICA, CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CUERDA));
//}

View* ViewObjetoUnionFactory::crearCorrea(ViewObjetoUnionUpdateMsj* o) {
	return new CorreaView(o->getX(), o->getY(),CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CORREA));
}

//View* ViewObjetoUnionFactory::crearCorreaEstatica(ViewObjetoUnionUpdateMsj* o) {
//	return new CorreaEstaticaView(o->getX(), o->getY(),ANCHO_UNION_ESTATICA, ALTO_UNION_ESTATICA, CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CORREA));
//	}

} /* namespace CLIENTE */
