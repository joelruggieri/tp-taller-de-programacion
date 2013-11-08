/*
 * PlataformaView.h
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#ifndef PLATAFORMAVIEW_H_
#define PLATAFORMAVIEW_H_
#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
namespace CLIENTE {
class PlataformaView: public ObjetoView {
private:
	typedef FiguraView super;
public:
	PlataformaView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~PlataformaView();
	void update(ViewMsj *);
};
}
#endif /* PLATAFORMAVIEW_H_ */
