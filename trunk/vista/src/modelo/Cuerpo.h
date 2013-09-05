/*
 * Cuerpo.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef CUERPO_H_
#define CUERPO_H_

class Cuerpo {
private:
	float posX, posY, alto, ancho, rotacion;
	bool isAdentro1D(float pos, float posCentro, float ancho);
public:
	bool isAdentro(float posX,float posY );
	bool isAdentro(const Cuerpo& cuerpo);
	Cuerpo(float posX,float posY,float ancho,float alto, float rotacion);
	Cuerpo(float posX,float posY,float ancho,float alto);
	Cuerpo(const Cuerpo& other);
	Cuerpo();
	virtual ~Cuerpo();
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
	float getPosX() const;
	void setPosX(float posX);
	float getPosY() const;
	void setPosY(float posY);
};

#endif /* CUERPO_H_ */
