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

#include "Archivo.h"
#include "AdministradorDeLoggers.h"

using namespace std;

const std::string fecha() {
	time_t tiempo = time(0);
	struct tm tiempoStruct = *localtime(&tiempo);
	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tiempoStruct);
	return buf;
}

//Logger::Logger(const char* nombre) :
//		archivo(nombre) {
//	this->nombre = nombre;
//}

Logger::~Logger() {
	archivo.close();
}

void Logger::error(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(ERROR);
	std::string salida = fecha() + " [ERROR]: " + mensaje;
	cout<< salida<< endl;
	a->escribir(salida);
}

void Logger::warning(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(WARN);
	std::string salida = fecha() + " [WARN]: " + mensaje;
	cout<< salida<< endl;
	a->escribir(salida);
}

void Logger::debug(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(DEBUG);
	std::string salida = fecha() + " [DEBUG]: " + mensaje;
	cout<< salida<< endl;
	a->escribir(salida);
}

void Logger::fatal(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(FATAL);
	std::string salida = fecha() + " [FATAL]: " + mensaje;
	cout<< salida<< endl;
	a->escribir(salida);
}

void Logger::info(std::string mensaje) {
	Archivo *a = AdministradorDeLoggers::getLogger(INFO);
	std::string salida = fecha() + " [INFO]: " + mensaje;
	cout<< salida<< endl;
	a->escribir(salida);
}


//void Logger::borrar() {
//	archivo.close();
//	archivo.open(nombre.c_str(),std::ofstream::trunc);
//}

void Logger::concatenar(std::string& mensajeOriginal,float numero){
	 std::stringstream ss (std::stringstream::out);
	 ss << numero;
	 mensajeOriginal.append(ss.str());
}

void Logger::concatenar(std::string& mensajeOriginal,double numero){
	 std::stringstream ss (std::stringstream::out);
	 ss << numero;
	 mensajeOriginal.append(ss.str());
}


Logger::Logger() {
	this->nombre = "";
}
