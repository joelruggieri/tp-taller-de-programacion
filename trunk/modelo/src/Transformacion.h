/*
 * Transformacion.h
 *
 *  Created on: 02/10/2013
 *      Author: jonathan
 */

#ifndef TRANSFORMACION_H_
#define TRANSFORMACION_H_

class Transformacion {
private:
	float angulo, transx, transy, escalax, escalay, x,y, ejex,ejey;
	bool invertirx,invertiry;
public:
	Transformacion();
	virtual ~Transformacion();
	void rotar(float angulo);
	void escalar(float x, float y);
	void traslacion(float x, float y);
	void invertir(bool, bool);
	void setVector(float x, float y);
	void setEjeRotacion(float x, float y);
	void getResultado(float &x, float &y);
};

#endif /* TRANSFORMACION_H_ */
