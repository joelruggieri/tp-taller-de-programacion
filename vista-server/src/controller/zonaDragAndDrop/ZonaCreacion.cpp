/*
 * ZonaCreacion.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaCreacion.h"
#include "../../modelo/Cuadrado.h"
#include "../RutasArchivos.h"
ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> & factories) :
		Zona(NULL) {
	list<ViewFiguraFactory*>::iterator it = factories.begin();
	while(it != factories.end())
	{

		this->factories.insert(pair<string, ViewFiguraFactory*>((*it)->getTagRemoto(), (*it)));
		it++;
	}
}



ZonaCreacion::~ZonaCreacion() {
	std::map<string,ViewFiguraFactory*>::iterator it = this->factories.begin();
	while(it != factories.end())
	{
		it->second->~ViewFiguraFactory();
	}
}


void ZonaCreacion::dibujarse(list<NetworkMensaje*> & lista, int desti){
	map<string, ViewFiguraFactory* >::iterator it;
	ViewMsj* msj;
	for(it=factories.begin(); it!= factories.end();++it){
		msj = it->second->dibujarse(desti);
		if(msj){
			lista.push_back(msj);
		}
	}
}

FiguraView* ZonaCreacion::crearFigura(string tag, float x, float y) {
	std::map<string,ViewFiguraFactory*>::iterator it = this->factories.find(tag);
	if (it == this->factories.end()) return NULL;
	return it->second->crearTemplate(x,y);

}
