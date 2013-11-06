/*
 * PlataformaView.h
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#ifndef PLATAFORMAVIEW_H_
#define PLATAFORMAVIEW_H_
#include "ObjetoView.h"
namespace CLIENTE {
class PlataformaView: public ObjetoView {
private:
	typedef FiguraView super;
public:
	PlataformaView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~PlataformaView();
	void update(ViewMsj *);
};
}
#endif /* PLATAFORMAVIEW_H_ */
