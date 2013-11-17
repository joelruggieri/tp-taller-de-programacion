/*
 * ViewObjetoUnionUpdateMsj.h
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#ifndef VIEWOBJETOUNIONUPDATEMSJ_H_
#define VIEWOBJETOUNIONUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"

class ViewObjetoUnionUpdateMsj: public ViewObjetoUpdateMsj {
private:
	float xHasta,yHasta,radioInicial, radioFinal, radio, xEslb, yEslb;
	bool estatico;
	bool conEslabon;
public:
	ViewObjetoUnionUpdateMsj(float xD, float yD, float xH,float yH, float radioInicial,float radioFinal,bool esEstatico, bool conEslabon,float radio,int id, char sel);
	virtual ~ViewObjetoUnionUpdateMsj();
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
	string getTag();
	void getMensaje();
	ViewMsj * clone(int dest);
	void acept(ViewMsjVisitor *);
	float getXHasta() const {
		return xHasta;
	}

	void setXHasta(float hasta) {
		xHasta = hasta;
	}

	float getYHasta() const {
		return yHasta;
	}

	void setYHasta(float hasta) {
		yHasta = hasta;
	}

	float getRadioFinal() const;
	float getRadioInicial() const;

	bool isEstatico() const {
		return estatico;
	}

	float getRadio() const {
		return radio;
	}
	void setPosEslabon(float x, float y);
	bool isConEslabon() const;
	float getXEslb() const;
	float getYEslb() const;
};

#endif /* VIEWOBJETOUNIONUPDATEMSJ_H_ */
