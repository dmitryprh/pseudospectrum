#pragma once

#include "Matrix.h"

class IReader {

public:

	virtual MatrixD ReadD() = 0;
	virtual MatrixZ ReadZ() = 0;

};