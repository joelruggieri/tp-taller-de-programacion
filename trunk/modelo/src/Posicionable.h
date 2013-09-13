/*
 * Posicionable.h
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#ifndef POSICIONABLE_H_
#define POSICIONABLE_H_

class Posicionable {
public:
	Posicionable();
	virtual ~Posicionable();
	virtual float getX() const = 0;
	virtual float getY() const = 0;
};

#endif /* POSICIONABLE_H_ */
