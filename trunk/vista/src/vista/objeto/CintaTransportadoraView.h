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
	CintaTransportadoraView(float x, float y, float w, float h,float altoModelo,int altoPlataforma, SDL_Texture * textura);
	virtual ~CintaTransportadoraView();
	void update(ViewMsj *);
	void dibujarse(SDL_Renderer*);
private:
	int xEngrIzq, xEngrDer, alto, yEngranajes,altoPlataforma;
	SDL_Texture * rueda;
	typedef ObjetoView super;
	void recalcular();
	void resizear();
	int getLayer();
};
}
#endif /* VISTACINTATRANSPORTADORA_H_ */
