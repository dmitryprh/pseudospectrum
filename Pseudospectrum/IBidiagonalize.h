#pragma once
#include "Matrix.h"

class IBidiagonalize {

public:

	virtual BdMatrixD BidiagonalizeD(MatrixD matrix) = 0;
	virtual BdMatrixD BidiagonalizeZ(MatrixZ matrix) = 0;

};