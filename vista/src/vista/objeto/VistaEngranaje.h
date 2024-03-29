/*
 * VistaEngranaje.h
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#ifndef VISTAENGRANAJE_H_
#define VISTAENGRANAJE_H_
	#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
namespace CLIENTE {
class VistaEngranaje: public ObjetoView {
	typedef FiguraView super;
public:
	VistaEngranaje(float x, float y, float w, float h,int numeroEvent, SDL_Texture * textura);
	virtual ~VistaEngranaje();
	void  update(ViewMsj* );
};
}
#endif /* VISTAENGRANAJE_H_ */
