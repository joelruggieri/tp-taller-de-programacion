/*
 * ZonaPlay.h
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#ifndef ZONAPLAY_H_
#define ZONAPLAY_H_
#include "../../modelo/Cuadrado.h"
#include "../../vista/BotonSwitch.h"
#include <src/threading/ColaEventos.h>
class ZonaPlay {
private:
	//ENTREGA3 EL BOTON SWITCH ESTA COMPARTIDO ENTRE THREADS, GUARDA
	BotonSwitch * boton;
	Cuadrado * cuerpo;
	ColaEventos * salida;
public:
	ZonaPlay(float x, float y,ColaEventos * cola);
	virtual ~ZonaPlay();
	bool click(float x, float y);
};

#endif /* ZONAPLAY_H_ */
