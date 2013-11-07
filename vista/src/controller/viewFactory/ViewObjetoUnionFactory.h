/*
 * ViewObjetoUnionFactory.h
 *
 *  Created on: 07/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWOBJETOUNIONFACTORY_H_
#define VIEWOBJETOUNIONFACTORY_H_
#include "../../vista/View.h"
#include "src/ConstantesComunicacion.h"
#include "../../ConstantesVista.h"
#include "../../vista/CargadorDeTextures.h"
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "../../vista/objeto/CorreaEstaticaView.h"
#include "../../vista/objeto/CorreaView.h"
#include "../../vista/objeto/SogaEstaticaView.h"
#include "../../vista/objeto/SogaView.h"
namespace CLIENTE {

class ViewObjetoUnionFactory {
public:
	ViewObjetoUnionFactory();
	View* crear (ViewObjetoUnionUpdateMsj*);
private:
	View* crearSoga(ViewObjetoUnionUpdateMsj*);
	View* crearSogaEstatica(ViewObjetoUnionUpdateMsj*);
	View* crearCorrea(ViewObjetoUnionUpdateMsj*);
	View* crearCorreaEstatica(ViewObjetoUnionUpdateMsj*);
};

} /* namespace CLIENTE */
#endif /* VIEWOBJETOUNIONFACTORY_H_ */
