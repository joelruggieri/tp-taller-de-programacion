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
	virtual bool clickDown(float,float) = 0;
	//recibe el evento de soltar el mouse.
	virtual bool clickUp(float, float)=0;
	virtual bool rightClickDown(float,float) = 0;
	//recibe el evento de soltar el mouse.
	virtual bool rightClickUp(float, float)=0;
	virtual bool mouseMotion(float, float)=0;
	//recibe el evento de mover la rueda del mouse.
	virtual bool mouseWheelMoved(float, float, int)=0;


};

#endif /* MOUSEEVENTCONTROLLER_H_ */
