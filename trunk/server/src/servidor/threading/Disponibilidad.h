/*
 * Disponibilidad.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef DISPONIBILIDAD_H_
#define DISPONIBILIDAD_H_
#include "src/threading/ObjetoCompartido.h"
#include <map>
using namespace std;
//LIBERADO tengo que deletear el que estaba y crear uno nuevo.
//LIBRE tengo que crear solamente.
class ThreadStatus;
class Disponibilidad: public ObjetoCompartido {
private:
	map<int,ThreadStatus *> relaciones;
public:
	Disponibilidad(int maxJugadores);
	virtual ~Disponibilidad();
//	bool exist(int socket);
	ThreadStatus * getStatus(int jugador);
	ThreadStatus * getNextFree();
	void cleanDeaths();
};

#endif /* DISPONIBILIDAD_H_ */