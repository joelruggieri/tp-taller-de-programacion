/*
 * DropController.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 *
 *      TODO ESTE TIPO DEBERÍA HACER LOS PIXELS DE LA PANTALLA NO DEBERÍAN LLEGAR A LAS ZONAS.
 */

#ifndef DropController_H_
#define DropController_H_
//#include "../modelo/figuraFactory/FiguraFactory.h"
#include "src/figuraFactory/FiguraFactory.h"
#include "../vista/figura/FiguraView.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"
#include "MouseEventController.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/RomboView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/CirculoView.h"
#include "../vista/figura/TrianguloView.h"
#include <list>

using namespace std;

class DropController: public MouseEventController {
private:
	ZonaDragAndDrop * zona;
	FiguraFactory * figurasFactory;
	void dropear(FiguraView* view, Figura* figura);
	FiguraView * figuraDrag;
public:
	DropController();
	~DropController();
	void dropNuevaFigura(CuadradoView*);
	void dropNuevaFigura(CirculoView*);
	void dropNuevaFigura(TrianguloView*);
	void dropNuevaFigura(RomboView*);
	void dropFigura(FiguraView*);
	bool clickDown(float,float);
	bool clickUp(float, float);
	bool mouseMotion(float, float);
};

#endif /* DropController_H_ */


