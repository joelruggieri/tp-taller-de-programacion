/*
 * Serializador.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "Serializador.h"
#include "SerializacionException.h"
#include "mensajes/userEvents/ClickMsj.h"
#include "mensajes/ConfiguracionNivelMsj.h"
#include "src/ManejadorErrores.h"
#include <errno.h>
#define MAX_BUFFER 1024
Serializador::Serializador(int destinatario) {
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_VIEW_OBJETO_SIMPLE), new ViewObjetoUpdateMsj(0, 0, 0, 0,'a')));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_MSJ_PLANO), new MensajePlano("")));
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_VIEW_OBJETO_CON_ANCHO),
					new ViewObjetoConAnchoUpdateMsj(0, 0, 0, 0, 0, 'a')));
	this->mensajes.insert(
			pair<string, NetworkMensaje*>(string(TAG_VIEW_OBJETO_UNION), new ViewObjetoUnionUpdateMsj(0, 0, 0, 0, 0, 'a')));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_CLICK), new ClickMsj(0, 0, 0, 0, 0, 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(MSJ_CONFIG_JUGADOR), new ConfiguracionNivelMsj()));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_MOUSE_MOTION), new MouseMotionMsj(0, 0, 0, 0)));
	this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_CREACION_OBJETO), new CreacionMsj("")));
	this->destinatario = destinatario;
}

Serializador::~Serializador() {
	map<string, NetworkMensaje*>::const_iterator iter;
	for (iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter) {
		delete iter->second;
	}
}

void Serializador::leer(int sock, list<NetworkMensaje*> & lista) {

//	string buffer;
	char buffer[1024] = "";
	char bufferAux[1024] = "";
	int longitudTotal;
	int longRecibida;
	int recibidos = 0;
	read(sock, &longitudTotal, sizeof(int));

	while (recibidos < longitudTotal) {
		read(sock, &longRecibida, sizeof(int));
		recibidos += recv(sock, &bufferAux, longRecibida, 0);
//		errno;

		if (recibidos == -1){
			//TODO CHEQUEAR ERRNO PARA VER QUE ACCION TOMAR:   http://www.cisco.com/en/US/docs/ios/sw_upgrades/interlink/r2_0/unpremsg/mucsock.html
			if ( ManejadorErrores::manejarReadError(errno) < 0)
			throw SerializacionException("No se pudo recibir el mensaje al host");

		}
		strcat(buffer, bufferAux);
	}
	string clave;

	string aux = buffer;
//	cout <<  longitud << endl;
	YAML::Node lineup = YAML::Load(aux.substr(0, longitudTotal));
	NetworkMensaje * msj;
	YAML::const_iterator it = lineup.begin();
	//TODO PROBAR ESTO DE ENVIAR MIERDA A VER QUE HACE
	while (it != lineup.end()) {
		bool tagEncontrado = false;
		while (!tagEncontrado && it != lineup.end()) {
			try {
				tagEncontrado = true;
				clave = it->as<string>();
				it++;
			} catch (YAML::Exception &exc) {
				//AVANZO A VER SI ENCUENTRO ALGO INTERESANTE PARA LEER
				tagEncontrado = false;
				it++;
			}
		}

		if (tagEncontrado) {

			std::map<string, NetworkMensaje*>::iterator msjCreator = this->mensajes.find(clave);
			if (msjCreator != mensajes.end()) {
				try {
					msj = msjCreator->second->deserialize(it);
					msj->setDestinatario(this->destinatario);
					lista.push_back(msj);
				} catch (YAML::Exception &exc) {
					//AVANZO A VER SI ENCUENTRO ALGO INTERESANTE PARA LEER
					it++;
				}
			} else {
				//AVANZO A VER SI ENCUENTRO ALGO INTERESANTE PARA LEER
				it++;
			}
		}
	}
}

void Serializador::escribir(list<NetworkMensaje*>& lista, int socket) {
	list<NetworkMensaje*>::iterator it = lista.begin();
	YAML::Node nodo;
	stringstream envio;

	while (it != lista.end()) {
		(*it)->serialize(&nodo);
		it++;

	}
	envio << nodo;
	int enviados = 0;
//	 const char * str = envio.str().c_str();
	int len = strlen(envio.str().c_str());
	int longEnviada;
	send(socket, &len, sizeof(int), 0);	//envio longitud total
	while (enviados < len) {
		longEnviada = len - enviados;
		send(socket, &(longEnviada), sizeof(int), 0);
		//ENTREGA3 CHEQUEAR ESTO PORQUE NO ESTA PROBADO.
		enviados += send(socket, envio.str().substr(enviados, len).c_str(), longEnviada, 0);
		if (enviados < 0)
		{
			ManejadorErrores::manejarWriteError(errno);
		}
		//TODO CHEQUEAR ERRNO PARA VER QUE ACCION TOMAR:   http://www.cisco.com/en/US/docs/ios/sw_upgrades/interlink/r2_0/unpremsg/mucsock.html
		if (enviados == -1) {
			throw SerializacionException("No se pudo enviar el mensaje al host");
		}
	}
}

void Serializador::escribir(NetworkMensaje* msj, int socket) {
	list<NetworkMensaje*> lista;
	lista.push_back(msj);
	this->escribir(lista, socket);
}
