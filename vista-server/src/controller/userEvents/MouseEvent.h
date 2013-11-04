/*
 * MouseEvent.h
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#ifndef MOUSEEVENT_H_
#define MOUSEEVENT_H_

class MouseEvent {
private:
	bool izquierdo,apretado, ctrl, shift;
	float x,y;
public:
	MouseEvent(float x, float y, bool i, bool a, bool c, bool s);
	virtual ~MouseEvent();
	bool isApretado() const;
	bool isIzquierdo() const;
	float getX() const;
	float getY() const;
	bool isCtrl() const;
	bool isShift() const;
};

#endif /* MOUSEEVENT_H_ */
