/*
 * Serializador.h

 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#ifndef SERIALIZADOR_H_
#define SERIALIZADOR_H_
#include "ConstantesComunicacion.h"
#include "mensajes/NetworkMensaje.h"
#include <map>
#include <utility>
#include "mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
#include "mensajes/MensajePlano.h"
#include "mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
#include "mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "mensajes/userEvents/MouseMotionMsj.h"
#include "mensajes/userEvents/CreacionMsj.h"
#include <string>
#include "yaml-cpp/yaml.h"
#include <sys/socket.h>
#include <list>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <src/Logger.h>
using namespace std;
class Serializador {
public:
	Serializador(int destinatario);
	virtual ~Serializador();
	void leer(int sock, list<NetworkMensaje*> & lista);
	void escribir(list<NetworkMensaje*>& lista, int socket);
	void escribir(NetworkMensaje * msj, int socket);
private:
	map<string, NetworkMensaje*> mensajes;
	int destinatario;
	Logger log;
};

#endif /* SERIALIZADOR_H_ */
