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
	static Archivo* obtenerArchivoNivel(int numero);
	static std::list<Archivo*> archivos;
	static void cerrarTodo();
	static Archivo* crearArchivoNivel(int numero);
private:
	static void cargar();
};

#endif /* ADMINISTRADORDEARCHIVOS_H_ */
