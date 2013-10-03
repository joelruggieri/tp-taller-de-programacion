/*
 * FlujoDeJuegoController.h
 *
 *  Created on: 02/10/2013
 *      Author: jonathan
 */

#ifndef FLUJODEJUEGOCONTROLLER_H_
#define FLUJODEJUEGOCONTROLLER_H_

class FlujoDeJuegoController {
public:
	virtual ~FlujoDeJuegoController(){

	};
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void paso() = 0;
};

#endif /* FLUJODEJUEGOCONTROLLER_H_ */
