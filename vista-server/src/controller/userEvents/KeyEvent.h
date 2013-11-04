/*
 * KeyEvent.h
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#ifndef KEYEVENT_H_
#define KEYEVENT_H_

class KeyEvent {
private:
	char tecla;
	bool presionada;
public:
	KeyEvent(char t, bool pressed);
	virtual ~KeyEvent();
	char getTecla() const;
	bool isPresionada() const;
};

#endif /* KEYEVENT_H_ */
