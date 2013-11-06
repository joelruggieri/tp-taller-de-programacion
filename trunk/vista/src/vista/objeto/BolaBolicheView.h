/*
 * BolaBolicheView.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef BOLABOLICHEVIEW_H_
#define BOLABOLICHEVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;
namespace CLIENTE {
class BolaBolicheView : public ObjetoView {
public:
	BolaBolicheView(int x, int y, int w, int h, SDL_Texture * textura);
	virtual ~BolaBolicheView();
	void update(ViewMsj *);
};

}
#endif /* BOLABOLICHEVIEW_H_ */
