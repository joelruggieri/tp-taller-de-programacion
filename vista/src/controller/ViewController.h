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
#include <src/threading/ObjetoCompartido.h>
#include "ResizerController.h"
#include "DrawController.h"
#include "../vista/View.h"
#include "SDL2/SDL.h"
#include "../modelo/Observable.h"
#include "src/mensajes/viewMensaje/ViewMsjVisitor.h"
#include <map>
using namespace std;
namespace CLIENTE {
class ViewController: public ObjetoCompartido, public DrawController, public ResizerController, public ViewMsjVisitor {
//ENTREGA3 ESTA CLASE ES LA QUE TIENE TODAS LAS VISTAS PARA DIBUJARLAS.
//ADEMAS PERMITE ACTUALIZAR UNA VISTA
//PERMITE AGREGAR UNA VISTA MANUALMENTE TAMBIEN.
private:
	map<int, View*> vistas;
	list<View*> vistasList;
	list<View*> vistasScrolleables;
	SDL_Renderer * renderer;
	void crearPantalla();
	Transformacion * tl;
public:
	ViewController(SDL_Renderer *,Transformacion * tl);
	void visit(ViewMsj*);
	void addView(int id, View *);
	void addViewScrolleable(int id, View *);
	void scrollUnidadesLogicas(float unidadesLogicas);
	void dibujar();
	virtual ~ViewController();
	void resize(Transformacion * tl);
	void notify(int id, Observable* obs, event_type T);
};

}
#endif /* VIEWCONTROLLER_H_ */
