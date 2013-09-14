/*
 * PersistenciaManager.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef PERSISTENCIAMANAGER_H_
#define PERSISTENCIAMANAGER_H_
#include <list>
using namespace std;
#include "src/figura/Figura.h"

class PersistenciaManager {
private:
	list<Figura*> figurasPersistidas;
public:
	PersistenciaManager();
	virtual ~PersistenciaManager();
	list<Figura*> & getFiguras();
};

#endif /* PERSISTENCIAMANAGER_H_ */
