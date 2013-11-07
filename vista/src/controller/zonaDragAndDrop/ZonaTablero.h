/*
 * ZonaTablero.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONATABLERO_H_
#define ZONATABLERO_H_

#include <list>
#include "../../vista/figura/FiguraView.h"
#include "../../vista/Canvas.h"
#include "../ViewController.h"
#include <map>
#include "../../modelo/Observer.h"
#include "../../modelo/Cuadrado.h"
#include "src/threading/ColaEventos.h"
using namespace std;
namespace CLIENTE {
class ZonaTablero {
private:
	Cuadrado * cuerpo;
	ColaEventos * salida;
	void crearVista(ViewController * vc);
public:
	ZonaTablero(ViewController * vc, ColaEventos * cola);
	virtual ~ZonaTablero();
	bool click(float, float);
	void rightClick(float, float);
	void keyPressed(char key);
	void keyReleased(char key);
};

}
#endif /* ZONATABLERO_H_ */

