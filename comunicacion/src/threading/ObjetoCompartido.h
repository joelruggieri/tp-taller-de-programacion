/*
 * ObjetoCompartido.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef OBJETOCOMPARTIDO_H_
#define OBJETOCOMPARTIDO_H_
#include <mutex>
using namespace std;

class ObjetoCompartido {
private:
	mutex traba;
public:
	ObjetoCompartido();
	virtual ~ObjetoCompartido();
	void lock();
	void unlock();
};

#endif /* OBJETOCOMPARTIDO_H_ */
