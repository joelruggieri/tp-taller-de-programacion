/*
 * Highlight.h
 *
 *  Created on: 13/11/2013
 *      Author: jonathan
 */

#ifndef HIGHLIGHT_H_
#define HIGHLIGHT_H_

#include "ViewMsj.h"

class Highlight: public ViewMsj {
public:
	Highlight(int id);
	virtual ~Highlight();
	void acept(ViewMsjVisitor *);
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator &);
	ViewMsj * clone(int destinatario);
};

#endif /* HIGHLIGHT_H_ */
