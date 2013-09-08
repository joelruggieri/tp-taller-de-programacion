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

class logger_test: public testing::Test {
protected:
	Logger l;
public:
	virtual void SetUp() {

	}
	logger_test(): l("test.log") {}
};

#endif /* LOGGER_TEST_H_ */

TEST_F(logger_test, test_logger) {
	l.setNivel(3);
	l.error("Prueba del logger");
}
