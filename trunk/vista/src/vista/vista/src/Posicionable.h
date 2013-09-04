/*
 * Posicionable.h
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#ifndef POSICIONABLE_H_
#define POSICIONABLE_H_

namespace std {

class  Posicionable {
protected:
	int x,y,w,h;
public:
	Posicionable();
	virtual ~Posicionable();
};

} /* namespace std */
#endif /* POSICIONABLE_H_ */
