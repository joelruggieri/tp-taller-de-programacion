/*
 * ManejadorErrores.cpp
 *
 *  Created on: 06/11/2013
 *      Author: ezequiel
 */

#include "ManejadorErrores.h"

int ManejadorErrores::manejarBindError(int error) {
int ret = -1;
Logger log;
switch(error)
{
case PUERTO_SIENDO_UTILIZADO:
	{
		log.error("El puerto esta siendo utilizado, intente de nuevo");
		return EJECUCION_TERMINA;//por ahora
	}
case SOCKET_YA_BINDEADO:
{
	log.error("El socket ya se encuentra atado a una direccion");
	return EJECUCION_TERMINA;
}
case MEMORIA_AGOTADA:
{
	log.error("La memoria del kernel se encuentra agotada");
	return EJECUCION_TERMINA;
}
}
return ret;
}

int ManejadorErrores::manejarAceptError(int error) {
int ret =  -1;
Logger log;
switch(error)
{
case CONEXION_ABORTADA:
{
	log.error("Conexion abortada");//ENTREGA3 ver como manejar este, mientras tanto corta conexion
	return EJECUCION_TERMINA;
}
case CONEXION_NO_PERMITIDA:
{
	log.error("Conexion prohibida, chequee firewall");
	return EJECUCION_TERMINA;
}
case NO_SE_ESCUCHA:
{
	log.error("El socket no esta escuchando conexiones");
	return EJECUCION_TERMINA;
}
}

return ret;
}

int ManejadorErrores::manejarListenError(int error) {
	Logger log;
int ret = -1;
switch(error)
{
case PUERTO_SIENDO_UTILIZADO:
	{
		log.error("El puerto esta siendo utilizado, intente de nuevo"); //ENTREGA3 esto se puede manejar
		return EJECUCION_TERMINA;//por ahora
	}

}
return ret;

}

int ManejadorErrores::manejarWriteError(int error) {
	Logger log;
int ret = -1;
switch(error)
{
case SENAL_DURANTE_CONEXION:
	log.error("Se ha terminado la conexion durante el envio de datos");	//ENTREGA3 revisar este caso
	return EJECUCION_TERMINA;//por ahora
}
return ret;

}

int ManejadorErrores::manejarReadError(int error) {
int ret = -1 ;
Logger log;
switch(error)
{
case SENAL_DURANTE_CONEXION:
	log.error("Se ha terminado la conexion durante la recepcion de datos");	//ENTREGA3 revisar este caso
	return EJECUCION_TERMINA;//por ahora
}
return ret ;
}

int ManejadorErrores::manejarConectError(int error) {
	int ret = -1 ;
	Logger log;
	switch(error)
	{
	case PERMISO_DENEGADO:
		log.error("No se tiene permiso para la conexion, chequee el firewall");	//ENTREGA3 revisar este caso
			return EJECUCION_TERMINA;//por ahora
	}
	return ret;
}
