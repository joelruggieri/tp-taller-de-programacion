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
	float xStart, yStart, yMax;
public:
	Drag(FiguraView* view, float yMax);
	void drop();
	virtual ~Drag();
	FiguraView * getView();
	float desplazarCentroA(float &x, float &y);
	float getXCentro() const;
	float getYCentro() const;
	void rollBack();
	bool isRolledBack() const;
};

#endif /* DRAG_H_ */
