/*
 * ViewEngranajeUpdateMsj.h
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWENGRANAJEUPDATEMSJ_H_
#define VIEWENGRANAJEUPDATEMSJ_H_
#include "ViewObjetoUpdateMsj.h"
class ViewEngranajeUpdateMsj : public ViewObjetoUpdateMsj {
public:
	ViewEngranajeUpdateMsj(float, float ,float, float);
	virtual ~ViewEngranajeUpdateMsj();
	void serialize(YAML::Node * nodo);
		NetworkMensaje * deserialize(YAML::const_iterator & it);
		string getTag();
		void getMensaje();
		private:
		//	float x,y;
		float radio;
		typedef ViewObjetoUpdateMsj super;
};

#endif /* VIEWENGRANAJEUPDATEMSJ_H_ */
