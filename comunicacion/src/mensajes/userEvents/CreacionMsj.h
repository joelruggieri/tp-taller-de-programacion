/*
 * CreacionMsj.h
 *
 *  Created on: 08/11/2013
 *      Author: ezequiel
 */

#ifndef CREACIONMSJ_H_
#define CREACIONMSJ_H_
#include "UserEventMsj.h"
#include "UserEventVisitor.h"
class CreacionMsj : public UserEventMsj {
public:
	CreacionMsj(string tag);
	virtual ~CreacionMsj();
	void acept(UserEventVisitor *);
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);

	const string& getTagObjeto() const {
		return tagObjeto;
	}

	void setTagObjeto(const string& tagObjeto) {
		this->tagObjeto = tagObjeto;
	}

private:
	string tagObjeto;

};

#endif /* CREACIONMSJ_H_ */
