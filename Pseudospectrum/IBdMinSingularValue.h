#pragma once
#include "Matrix.h"


class IBdMinSingularValue {

public:

	virtual double MinSingularValue(BdMatrixD matrix) = 0;

};