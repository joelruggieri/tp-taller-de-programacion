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

View* ViewObjetoSimpleFactory::crearGlobo(ViewObjetoUpdateMsj*) {
	return NULL;
}

View* ViewObjetoSimpleFactory::crearBola(ViewObjetoUpdateMsj*) {
	return NULL;
}

View* ViewObjetoSimpleFactory::crearPelota(ViewObjetoUpdateMsj*) {
	return NULL;
}

View* ViewObjetoSimpleFactory::crearMotor(ViewObjetoUpdateMsj*) {
	return NULL;
}

View* ViewObjetoSimpleFactory::crearBalancin(ViewObjetoUpdateMsj*) {
	return NULL;
}

ViewObjetoSimpleFactory::~ViewObjetoSimpleFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewObjetoSimpleFactory::crear(ViewObjetoUpdateMsj*) {
	//ENTREGA3 switch por el selector y llamar al metodo que corresponda
	return NULL;
}

} /* namespace CLIENTE */
