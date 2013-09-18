/*
 * CanvasController.h
 *
 *  Created on: Sep 18, 2013
 *      Author: matias
 */

#ifndef CANVASCONTROLLER_H_
#define CANVASCONTROLLER_H_

#include "../vista/Canvas.h"

using namespace std;

class CanvasController {
private:
	Canvas* canvas;

public:
	CanvasController(Canvas* canvas);
	virtual ~CanvasController();
	void atenderEvento(SDL_Event evento);
};

#endif /* CANVASCONTROLLER_H_ */
