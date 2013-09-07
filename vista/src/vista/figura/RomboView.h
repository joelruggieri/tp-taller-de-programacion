/*
 * RomboView.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef ROMBOVIEW_H_
#define ROMBOVIEW_H_

#include "FiguraView.h"

class RomboView: public FiguraView {
private:
	void dropTemplate(DragAndDropManager*);
public:
	RomboView();
	virtual ~RomboView();
};

#endif /* ROMBOVIEW_H_ */
