/*
 * Objeto.h
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#ifndef OBJETO_H_
#define OBJETO_H_

class Objeto {
public:
	Objeto();
	Objeto(float x, float y);
	virtual ~Objeto();

	float getPosX() const;

	float getPosY() const;

	void setPosX(float posX);

	void setPosY(float posY);
	bool operator == (const Objeto &p) const;

private:
	float posX;
	float posY;
};

#endif /* OBJETO_H_ */
