#include "ViewSogaDinamicaFactory.h"
#include "../../vista/objeto/SogaView.h"
#include "../../ConstantesVista.h"

ViewSogaDinamicaFactory::ViewSogaDinamicaFactory(EditorUnion* editor): ViewFiguraFactory(PATH_VISTA_CORREA,editor) {


}

FiguraView* ViewSogaDinamicaFactory::crear(int x,int y,int w, int h){
	return new SogaView(x, y,this->textura, (EditorUnion*) this->controller);
}

ViewSogaDinamicaFactory::~ViewSogaDinamicaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewSogaDinamicaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
