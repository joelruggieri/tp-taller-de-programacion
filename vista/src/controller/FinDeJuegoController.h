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
namespace CLIENTE {

class FinDeJuegoController: public ObjetoCompartido, public MensajePlanoVisitor {
private:
	bool terminado;
	bool ganado;
public:
	FinDeJuegoController();
	void visit (MensajePlano * m);
	virtual ~FinDeJuegoController();
	bool isTerminado();
	bool isGanado();

};

} /* namespace CLIENTE */
#endif /* FINDEJUEGOCONTROLLER_H_ */
