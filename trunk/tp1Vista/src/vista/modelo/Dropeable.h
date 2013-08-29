/*
 * Dropeable.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef DROPEABLE_H_
#define DROPEABLE_H_
#include <string>
using namespace std;

class Dropeable {
private:
	float posX;
	float posY;
	string modelo;
public:
	Dropeable(string modelo);
	virtual ~Dropeable();

	float getPosX() const;
	void setPosX(float posX);
	float getPosY() const;
	void setPosY(float posY);
	string getModelo();
};

#endif /* DROPEABLE_H_ */
