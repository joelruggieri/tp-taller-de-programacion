/*
 * Serializador.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "Serializador.h"
#include "SerializacionException.h"
#define MAX_BUFFER 1024
Serializador::Serializador() {
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_GLOBO), new ViewGloboUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_MSJ_PLANO), new MensajePlano("")));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_BOLA), new ViewBolaBolicheUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_PELOTA), new ViewPelotaUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_PLATAFORMA), new ViewPlataformaUpdateMsj(0,0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_MOTOR), new ViewMotorUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_CINTA), new ViewCintaUpdateMsj(0,0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_ENGRANAJE), new ViewEngranajeUpdateMsj(0,0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_BALANCIN), new ViewBalancinUpdateMsj(0,0,0)));
this->mensajes.insert(pair<string, NetworkMensaje*>(string(TAG_VIEW_SOGA), new ViewSogaUpdateMje(0,0,0,0)));
}

Serializador::~Serializador() {
	map<string, NetworkMensaje* >::const_iterator iter;
	for(iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter)
	{
		iter->second->~NetworkMensaje();
	}
}

list<NetworkMensaje*> Serializador::leer(int sock) {
	list<NetworkMensaje*> retorno;

//	string buffer;
	char buffer[1024] = "";
	char bufferAux[1024] = "";
	int longitudTotal;
	int longRecibida;
	int recibidos = 0;
	read(sock, &longitudTotal, sizeof(int));

	while(recibidos < longitudTotal){
	read(sock, &longRecibida, sizeof(int));
	recibidos += read(sock, &bufferAux,longRecibida);

	if (recibidos == -1) throw SerializacionException("No se pudo recibir el mensaje al host");
	strcat(buffer, bufferAux);
	}
	string clave;

	string aux = buffer;
//	cout <<  longitud << endl;
	YAML::Node lineup = YAML::Load(aux.substr(0, longitudTotal));

	YAML::const_iterator it=lineup.begin();

	while(it != lineup.end())
	{


		clave = it->as<string>();
		it++;
//		cout << clave << endl;
		retorno.push_back(this->mensajes.find(clave)->second->deserialize(it));

	}
return retorno;
}

void Serializador::escribir(list<NetworkMensaje*>& lista, int socket) {
	list<NetworkMensaje*>::iterator it = lista.begin();
	YAML::Node * nodo = new YAML::Node() ;
	stringstream envio;

	while(it != lista.end())
	{
		(*it)->serialize(nodo);
		it++;

	}
	 envio << *nodo;
	 int enviados = 0;
//	 const char * str = envio.str().c_str();
	 int len = strlen(envio.str().c_str());
	 int longEnviada;
	 send(socket, &len, sizeof(int), 0);	//envio longitud total
	 while(enviados < len){
		 longEnviada = len - enviados;
	 send(socket, &(longEnviada), sizeof(int), 0);
	 enviados += send(socket, envio.str().substr(enviados, len).c_str(), longEnviada, 0);

	 if(enviados == -1){
		 throw SerializacionException("No se pudo enviar el mensaje al host");
	 }
	 }
}

void Serializador::escribir(NetworkMensaje* msj, int socket) {
	list<NetworkMensaje*> lista;
	lista.push_back(msj);
	this->escribir(lista,socket);
}
