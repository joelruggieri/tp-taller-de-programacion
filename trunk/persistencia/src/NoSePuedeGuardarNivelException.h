/*
 * NoSePuedeGuardarNivelException.h
 *
 *  Created on: 04/11/2013
 *      Author: joel
 */

#ifndef NOSEPUEDEGUARDARNIVELEXCEPTION_H_
#define NOSEPUEDEGUARDARNIVELEXCEPTION_H_
#include <exception>

class NoSePuedeGuardarNivelException: public std::exception {
public:
	NoSePuedeGuardarNivelException();
};

#endif /* NOSEPUEDEGUARDARNIVELEXCEPTION_H_ */
