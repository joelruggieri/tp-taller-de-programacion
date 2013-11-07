/*
 * Resizeable.h
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#ifndef RESIZEABLE_H_
#define RESIZEABLE_H_
#include "../modelo/Transformacion.h"
namespace CLIENTE {
class Resizeable {
protected:
	Transformacion * tl;
public:
	Resizeable();
	virtual void resizear() = 0;

	virtual ~Resizeable();
	Transformacion* getTl() ;
	void setTl(Transformacion* tl);
};

}
#endif /* RESIZEABLE_H_ */
