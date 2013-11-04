/*
 * ViewController.h
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#ifndef VIEWCONTROLLER_H_
#define VIEWCONTROLLER_H_
#include <src/threading/ColaEventos.h>
#include <src/mensajes/userEvents/UserEventMsj.h>
#include <src/mensajes/viewMensaje/ViewMsj.h>
#include "../vista/View.h"
#include "SDL2/SDL.h"
#include <map>
using namespace std;

class ViewController {
//ENTREGA3 ESTA CLASE ES LA QUE TIENE TODAS LAS VISTAS PARA DIBUJARLAS.
//ADEMAS PERMITE ACTUALIZAR UNA VISTA
//PERMITE AGREGAR UNA VISTA MANUALMENTE TAMBIEN.
private:
	map<int, View*> vistas;
	ColaEventos * salida;
public:
	ViewController(ColaEventos * colaSalida);
	void receiveEvent(ViewMsj *);
	void sendEvent(UserEventMsj * );
	void addView(int id, View *);
	void dibujarse(SDL_Renderer *);
	virtual ~ViewController();
};

#endif /* VIEWCONTROLLER_H_ */
