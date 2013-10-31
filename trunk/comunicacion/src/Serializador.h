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
#include "mensajes/ViewGloboUpdateMsj.h"
#include "mensajes/MensajePlano.h"
#include "mensajes/ViewBolaBolicheUpdateMsj.h"
#include "mensajes/ViewPelotaUpdateMsj.h"
#include "mensajes/ViewPlataformaUpdateMsj.h"
#include <string>
#include "yaml-cpp/yaml.h"
#include <sys/socket.h>
#include <list>
#include <iostream>

using namespace std;
class Serializador {
public:
	Serializador();
	virtual ~Serializador();
	list<NetworkMensaje*> leer(int sock);
private:
	map<string, NetworkMensaje*> mensajes;
};

#endif /* SERIALIZADOR_H_ */