/*
 * CintaTransportadoraView.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VISTACINTATRANSPORTADORA_H_
#define VISTACINTATRANSPORTADORA_H_

#include "ObjetoView.h"
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
namespace CLIENTE {
class CintaTransportadoraView: public ObjetoView {
public:
	CintaTransportadoraView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura);
	virtual ~CintaTransportadoraView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer*);
private:
	float xizql, xderl, xmedl;
	int xizqp, xderp, radiop, altocintal, xmedp;
	float altocintap;
	typedef ObjetoView super;
	SDL_Texture * rueda;
	void recalcular();
	void resizear();
};
}
#endif /* VISTACINTATRANSPORTADORA_H_ */
