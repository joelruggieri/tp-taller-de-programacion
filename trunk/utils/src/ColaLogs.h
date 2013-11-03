/*
 * ColaLogs.h
 *
 *  Created on: 03/11/2013
 *      Author: jonathan
 */

#ifndef COLALOGS_H_
#define COLALOGS_H_
#include <pthread.h>

#include <string>
#include <list>
using namespace std;
namespace LOG {
class ColaLogs {
private:
	pthread_mutex_t mutex;
	list<string> buffer;
public:
	ColaLogs();
	virtual ~ColaLogs();
	void lock();
	void unlock();
	void push(string msj);
	string front();
	bool hasNext();
};

} /* namespace LOG */
#endif /* COLALOGS_H_ */
