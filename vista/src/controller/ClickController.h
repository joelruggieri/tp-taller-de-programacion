/*
 * ClickController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef CLICKCONTROLLER_H_
#define CLICKCONTROLLER_H_

class ClickController {
public:
	ClickController();
	virtual ~ClickController();
	//recibe un click en coordenadas pixels retorna true para propagar evento
	virtual bool clickDown(float,float) = 0;
	//recibe el evento de soltar el mouse.
	virtual bool clickUp(float, float)=0;
};

#endif /* CLICKCONTROLLER_H_ */
