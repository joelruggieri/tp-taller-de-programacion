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

int main(int arg, char** argv) {
	LOG::LoggingService loggingService;
	string ip ;
	if (arg == 1) ip = "0";
	else
	ip = argv[1];
	MainClienteThread main(ip);
	main.run();
}
