/*
 * ThredStatus.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef STATUS_H_
#define STATUS_H_
//#include <chrono>
#include "src/threading/ObjetoCompartido.h"
using namespace std;

class Status: public ObjetoCompartido {
//	chrono::system_clock::time_point puntoControl;
private:
	int timeout;
public:
	Status(int timeout);
	bool isAlive();
	void refresh();
	virtual ~Status();
};

#endif /* THREDSTATUS_H_ */
