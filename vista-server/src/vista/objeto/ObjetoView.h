/*
 * ObjetoView.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef OBJETOVIEW_H_
#define OBJETOVIEW_H_

#include "../figura/FiguraView.h"

class ObjetoView: public FiguraView {
public:
	ObjetoView(float x, float y, DropController * controller);
	virtual ~ObjetoView();
	virtual void dibujarse(list<ViewMsj*> & lista);
};

#endif /* OBJETOVIEW_H_ */
