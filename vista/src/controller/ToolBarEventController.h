/*
 * ToolBarEventController.h
 *
 *  Created on: 15/09/2013
 *      Author: ezequiel
 */

#ifndef TOOLBAREVENTCONTROLLER_H_
#define TOOLBAREVENTCONTROLLER_H_
#include "mouseEventController/MouseEventController.h"
#include "zonaToolBar/ZonaToolBar.h"
#include "keyboardEventController/KeyBoardEventController.h"
class ToolBarEventController : public MouseEventController, public KeyBoardEventController {
public:
	ZonaToolBar* zona ;
	bool seleccionado ;
	ToolBarEventController(ZonaToolBar* zona);
	virtual ~ToolBarEventController();
	 bool clickDown(int,int);
		//recibe el evento de soltar el mouse.
		 bool clickUp(int, int);
		 bool rightClickDown(int,int);
		 bool keyPressed(char key);
		 bool rightClickUp(int, int);
		 bool mouseMotion(int, int);
		 bool keyReleased();
		void resizear();

};

#endif /* TOOLBAREVENTCONTROLLER_H_ */
