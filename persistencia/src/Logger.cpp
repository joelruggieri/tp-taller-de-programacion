/*
 * Logger.cpp
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#include "Logger.h"
#include <fstream>
#include <iostream>
#include <time.h>

const std::string fecha() {
	time_t tiempo = time(0);
	struct tm tiempoStruct = *localtime(&tiempo);
	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tiempoStruct);
	return buf;
}

Logger::Logger(const char* nombre) :
		archivo(nombre) {
	this->nombre = nombre;
}

Logger::~Logger() {
	archivo.close();
}

void Logger::error(std::string mensaje) {
		archivo << fecha() << " [ERROR] " << ": " << mensaje;
}

void Logger::warning(std::string mensaje) {
		archivo << fecha() << " [WARN] " << ": " << mensaje;
}

void Logger::debug(std::string mensaje) {
		archivo << fecha() << " [DEBUG] " << ": " << mensaje;
}

void Logger::borrar() {
	archivo.close();
	archivo.open(nombre.c_str(),std::ofstream::trunc);
}

Logger::Logger() {
	this->nombre = "";
}
