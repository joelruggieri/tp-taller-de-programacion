#include "ViewCorreaDinamicaFactory.h"
#include "../../vista/objeto/CorreaView.h"
#include "../../ConstantesVista.h"

ViewCorreaDinamicaFactory::ViewCorreaDinamicaFactory(EditorUnion* editor, int cantidad): ViewFiguraFactory(editor, cantidad,ID_FACTORY_CORREA) {


}

FiguraView* ViewCorreaDinamicaFactory::crear(float x, float y){
	return new CorreaView(x, y,(EditorUnion*) this->controller);
}

ViewCorreaDinamicaFactory::~ViewCorreaDinamicaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaDinamicaFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewCorreaDinamicaFactory::getTagRemoto() {
	//esta factory no sirve para las zonas de creacion asi que el tag remoto no aplica para esta
	return "";
}

ViewFiguraFactory* ViewCorreaDinamicaFactory::clone(int cantidad){
	EditorUnion * editor = ((EditorUnion*) this->controller);
	editor = (EditorUnion *)editor->clone();
	return new ViewCorreaDinamicaFactory(editor,cantidad);
}

View * ViewCorreaDinamicaFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}
