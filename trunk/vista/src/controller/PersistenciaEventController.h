/*
 * PersistenciaEventController.h
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#ifndef PERSISTENCIAEVENTCONTROLLER_H_
#define PERSISTENCIAEVENTCONTROLLER_H_
#include "PersistenciaManager.h"
#include "src/figura/Mapa.h"


class PersistenciaEventController {
private:
	PersistenciaManager * manager;
	Mapa * mapa;
public:
	PersistenciaEventController(Mapa * m, PersistenciaManager *);
	void persistir();
	virtual ~PersistenciaEventController();
};

#endif /* PERSISTENCIAEVENTCONTROLLER_H_ */
