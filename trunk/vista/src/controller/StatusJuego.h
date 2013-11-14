/*
 * StatusJuego.h
 *
 *  Created on: 14/11/2013
 *      Author: jonathan
 */

#ifndef STATUSJUEGO_H_
#define STATUSJUEGO_H_

#include <src/threading/ObjetoCompartido.h>

namespace CLIENTE {

class StatusJuego: public ObjetoCompartido {
private:
	bool corriendo, terminado,ganado;
public:
	StatusJuego();
	void parar();
	void arrancar();
	void ganar();
	void perder();
	bool isCorriendo();
	bool isTerminado();
	bool isGanado();
	virtual ~StatusJuego();
};

} /* namespace CLIENTE */
#endif /* STATUSJUEGO_H_ */
