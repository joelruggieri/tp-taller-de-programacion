/*
 * logger_test.h
 *
 *  Created on: 08/09/2013
 *      Author: javier
 */

#ifndef LOGGER_TEST_H_
#define LOGGER_TEST_H_

#include "gtest/gtest.h"
#include "src/Logger.h"
#include "src/AdministradorDeLoggers.h"

class logger_test: public testing::Test {
protected:
	Logger l;
public:
	virtual void SetUp() {

	}
};

#endif /* LOGGER_TEST_H_ */

TEST_F(logger_test, test_logger) {
	l.error("Prueba del logger");
	l.debug("Prueba del logger");
	l.info("Prueba del logger");
	l.fatal("Prueba del logger");
	l.warning("Prueba del logger");

	l.error("Prueba del logger");
	l.debug("Prueba del logger");
	l.info("Prueba del logger");
	l.fatal("Prueba del logger");
	l.warning("Prueba del logger");

	l.error("Prueba del logger");
	l.debug("Prueba del logger");
	l.info("Prueba del logger");
	l.fatal("Prueba del logger");
	l.warning("Prueba del logger");

	AdministradorDeLoggers::cerrarTodo();
}
