/*
 * ViewCarritoMsj.h
 *
 *  Created on: 17/11/2013
 *      Author: jonathan
 */

#ifndef VIEWCARRITOMSJ_H_
#define VIEWCARRITOMSJ_H_

#include "ViewMsj.h"

class ViewCarritoMsj: public ViewMsj {
private:
	float x,y,rotCarrito, rotRuedaI, rotRuedaD,xi,yi,xd,yd;
	int idEvento;
public:
	ViewCarritoMsj(float x, float y,float xi,float yi,float xd,float yd, float rotCarrito, float rotRuedI, float rotRuedaD, int id, int idEvent);

	virtual ~ViewCarritoMsj();
	void acept(ViewMsjVisitor *);
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator &);
	ViewMsj * clone(int destinatario);
	float getRotCarrito() const;
	float getRotRuedaD() const;
	float getRotRuedaI() const;
	float getX() const;
	float getXd() const;
	float getXi() const;
	float getY() const;
	float getYd() const;
	float getYi() const;
	int getIdEvento() const;
};

#endif /* VIEWCARRITOMSJ_H_ */
