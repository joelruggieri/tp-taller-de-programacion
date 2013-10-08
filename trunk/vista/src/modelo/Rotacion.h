/*
 * Rotacion.h
 *
 *  Created on: 11/09/2013
 *      Author: jonathan
 */

#ifndef ROTACION_H_
#define ROTACION_H_

class Rotacion {
private:
	double xc, yc;
	double x0, y0;
	double angulo;
	int rotaciones;
	double direccion;

	void loggear(double xN, double yN);

public:
	Rotacion(int x, int y, int x0, int y0, float anguloI);
	double rotar(double x, double y);
	
	virtual ~Rotacion();
	double getAngulo() const;
	double getDireccion() const;
};

#endif /* ROTACION_H_ */
