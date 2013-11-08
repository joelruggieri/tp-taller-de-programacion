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
	int getHp() const;
	void setHp(int hp);
	int getWp() const;
	void setWp(int wp);
	int getXp() const;
	void setXp(int xp);
	int getYp() const;
	void setYp(int yp);

	float getHl() const {
		return hl;
	}

	void setHl(float hl) {
		this->hl = hl;
	}

	float getWl() const {
		return wl;
	}

	void setWl(float wl) {
		this->wl = wl;
	}

	float getXl() const {
		return xl;
	}

	void setXl(float xl) {
		this->xl = xl;
	}

	float getYl() const {
		return yl;
	}

	void setYl(float yl) {
		this->yl = yl;
	}
};

}
#endif /* VIEW_H_ */
