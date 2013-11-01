/*
 * ThredStatus.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "Status.h"
//#include <ratio>
//using namespace std;
//using namespace chrono;
//Status::Status(int timeout): puntoControl(chrono::duration<int>(1)){
//	this->timeout = timeout;
//};
bool Status::isAlive() {
//     int transcurrido = duration_cast<milliseconds>(system_clock::now() - puntoControl).count();
//	return transcurrido < this->timeout;
return true;
}
//
//void Status::refresh() {
//	puntoControl = system_clock::now();
//}
//
//Status::~Status() {
//	// TODO Auto-generated destructor stub
//}

