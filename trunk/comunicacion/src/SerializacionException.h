/*
 * SerializacionException.h
 *
 *  Created on: 01/11/2013
 *      Author: jonathan
 */

#ifndef SERIALIZACIONEXCEPTION_H_
#define SERIALIZACIONEXCEPTION_H_

#include <exception>
#include <string>
class SerializacionException: public std::exception {
private:
    std::string message_;
public:
	SerializacionException(const std::string& message);
    virtual const char* what() const throw() {
        return message_.c_str();
    }
	virtual ~SerializacionException() throw();
};

#endif /* SERIALIZACIONEXCEPTION_H_ */

