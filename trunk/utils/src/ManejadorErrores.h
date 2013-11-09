/*
 * ManejadorErrores.h
 *
 *  Created on: 06/11/2013
 *      Author: ezequiel
 */

#ifndef MANEJADORERRORES_H_
#define MANEJADORERRORES_H_
#define EJECUCION_TERMINA -1
#define EJECUCION_CONTINUA 0
#define PUERTO_SIENDO_UTILIZADO 98
#define SOCKET_YA_BINDEADO 22
#define MEMORIA_AGOTADA 12
#define CONEXION_ABORTADA 103
#define CONEXION_NO_PERMITIDA 1
#define NO_SE_ESCUCHA 22
#define SENAL_DURANTE_CONEXION 4
#define PERMISO_DENEGADO 13
//#define
#include "Logger.h"
class ManejadorErrores {
public:
	static int manejarBindError(int);
	static int manejarAceptError(int);
	static int manejarListenError(int);
	static int manejarWriteError(int);
	static int manejarReadError(int);
	static int manejarConectError(int);
//	static Logger log;
private:
;
};

#endif /* MANEJADORERRORES_H_ */
