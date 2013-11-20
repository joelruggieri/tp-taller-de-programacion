/*
 * ViewTijeraMsj.h
 *
 *  Created on: 17/11/2013
 *      Author: jonathan
 */

#ifndef ViewTijeraMsj_H_
#define ViewTijeraMsj_H_

#include "ViewMsj.h"

class ViewTijeraMsj: public ViewMsj {
private:
	float x,y,rotacionAspa1, rotacionAspa2;
	int idEvento;
public:
	ViewTijeraMsj(float x, float y,float rotAspa1,float rotAsp2, int id,int idEvent);

	virtual ~ViewTijeraMsj();
	void acept(ViewMsjVisitor *);
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator &);
	ViewMsj * clone(int destinatario);
	float getRotacionAspa1() const;
	float getRotacionAspa2() const;
	float getX() const;
	float getY() const;
	int getIdEvento() const;
};

#endif /* ViewTijeraMsj_H_ */
