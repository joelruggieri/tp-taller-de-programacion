/*
 * PelotaJuegoView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef PELOTAJUEGOVIEW_H_
#define PELOTAJUEGOVIEW_H_
#include "ObjetoView.h"

namespace CLIENTE {

class PelotaJuegoView : public ObjetoView {
public:
	PelotaJuegoView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~PelotaJuegoView();
	void update(ViewMsj *);
};
}
#endif /* PELOTAJUEGOVIEW_H_ */
