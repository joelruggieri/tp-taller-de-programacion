/*
 * Sogaview.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef SOGAVIEW_H_
#define SOGAVIEW_H_
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "UnionView.h"
#include <SDL2/SDL_mixer.h>
namespace CLIENTE {

class SogaView: public UnionView {
public:
	SogaView(float xDesde, float yDesde,float xHasta, float yHasta,int numeroEvent,SDL_Texture * textura);
	virtual ~SogaView();
	void dibujarse(SDL_Renderer * renderer);
	void update(ViewMsj*);
	void resizear();
	void setPosEslabonL(float, float);
private:
	SDL_Texture * texturaEslabon;
	typedef UnionView super;
	float xEslabonl, yEslabonl;
	int xEslabonp,xEslabonDibp , yEslabonp,yEslabonDibp, anchoEslabonP;
	bool primerTramo, segundoTramo;
	Mix_Chunk* sonido;
};
}
#endif /* SOGAVIEW_H_ */
