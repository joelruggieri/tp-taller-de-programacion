/*
 * CargadorDeSonidos.h
 *
 *  Created on: 21/11/2013
 *      Author: joel
 */

#ifndef CARGADORDESONIDOS_H_
#define CARGADORDESONIDOS_H_
#include <map>
#include <utility>
#include <string>
#include <SDL2/SDL_mixer.h>
using namespace std;
namespace CLIENTE{

class CargadorDeSonidos {
private:
	static CargadorDeSonidos* pinstance;
	map<int,Mix_Chunk*> sonidos;
	CargadorDeSonidos();
public:
	//CargadorDeSonidos();
	~CargadorDeSonidos();
	bool cargarSonido(int id , string ruta);
	static CargadorDeSonidos* Instance();
	//ENTREGA3 TENER CUIDADO QUE ESTO DEVUELVE NULL EN CASO DE NO ENCONTRAR EL ID
	Mix_Chunk* getSonido(int id);
};
}

#endif /* CARGADORDESONIDOS_H_ */
