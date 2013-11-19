/*
 * ConfiguracionNivelMsj.h
 *
 *  Created on: 07/11/2013
 *      Author: joel
 */

#ifndef CONFIGURACIONNIVELMSJ_H_
#define CONFIGURACIONNIVELMSJ_H_
#include "NetworkMensaje.h"

class ConfiguracionNivelMsj: public NetworkMensaje {
	std::list<std::string> factoriesTags;
	float xArea, yArea, anchoArea, altoArea;
	string objetivo;

public:
	ConfiguracionNivelMsj();
	float getXArea();
	float getYArea();
	float getAnchoArea();
	float getAltoArea();
	void setXArea(float x);
	void setYArea(float y);
	void setAnchoArea(float ancho);
	void setAltoArea(float alto);
	void agregarTagFactory (std::string tag);
	std::list<std::string>& getFactoriresTags();
	void serialize(YAML::Emitter & out);
	NetworkMensaje* deserialize(YAML::const_iterator& it);
	void acept(MensajeVisitor *);
	virtual ~ConfiguracionNivelMsj();
	const string& getObjetivo() const;
	void setObjetivo(const string& objetivo);
};

#endif /* CONFIGURACIONNIVELMSJ_H_ */
