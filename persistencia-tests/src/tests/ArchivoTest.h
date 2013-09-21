/*
 * ArchivoTest.h
 *
 *  Created on: 21/09/2013
 *      Author: javier
 */

#ifndef ARCHIVOTEST_H_
#define ARCHIVOTEST_H_

#include "src/Archivo.h"
#include <yaml-cpp/yaml.h>
#include <string>

using std::string;

class ArchivoTest: public testing::Test {
protected:
	Archivo *archivo;
	virtual void SetUp() {

	}
	virtual void tearDown() {
		if (archivo) {
			archivo->cerrar();
		}
	}
};

#endif /* ARCHIVOTEST_H_ */

TEST_F(ArchivoTest, test_leer_linea) {
	string nombre = "test_lectura.txt";
	archivo = new Archivo(nombre.c_str(), LECTURA);
	string linea = archivo->leer();
	EXPECT_STREQ("test lectura", linea.c_str());
}

TEST_F(ArchivoTest, test_leer_varias_lineas) {
	string nombre = "test_varias_lineas.txt";
	archivo = new Archivo(nombre.c_str(), ESCRITURA);
	archivo->escribir("linea 1");
	archivo->escribir("linea 2");
	archivo->escribir("linea 3");
	archivo->cerrar();
	archivo = new Archivo(nombre.c_str(), LECTURA);
	string linea = archivo->leer();
	EXPECT_STREQ("linea 1", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("linea 2", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("linea 3", linea.c_str());
}

TEST_F(ArchivoTest, test_crear_archivo_si_no_existe) {
	string nombre = "test_creacion.txt";
	archivo = new Archivo(nombre.c_str(), ESCRITURA);
	archivo->escribir("test creacion");
	archivo->cerrar();
	archivo = new Archivo(nombre.c_str(), LECTURA);
	string linea = archivo->leer();
	EXPECT_STREQ("test creacion", linea.c_str());
}


TEST_F(ArchivoTest, test_append) {
	string nombre = "test_append.txt";
	archivo = new Archivo(nombre.c_str(), ESCRITURA);
	archivo->escribir("linea 1");
	archivo->cerrar();
	archivo = new Archivo(nombre.c_str(), APPEND);
	archivo->escribir("linea 2 (append)");
	archivo->cerrar();
	archivo = new Archivo(nombre.c_str(), LECTURA);
	string linea = archivo->leer();
	EXPECT_STREQ("linea 1", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("linea 2 (append)", linea.c_str());
}

TEST_F(ArchivoTest, test_sobreescribir_nodo_yaml) {
	string nombre = "test_nodo.txt";
	archivo = new Archivo(nombre.c_str(), ESCRITURA);
	YAML::Node nodo;
	nodo["test"] = "dato test";
	archivo->sobreescribir(nodo);
	archivo->cerrar();
	archivo = new Archivo(nombre.c_str(), LECTURA);
	string linea = archivo->leer();
	EXPECT_STREQ("test: dato test", linea.c_str());

	//DEBUG: Para visualizar, por si borre el archivo.
//	while (!archivo->alFinal()) {
//		std::cout << "DEBUG: "<< archivo->leer();
//	}
}


TEST_F(ArchivoTest, test_sobreescribir_nodo_yaml_con_lista_de_elementos) {
	string nombre = "test_nodo_lista.txt";
	archivo = new Archivo(nombre.c_str(), ESCRITURA);
	YAML::Node nodo;
	nodo.push_back("Dato 1");
	nodo.push_back("Dato 2");
	nodo.push_back("Dato 3");
	archivo->sobreescribir(nodo);
	archivo->cerrar();
	archivo = new Archivo(nombre.c_str(), LECTURA);
	string linea = archivo->leer();
	EXPECT_STREQ("- Dato 1", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("- Dato 2", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("- Dato 3", linea.c_str());
}

TEST_F(ArchivoTest, test_actualizar_nodo_yaml) {
	string nombre = "test_nodo_actualizar.txt";
	archivo = new Archivo(nombre.c_str(), ESCRITURA);
	YAML::Node nodo, nodoRaiz;
	nodo.push_back("Dato 1");
	nodo.push_back("Dato 2");
	nodo.push_back("Dato 3");
	nodoRaiz["Datos"] = nodo;
	archivo->sobreescribir(nodoRaiz);
	archivo->cerrar();

	// Leer el primer estado del archivo
	archivo = new Archivo(nombre.c_str(), LECTURA);
	string linea = archivo->leer();
	EXPECT_STREQ("Datos:", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("  - Dato 1", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("  - Dato 2", linea.c_str());
	linea = archivo->leer();
	EXPECT_STREQ("  - Dato 3", linea.c_str());
	archivo->cerrar();

	// Levantar el nodo y modificarlo
	archivo = new Archivo(nombre.c_str(), LECTOESCRITURA);
	nodoRaiz = archivo->obtenerNodoRaiz();
	nodo = nodoRaiz["Datos"];
	EXPECT_TRUE( nodo.IsSequence() );
	EXPECT_EQ( nodo.size(), 3 );
	nodo.push_back("Dato 4");
	archivo->sobreescribir(nodoRaiz);
	archivo->cerrar();

	// Leer y comprobar el nodo modificado
	archivo = new Archivo(nombre.c_str(), LECTURA);
	nodoRaiz = archivo->obtenerNodoRaiz();
	nodo = nodoRaiz["Datos"];
	EXPECT_TRUE( nodo.IsSequence() );
	EXPECT_EQ( nodo.size(), 4 );
	EXPECT_STREQ(nodo[0].as<string>().c_str(), "Dato 1");
	EXPECT_STREQ(nodo[1].as<string>().c_str(), "Dato 2");
	EXPECT_STREQ(nodo[2].as<string>().c_str(), "Dato 3");
	EXPECT_STREQ(nodo[3].as<string>().c_str(), "Dato 4");
}
