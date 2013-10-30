#include "ViewCorreaDinamicaFactory.h"
#include "../../vista/objeto/CorreaView.h"
#include "../../ConstantesVista.h"

ViewCorreaDinamicaFactory::ViewCorreaDinamicaFactory(EditorUnion* editor): ViewFiguraFactory(editor) {


}

FiguraView* ViewCorreaDinamicaFactory::crear(float x, float y, float w, float h){
	return new CorreaView(x, y,(EditorUnion*) this->controller);
}

ViewCorreaDinamicaFactory::~ViewCorreaDinamicaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaDinamicaFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}

