/*
 * ViewConFondo.h
 *
 *  Created on: 22/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCONFONDO_H_
#define VIEWCONFONDO_H_
#include "View.h"
namespace CLIENTE {
class ViewConFondo: public View {
private:
	View *decorable;
public:
	ViewConFondo(View *);
	virtual ~ViewConFondo();
	virtual void dibujarse(SDL_Renderer*);
	virtual void dibujarse(SDL_Renderer*, SDL_Rect&);
	void resizear();
	//desplaza la vista en x y en y;
	void desplazarCentroA(int x, int y);
};
}
#endif /* VIEWCONFONDO_H_ */
