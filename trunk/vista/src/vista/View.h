/*
 * View.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEW_H_
#define VIEW_H_
#include "Dibujable.h"
#include "Resizeable.h"
#include "../controller/Resizer.h"
#include "src/mensajes/viewMensaje/ViewMsj.h"
#include "../modelo/Observer.h"
#include "../modelo/Observable.h"

namespace CLIENTE {
class View : public Dibujable, public Resizeable{
protected:
	int wp,hp;
	int xp, yp;
	float xl,yl,wl,hl;
public:
	View(float x, float y, float w, float h);
	virtual ~View();
	virtual void dibujarse(SDL_Renderer*)=0;
	virtual void dibujarse(SDL_Renderer*, SDL_Rect&)=0;
	virtual void resizear();
	virtual void update(ViewMsj *) = 0;
	virtual void setYL(float yl);
	virtual float getYL();
};

}
#endif /* VIEW_H_ */
