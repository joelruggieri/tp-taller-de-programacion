/*
 * FactoryParam.h
 *
 *  Created on: 05/11/2013
 *      Author: joel
 */

#ifndef FACTORYPARAM_H_
#define FACTORYPARAM_H_
#include <string>

class FactoryParam {
private:
	int cantDisponible;
	std::string nombre;
public:
	FactoryParam();
	FactoryParam(const FactoryParam&);
	void setNombre(std::string nombre);
	std::string getNombre() const;
	void setCantidad(int numero);
	int getCantidad() const;
	virtual ~FactoryParam();
};

#endif /* FACTORYPARAM_H_ */
