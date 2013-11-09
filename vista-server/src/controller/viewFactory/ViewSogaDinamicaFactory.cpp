#include "ViewSogaDinamicaFactory.h"
#include "../../vista/objeto/SogaView.h"
#include "../../ConstantesVista.h"

ViewSogaDinamicaFactory::ViewSogaDinamicaFactory(EditorUnion* editor, int cantidad): ViewFiguraFactory(editor, cantidad) {


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

ViewFiguraFactory* ViewSogaDinamicaFactory::clone(int cantidad){
	EditorUnion * editor = ((EditorUnion*) this->controller);
	editor = (EditorUnion *)editor->clone();
	return new ViewSogaDinamicaFactory(editor,cantidad);
}

View* ViewSogaDinamicaFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}
