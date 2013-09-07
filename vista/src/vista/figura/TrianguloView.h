/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef TRIANGULOVIEW_H_
#define TRIANGULOVIEW_H_

#include "FiguraView.h"

class TrianguloView: public FiguraView {
private:
	void dropTemplate(DragAndDropManager*);
public:
	TrianguloView();
	virtual ~TrianguloView();

};

#endif /* CUADRADOVIEW_H_ */
