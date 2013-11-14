/*
 * ViewBotonStartMsj.h
 *
 *  Created on: 13/11/2013
 *      Author: jonathan
 */

#ifndef VIEWBOTONSTARTMSJ_H_
#define VIEWBOTONSTARTMSJ_H_
#include "ViewMsj.h"

class ViewBotonStartMsj: public ViewMsj {
private:
	bool listo;
public:
	ViewBotonStartMsj(int id, bool listo);
	virtual ~ViewBotonStartMsj();
	void acept(ViewMsjVisitor *);
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator &);
	ViewMsj * clone(int destinatario);
	bool isListo();
};

#endif /* VIEWBOTONSTARTMSJ_H_ */
