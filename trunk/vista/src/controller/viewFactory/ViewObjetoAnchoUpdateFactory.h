/*
 * ViewObjetoAnchoUpdateFactory.h
 *
 *  Created on: 07/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWOBJETOANCHOUPDATEFACTORY_H_
#define VIEWOBJETOANCHOUPDATEFACTORY_H_
#include "../../vista/View.h"
#include "src/ConstantesComunicacion.h"
#include "../../ConstantesVista.h"
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
#include "../../vista/objeto/PlataformaView.h"
#include "../../vista/objeto/VistaEngranaje.h"
#include "../../vista/objeto/CintaTransportadoraView.h"
#include "../../vista/CargadorDeTextures.h"

namespace CLIENTE {

class ViewObjetoAnchoUpdateFactory {
private:
	View* crearEngranaje(ViewObjetoConAnchoUpdateMsj*);
	View* crearPlataforma(ViewObjetoConAnchoUpdateMsj*);
	View* crearCinta(ViewObjetoConAnchoUpdateMsj*);

public:
	ViewObjetoAnchoUpdateFactory();
	View* crear(ViewObjetoConAnchoUpdateMsj*);
};

} /* namespace CLIENTE */
#endif /* VIEWOBJETOANCHOUPDATEFACTORY_H_ */
