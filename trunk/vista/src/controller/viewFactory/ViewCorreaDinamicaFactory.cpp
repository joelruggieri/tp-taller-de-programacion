#include "ViewCorreaDinamicaFactory.h"
#include "../../vista/objeto/CorreaView.h"
#include "../../ConstantesVista.h"

ViewCorreaDinamicaFactory::ViewCorreaDinamicaFactory(EditorUnion* editor): ViewFiguraFactory(PATH_VISTA_CORREA,editor) {


}

FiguraView* ViewCorreaDinamicaFactory::crear(int x,int y,int w, int h){
	return new CorreaView(x, y,this->textura, (EditorUnion*) this->controller);
}

ViewCorreaDinamicaFactory::~ViewCorreaDinamicaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaDinamicaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}

