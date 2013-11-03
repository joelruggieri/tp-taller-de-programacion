/*
 * LoggingService.h
 *
 *  Created on: 03/11/2013
 *      Author: jonathan
 */

#ifndef LOGGINGSERVICE_H_
#define LOGGINGSERVICE_H_
#include "ColaLogs.h"
#include "Worker.h"
namespace LOG {

class LoggingService {
private:
	Worker * worker;
public:
	static ColaLogs * colaLogs;
	LoggingService();
	virtual ~LoggingService();
};

} /* namespace LOG */
#endif /* LOGGINGSERVICE_H_ */
