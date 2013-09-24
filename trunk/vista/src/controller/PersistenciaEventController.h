/*
 * PersistenciaEventController.h
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#ifndef PERSISTENCIAEVENTCONTROLLER_H_
#define PERSISTENCIAEVENTCONTROLLER_H_
#include "PersistenciaManager.h"
#include "src/ModeloController.h"
#include "CanvasController.h"

class PersistenciaEventController {
private:
	PersistenciaManager * manager;
	ModeloController * modeloController;
	CanvasController * canvasController;
public:
	PersistenciaEventController(ModeloController * m, CanvasController * c, PersistenciaManager *);
	void persistir();
	virtual ~PersistenciaEventController();
};

#endif /* PERSISTENCIAEVENTCONTROLLER_H_ */
