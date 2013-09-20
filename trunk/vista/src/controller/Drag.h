/*
 * Drag.h
 *
 *  Created on: 19/09/2013
 *      Author: jonathan
 */

#ifndef DRAG_H_
#define DRAG_H_

#include "../vista/figura/FiguraView.h"

class Drag {
private:
	FiguraView * view;
	int xStart;
	int yStart;
	int yMax;
public:
	Drag(FiguraView* view, int yMax);
	void drop();
	virtual ~Drag();
	FiguraView * getView();
	int desplazarCentroA(int &x, int &y);
	int getXCentro() const;
	int getYCentro() const;
	void rollBack();
	bool isRolledBack() const;
};

#endif /* DRAG_H_ */
