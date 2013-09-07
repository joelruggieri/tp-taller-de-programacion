/*
 * DropManager.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 *
 *      TODO ESTE TIPO DEBERÍA HACER LOS PIXELS DE LA PANTALLA NO DEBERÍAN LLEGAR A LAS ZONAS.
 */

#ifndef DROPMANAGER_H_
#define DROPMANAGER_H_
//#include "../modelo/figuraFactory/FiguraFactory.h"
#include "src/figuraFactory/FiguraFactory.h"
#include "../vista/figura/FiguraView.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"
#include "ClickController.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/RomboView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/CirculoView.h"
#include "../vista/figura/TrianguloView.h"
#include <list>

using namespace std;

class DropManager: public ClickController {
private:
	ZonaDragAndDrop * zona;
	FiguraFactory * figurasFactory;
	void dropear(FiguraView* view, Figura* figura);

public:
	DropManager();
	~DropManager();
	void dropNuevaFigura(CuadradoView*);
	void dropNuevaFigura(CirculoView*);
	void dropNuevaFigura(TrianguloView*);
	void dropNuevaFigura(RomboView*);
	void dropFigura(FiguraView*);
	FiguraView* drag(float, float);
};

#endif /* DROPMANAGER_H_ */


