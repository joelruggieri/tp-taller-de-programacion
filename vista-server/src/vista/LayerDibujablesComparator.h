#include "Dibujable.h"

bool comparar_layers(Dibujable * first,
		Dibujable * second) {
	return first->getLayer() < second->getLayer();
}
