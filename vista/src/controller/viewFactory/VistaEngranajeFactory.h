/*
 * VistaEngranajeFactory.h
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#ifndef VISTAENGRANAJEFACTORY_H_
#define VISTAENGRANAJEFACTORY_H_

#include "ViewFiguraFactory.h"

namespace CLIENTE {
class SimpleEditorAnguloFijo;

class VistaEngranajeFactory: public ViewFiguraFactory {
public:
	VistaEngranajeFactory();
	virtual ~VistaEngranajeFactory();
	FiguraView * crear(int, int);
};
}
#endif /* VISTAENGRANAJEFACTORY_H_ */
