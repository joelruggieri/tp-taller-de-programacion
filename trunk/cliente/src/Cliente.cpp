//============================================================================
// Name        : Cliente.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "clientethread/MainClienteThread.h"
#include "src/LoggingService.h"
using namespace std;

int main() {
	LOG::LoggingService loggingService;
	MainClienteThread main;
	main.run();
}
