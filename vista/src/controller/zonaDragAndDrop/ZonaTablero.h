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
#include <string>
using namespace std;
namespace CLIENTE {
class ZonaTablero {
private:
	Cuadrado * cuerpo;
	ColaEventos * salida;
	void crearVista(ViewController * vc);
	void setearTeclas(bool&, bool&);
public:
	ZonaTablero(ViewController * vc, ColaEventos * cola);
	virtual ~ZonaTablero();
	bool click(float, float);
	bool rightClick(float, float);
	bool clickUp(float, float);
	bool rightClickUp(float, float);
	bool keyPressed(char key);
	bool keyReleased(char key);
	bool mouseMotion(float, float);
};

}
#endif /* ZONATABLERO_H_ */

