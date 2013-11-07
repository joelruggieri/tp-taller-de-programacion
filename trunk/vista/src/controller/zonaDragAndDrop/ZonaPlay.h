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
#include "../ViewController.h"
#include "../../vista/Canvas.h"
namespace CLIENTE {

class ZonaPlay {
private:
	Cuadrado * cuerpo;
	ColaEventos * salida;
	void crearVista(ViewController * vc);
	ViewController * controller;
public:
	ZonaPlay(ViewController * vc, float x, float y,ColaEventos * cola);
	virtual ~ZonaPlay();
	bool click(float x, float y);
};

}
#endif /* ZONAPLAY_H_ */
