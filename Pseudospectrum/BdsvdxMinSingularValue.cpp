#include "mkl.h"

#include "BdsvdxMinSingularValue.h"


double BdsvdxMinSingularValue::MinSingularValue(BdMatrixD matrix) {

	char uplo = matrix.bidiagonal == Bidiagonal::LOWER ? 'L' : 'U';

	int ns = 0;
	double* singular_values = new double[matrix.order];

	int* superb = new int[12 * (long long)matrix.order];

	int info = LAPACKE_dbdsvdx(LAPACK_ROW_MAJOR, uplo, 'N', 'I', matrix.order, matrix.diagonal.data(), matrix.superdiagonal.data(), 
		0, 0, matrix.order, matrix.order, &ns, singular_values, NULL, 0, superb);

	return singular_values[0];
}