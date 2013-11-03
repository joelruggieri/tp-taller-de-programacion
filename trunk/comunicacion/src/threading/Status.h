/*
 * ThredStatus.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef STATUS_H_
#define STATUS_H_
#include <ctime>
#include "ObjetoCompartido.h"
using namespace std;

class IOThread;
class Status: public ObjetoCompartido {
private:
	time_t puntoControl;
	int timeout;
	IOThread * listener;
	bool vivo;
public:
	Status(int timeout);
	bool isAlive();
	void refresh();
	void setThread(IOThread*);
	IOThread* getThread();
	virtual ~Status();
	void kill();
	void clean();
	bool allowClient();
};

#endif /* THREDSTATUS_H_ */
