/*
 * MouseEventController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef MOUSEEVENTCONTROLLER_H_
#define MOUSEEVENTCONTROLLER_H_

class MouseEventController {
public:
	MouseEventController();
	virtual ~MouseEventController();
	//recibe un click en coordenadas pixels retorna true para propagar evento
	virtual bool clickDown(int,int) = 0;
	//recibe el evento de soltar el mouse.
	virtual bool clickUp(int, int)=0;
	virtual bool rightClickDown(int,int) = 0;
	//recibe el evento de soltar el mouse.
	virtual bool rightClickUp(int, int)=0;
	virtual bool mouseMotion(int, int)=0;


};

#endif /* MOUSEEVENTCONTROLLER_H_ */
