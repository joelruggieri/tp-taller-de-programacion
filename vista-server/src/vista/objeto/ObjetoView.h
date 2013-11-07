/*
 * ObjetoView.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef OBJETOVIEW_H_
#define OBJETOVIEW_H_

#include "../figura/FiguraView.h"
#include "src/ConstantesComunicacion.h"
class ObjetoView: public FiguraView {
public:
	ObjetoView(float x, float y, DropController * controller, char selector);
	virtual ~ObjetoView();
	virtual void dibujarse(list<ViewMsj*> & lista);
	char getSelector() const;

protected:
	char selector;
};

#endif /* OBJETOVIEW_H_ */
