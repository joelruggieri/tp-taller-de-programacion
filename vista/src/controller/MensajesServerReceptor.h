/*
 * FinDeJuegoController.h
 *
 *  Created on: 14/11/2013
 *      Author: jonathan
 */

#ifndef FINDEJUEGOCONTROLLER_H_
#define FINDEJUEGOCONTROLLER_H_

#include <src/threading/ObjetoCompartido.h>
#include <src/mensajes/MensajePlanoVisitor.h>
#include "src/ConstantesComunicacion.h"
#include "StatusJuego.h"
namespace CLIENTE {

class MensajesServerReceptor: public ObjetoCompartido, public MensajePlanoVisitor {
private:
	StatusJuego * status;
public:
	MensajesServerReceptor(StatusJuego * status);
	void visit (MensajePlano * m);
	virtual ~MensajesServerReceptor();
};

} /* namespace CLIENTE */
#endif /* FINDEJUEGOCONTROLLER_H_ */
