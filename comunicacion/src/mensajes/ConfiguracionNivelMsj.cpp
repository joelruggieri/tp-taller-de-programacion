/*
 * ConfiguracionNivelMsj.cpp
 *
 *  Created on: 07/11/2013
 *      Author: joel
 */

#include "ConfiguracionNivelMsj.h"

ConfiguracionNivelMsj::ConfiguracionNivelMsj() {
	// TODO Auto-generated constructor stub

}

float ConfiguracionNivelMsj::getXArea(){
	return this->xArea;
}
float ConfiguracionNivelMsj::getYArea(){
	return this->yArea;
}
float ConfiguracionNivelMsj::getAnchoArea(){
	return this->anchoArea;
}

float ConfiguracionNivelMsj::getAltoArea(){
	return this->altoArea;
}

void ConfiguracionNivelMsj::setXArea(float x){
	this->xArea = x;
}

void ConfiguracionNivelMsj::setYArea(float y){
	this->yArea = y;
}

void ConfiguracionNivelMsj::setAnchoArea(float ancho){
	this->anchoArea = ancho;
}

std::list<std::string>& ConfiguracionNivelMsj::getFactoriresTags(){
	return this->factoriesTags;
}

void ConfiguracionNivelMsj::setAltoArea(float alto){
	this->altoArea = alto;
}

void ConfiguracionNivelMsj::agregarTagFactory (std::string tag){
	this->factoriesTags.push_back(tag);
}

void ConfiguracionNivelMsj::serialize(YAML::Emitter & out){
	out << MSJ_CONFIG_JUGADOR;
	out << this->getXArea();
	out << this->getYArea();
	out << this->getAnchoArea();
	out << this->getAltoArea();
	out << this->getFactoriresTags().size();
	std::list<std::string>::iterator iterador;
	for (iterador = this->getFactoriresTags().begin(); iterador != this->getFactoriresTags().end(); ++iterador){
		out << *iterador;
	}
}

NetworkMensaje* ConfiguracionNivelMsj::deserialize(YAML::const_iterator& it) {
	float xArea = it->as<float>();
	it++;
	float yArea = it->as<float>();
	it++;
	float anchoArea = it->as<float>();
	it++;
	float altoArea = it->as<float>();
	it++;
	int cantTags = it->as<size_t>();
	it++;

	std::string tag;
	ConfiguracionNivelMsj * salida = new ConfiguracionNivelMsj();
	salida->setXArea(xArea);
	salida->setYArea(yArea);
	salida->setAnchoArea(anchoArea);
	salida->setAltoArea(altoArea);
	for(int i=0 ; i < cantTags; i++){
		tag = it->as<std::string>();
		salida->agregarTagFactory(tag);
		it++;
	}
	return salida;
}

void ConfiguracionNivelMsj::acept(MensajeVisitor* v) {

}

ConfiguracionNivelMsj::~ConfiguracionNivelMsj() {
	// TODO Auto-generated destructor stub
}

