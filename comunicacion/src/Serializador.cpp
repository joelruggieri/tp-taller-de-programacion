/*
 * Serializador.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "Serializador.h"

Serializador::Serializador() {
this->mensajes.insert(pair<char*, NetworkMensaje*>(TAG_VIEW_GLOBO, new ViewGloboUpdateMsj(0,0)));
this->mensajes.insert(pair<char*, NetworkMensaje*>(TAG_MSJ_PLANO, new MensajePlano("")));
this->mensajes.insert(pair<char*, NetworkMensaje*>(TAG_VIEW_BOLA, new ViewBolaBolicheUpdateMsj(0,0)));
this->mensajes.insert(pair<char*, NetworkMensaje*>(TAG_VIEW_PELOTA, new ViewPelotaUpdateMsj(0,0)));
this->mensajes.insert(pair<char*, NetworkMensaje*>(TAG_VIEW_PELOTA, new ViewPlataformaUpdateMsj(0,0,0)));
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
	string buffer;
	read(sock, &buffer,1024);
	string clave;
	YAML::Node lineup = YAML::Load(buffer.c_str());
	YAML::const_iterator it=lineup.begin();
	while(it != lineup.end())
	{
		it++;
		clave = it->as<string>();
		retorno.push_back(this->mensajes.find(clave)->second->deserialize(it));
	}

return retorno;
}
