/*
 * SerializacionException.cpp
 *
 *  Created on: 01/11/2013
 *      Author: jonathan
 */

#include "SerializacionException.h"


SerializacionException::SerializacionException(const std::string& message) {
	this->message_ = message;
}

SerializacionException::~SerializacionException() throw () {
}
