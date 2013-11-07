/*
 * ViewObjetoSimpleFactory.h
 *
 *  Created on: 7/11/2013
 *      Author: jonathan
 */

#ifndef VIEWOBJETOSIMPLEFACTORY_H_
#define VIEWOBJETOSIMPLEFACTORY_H_
#include "../../vista/View.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
#include "src/ConstantesComunicacion.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/objeto/GloboHelioView.h"
#include "../../vista/objeto/PelotaJuegoView.h"
#include "../../vista/objeto/BalancinView.h"
#include "../../vista/objeto/MotorView.h"
#include "../../vista/objeto/BolaBolicheView.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
namespace CLIENTE {

class ViewObjetoSimpleFactory {
private:
	//ENTREGA3 CHEQUEAR SI SON TODAS LAS FIGURAS QUE PUEDEN VENIRLE.
	View * crearGlobo(ViewObjetoUpdateMsj * );
	View * crearBola(ViewObjetoUpdateMsj * );
	View * crearPelota(ViewObjetoUpdateMsj * );
	View * crearMotor(ViewObjetoUpdateMsj * );
	View * crearBalancin(ViewObjetoUpdateMsj * );
public:
	ViewObjetoSimpleFactory();
	virtual ~ViewObjetoSimpleFactory();
	View * crear(ViewObjetoUpdateMsj *);
};

} /* namespace CLIENTE */
#endif /* VIEWOBJETOSIMPLEFACTORY_H_ */
