#pragma once

#include "IBidiagonalize.h"


class GebrdBidiagonalize : IBidiagonalize {

public:
	BdMatrixD BidiagonalizeD(MatrixD matrix);
	BdMatrixD BidiagonalizeZ(MatrixZ matrix);
};