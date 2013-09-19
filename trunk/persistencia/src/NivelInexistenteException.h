/*
 * NivelInexistenteException.h
 *
 *  Created on: 19/09/2013
 *      Author: jonathan
 */

#ifndef NIVELINEXISTENTEEXCEPTION_H_
#define NIVELINEXISTENTEEXCEPTION_H_

#include <exception>

class NivelInexistenteException: public std::exception {
public:
	NivelInexistenteException();
};

#endif /* NIVELINEXISTENTEEXCEPTION_H_ */
