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
	CreacionMsj(string tag, float x, float y);
	virtual ~CreacionMsj();
	void acept(UserEventVisitor *);
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator & it);

	const string& getTagObjeto() const {
		return tagObjeto;
	}

	void setTagObjeto(const string& tagObjeto) {
		this->tagObjeto = tagObjeto;
	}

	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);

private:
	string tagObjeto;
	float x,y;

};

#endif /* CREACIONMSJ_H_ */
