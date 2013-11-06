#include "Dibujable.h"
namespace CLIENTE {
bool comparar_layers(Dibujable * first,
		Dibujable * second) {
	return first->getLayer() < second->getLayer();
}
}
