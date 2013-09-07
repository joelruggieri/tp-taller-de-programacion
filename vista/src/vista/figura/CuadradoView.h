/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef CUADRADOVIEW_H_
#define CUADRADOVIEW_H_

#include "FiguraView.h"

class CuadradoView: public FiguraView {
private:
	void dropTemplate(DragAndDropManager*);
public:
	CuadradoView();
	virtual ~CuadradoView();

};

#endif /* CUADRADOVIEW_H_ */
