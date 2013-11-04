/*
 * BalancinView.h
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#ifndef BALANCINVIEW_H_
#define BALANCINVIEW_H_


class SimpleEditorAnguloFijo;
struct SDL_Texture;
#include "ObjetoView.h"

class BalancinView: public ObjetoView {
public:
	BalancinView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~BalancinView();
	void update(ViewMsj *);
};

#endif /* BALANCINVIEW_H_ */
