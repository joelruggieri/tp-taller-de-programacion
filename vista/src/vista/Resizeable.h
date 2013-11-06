/*
 * Resizeable.h
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#ifndef RESIZEABLE_H_
#define RESIZEABLE_H_

namespace CLIENTE {
class Resizeable {
public:
	Resizeable();
	virtual void resizear() = 0;
	virtual ~Resizeable();
};

}
#endif /* RESIZEABLE_H_ */
