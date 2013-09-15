/*
 * toolBarController.h
 *
 *  Created on: 15/09/2013
 *      Author: ezequiel
 */

#ifndef TOOLBARCONTROLLER_H_
#define TOOLBARCONTROLLER_H_
#include "zonaToolBar/ZonaToolBar.h"
#include "mouseEventController/MouseControllerPrioridades.h"
#include "ToolBarEventController.h"

class ToolBarController : public MouseControllerPrioridades {
public:
	ZonaToolBar* zona ;

	// por ahora le pido una zona
	ToolBarController(ZonaToolBar *zona, ToolBarEventController* toolBarEvent ): MouseControllerPrioridades(toolBarEvent,1,1)
	{
		this->zona = zona ;
	}


//	void
	virtual ~ToolBarController();

};

#endif /* TOOLBARCONTROLLER_H_ */
