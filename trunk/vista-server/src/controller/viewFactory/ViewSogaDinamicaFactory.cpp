#include "ViewSogaDinamicaFactory.h"
#include "../../vista/objeto/SogaView.h"
#include "../../ConstantesVista.h"

ViewSogaDinamicaFactory::ViewSogaDinamicaFactory(EditorUnion* editor): ViewFiguraFactory(editor) {


}

FiguraView* ViewSogaDinamicaFactory::crear(float x, float y){
	return new SogaView(x, y,(EditorUnion*) this->controller);
}

ViewSogaDinamicaFactory::~ViewSogaDinamicaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewSogaDinamicaFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewSogaDinamicaFactory::getTagRemoto() {
	//esta factory no puede ser remota
	return "";
}
