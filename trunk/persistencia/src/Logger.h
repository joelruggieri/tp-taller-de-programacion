/*
 * Logger.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <fstream>

//Niveles del logger:
//	0 - No loguea nada
//	1 - Error
//	2 - Warning
//	3 - Debug

class Logger {
public:
	Logger(std::string nombre);
	virtual ~Logger();
	void error(std::string mensaje);
	void warning(std::string mensaje);
	void debug(std::string mensaje);
	void setNivel(int nivel);
private:
	int nivel;
	std::string nombre;
	std::ofstream archivo;
};

#endif /* LOGGER_H_ */
