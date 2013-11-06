/*
 * VistaCintaTransportadoraFactory.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VistaCINTATRANSPORTADORAFACTORY_H_
#define VistaCINTATRANSPORTADORAFACTORY_H_

#include "ViewFiguraFactory.h"

namespace CLIENTE {
class SimpleEditorEstirar;

class VistaCintaTransportadoraFactory: public ViewFiguraFactory {
public:
	VistaCintaTransportadoraFactory();
	virtual ~VistaCintaTransportadoraFactory();
	FiguraView * crear(int,int);
};

#endif /* VistaCINTATRANSPORTADORAFACTORY_H_ */
}
