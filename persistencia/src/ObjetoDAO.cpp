/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"
#include <yaml-cpp/yaml.h>
#include <cstdio>
#include <iostream>
#include <fstream>

ObjetoDAO::ObjetoDAO() {
	// TODO Auto-generated constructor stub

}

ObjetoDAO::~ObjetoDAO() {
	// TODO Auto-generated destructor stub
}

bool ObjetoDAO::guardar(Objeto* objeto) {
	YAML::Node config = YAML::Load("config.yaml");

	config["objeto_pos_x"] = objeto->getPosX();
	config["objeto_pos_y"] = objeto->getPosY();

	std::ofstream fout("config.yaml");
	fout << config;
	return true;
}
