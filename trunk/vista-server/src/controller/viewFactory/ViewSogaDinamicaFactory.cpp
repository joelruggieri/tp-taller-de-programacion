#include "ViewSogaDinamicaFactory.h"
#include "../../vista/objeto/SogaView.h"
#include "../../ConstantesVista.h"

ViewSogaDinamicaFactory::ViewSogaDinamicaFactory(EditorUnion* editor): ViewFiguraFactory(editor) {


}

FiguraView* ViewSogaDinamicaFactory::crear(float x, float y, float w, float h){
	return new SogaView(x, y,(EditorUnion*) this->controller);
}

ViewSogaDinamicaFactory::~ViewSogaDinamicaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewSogaDinamicaFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}
