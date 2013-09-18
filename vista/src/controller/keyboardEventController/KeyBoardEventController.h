/*
 * KeyBoardEventController.h
 *
 *  Created on: 17/09/2013
 *      Author: ezequiel
 */

#ifndef KEYBOARDEVENTCONTROLLER_H_
#define KEYBOARDEVENTCONTROLLER_H_

class KeyBoardEventController {
public:
	KeyBoardEventController();
	virtual ~KeyBoardEventController();
	virtual bool keyPressed(char key) = 0;
	virtual bool keyReleased() = 0;
};

#endif /* KEYBOARDEVENTCONTROLLER_H_ */
