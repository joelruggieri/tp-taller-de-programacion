/*
 * Disponibilidad.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef DISPONIBILIDAD_H_
#define DISPONIBILIDAD_H_
#include "ObjetoCompartido.h"
#include <map>
using namespace std;
//LIBERADO tengo que deletear el que estaba y crear uno nuevo.
//LIBRE tengo que crear solamente.
enum ESTADO {LIBERADO=-2, LIBRE=-1};
class ThreadStatus;
class Disponibilidad: public ObjetoCompartido {
private:
	map<int,ThreadStatus *> relaciones;
public:
	Disponibilidad(int maxJugadores);
	virtual ~Disponibilidad();
	ThreadStatus * getStatus(int jugador);
	ThreadStatus * getNextFree();
};

#endif /* DISPONIBILIDAD_H_ */
