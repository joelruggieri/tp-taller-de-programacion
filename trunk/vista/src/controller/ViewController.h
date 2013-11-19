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
#include <src/mensajes/viewMensaje/ViewBotonStartMsj.h>
#include <src/mensajes/viewMensaje/Highlight.h>
#include <src/mensajes/viewMensaje/ViewCarritoMsj.h>
#include <src/mensajes/viewMensaje/ViewTijeraMsj.h>
#include <src/threading/ObjetoCompartido.h>
#include "ResizerController.h"
#include "DrawController.h"
#include "../vista/View.h"
#include "SDL2/SDL.h"
#include "../modelo/Observable.h"
#include "src/mensajes/viewMensaje/ViewMsjVisitor.h"
#include "../vista/AreaView.h"
#include "../modelo/Cuadrado.h"
#include "../vista/AreaMensajes.h"
#include <map>
using namespace std;
namespace CLIENTE {
class ViewController: public ObjetoCompartido, public DrawController, public ResizerController, public ViewMsjVisitor {
//ENTREGA3 ESTA CLASE ES LA QUE TIENE TODAS LAS VISTAS PARA DIBUJARLAS.
//ADEMAS PERMITE ACTUALIZAR UNA VISTA
//PERMITE AGREGAR UNA VISTA MANUALMENTE TAMBIEN.
private:
	int highlightsActual;
	int highlightsAnterior;
//	AreaView* areaVista;
//	AreaMensajes* areaMensajes;
	string objetivo;
	map<int, View*> vistas;
	list<View*> vistasList;
	list<View*> vistasScrolleables;
	SDL_Renderer * renderer;
	void crearPantalla();
	bool update(ViewMsj *);
	Transformacion * tl;
	void addViewPrivado(int id, View *);
	typedef ObjetoCompartido super;
	bool ordenar, huboHighLighT;
public:
	void generarVistaArea(float, float  ,float ,float);
	ViewController(SDL_Renderer *,Transformacion * tl, Cuadrado cuadradoArea, string objetivo);
	void visit(ViewObjetoConAnchoUpdateMsj*);
	void visit(ViewObjetoUpdateMsj*);
	void visit(ViewObjetoUnionUpdateMsj*);
	void visit(FinDibujado*);
	void visit(ViewBotonStartMsj*);
	void visit(Highlight*);
	void visit(ViewCarritoMsj*);
	void visit(ViewTijeraMsj*);
	void addView(int id, View *);
	void addViewScrolleable(int id, View *);
	void scrollUnidadesLogicas(float unidadesLogicas);
	void dibujar();
	virtual ~ViewController();
	void resize(Transformacion * tl);
	void lock();
	void unlock();
	//LLAMAR EL ENDUPDATE DSPS DE TOCAR LO DE LA CLASE. ESTO PUEDE CLAVAR EL JUEGO YA QUE SINCRONIZA CON EL THREAD DE DIBUJADO
	View * getForUpdate(int id);
	void endUpdate();
};

}
#endif /* VIEWCONTROLLER_H_ */
