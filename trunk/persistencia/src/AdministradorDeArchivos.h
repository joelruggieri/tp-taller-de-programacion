/*
 * AdministradorDeArchivos.h
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#ifndef ADMINISTRADORDEARCHIVOS_H_
#define ADMINISTRADORDEARCHIVOS_H_

#include <string>
#include <list>
#include "src/Archivo.h"

class AdministradorDeArchivos {
public:
	AdministradorDeArchivos();
	virtual ~AdministradorDeArchivos();
	static Archivo* obtenerArchivoNivel(const char *numero);
	static Archivo* obtenerArchivoNivel(const std::string &numero);
	static std::list<Archivo*> archivos;
	static void cerrarTodo();
	static Archivo* crearArchivoNivel(const char* numero);
	static void registrar(std::string nombre);
};

#endif /* ADMINISTRADORDEARCHIVOS_H_ */
