/*
 * DrawController.h
 *
 *  Created on: 04/10/2013
 *      Author: jonathan
 */

#ifndef DRAWCONTROLLER_H_
#define DRAWCONTROLLER_H_

namespace CLIENTE {
class DrawController {
public:
	virtual ~DrawController(){

	};
	virtual void dibujar() = 0;

};

}
#endif /* DRAWCONTROLLER_H_ */
