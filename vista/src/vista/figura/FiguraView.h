/*
 * FiguraView.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURAVIEW_H_
#define FIGURAVIEW_H_
#include "src/figura/Figura.h"
//#include "../../modelo/figura/Figura.h"
#include <iostream>
#include "../View.h"
using namespace std;

class DragAndDropManager;
class FiguraView: public View {
private:
	Figura * modelo;
protected:
	virtual void dropTemplate(DragAndDropManager*) = 0;
public:
	FiguraView();
	virtual ~FiguraView();
	Figura * getModelo();
	void setModelo(Figura* modelo);
	void drop(DragAndDropManager* manager);
	void dibujarse();
};

#endif /* FIGURAVIEW_H_ */
