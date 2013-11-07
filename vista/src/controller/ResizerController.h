/*
 * ResizerController.h
 *
 *  Created on: 6/11/2013
 *      Author: jonathan
 */

#ifndef RESIZERCONTROLLER_H_
#define RESIZERCONTROLLER_H_

namespace CLIENTE {

class ResizerController {
public:
	virtual ~ResizerController(){}
	virtual void resize(int, int) = 0;

};

} /* namespace CLIENTE */
#endif /* RESIZERCONTROLLER_H_ */
