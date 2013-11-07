/*
 * SerializacionException.h
 *
 *  Created on: 01/11/2013
 *      Author: jonathan
 */

#ifndef CONEXIONEXCEPTION_H_
#define CONEXIONEXCEPTION_H_

#include <exception>
#include <string>
class ConexionException: public std::exception {
private:
    std::string message_;
public:
	ConexionException(const std::string& message){
		this->message_ = message;
	}
    virtual const char* what() const throw() {
        return message_.c_str();
    }
	virtual ~ConexionException() throw(){

	}
};

#endif /* CONEXIONEXCEPTION_H_ */

