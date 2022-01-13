#include "mkl.h"

#include "GebrdBidiagonalize.h"
#include "Macros.h"



BdMatrixD GebrdBidiagonalize::BidiagonalizeD(MatrixD matrix) {

	int order = min(matrix.rows, matrix.columns);
	BdMatrixD result = {
		matrix.rows >= matrix.columns ? Bidiagonal::UPPER : Bidiagonal::LOWER,
		order,
		std::vector<double>(order),
		std::vector<double>(order - 1)
	};


	int layout = matrix.layout == MatrixLayout::ROW_MAJOR ? LAPACK_ROW_MAJOR : LAPACK_COL_MAJOR;
	int leading_dimension = matrix.layout == MatrixLayout::ROW_MAJOR ? matrix.columns : matrix.rows;

	double* tauq = new double[order];
	double* taup = new double[order];
	
	int info = LAPACKE_dgebrd(layout, matrix.rows, matrix.columns, matrix.matrix.data(), leading_dimension, 
		result.diagonal.data(), result.superdiagonal.data(), tauq, taup);

	delete[] tauq;
	delete[] taup;

	return result;
}


BdMatrixD GebrdBidiagonalize::BidiagonalizeZ(MatrixZ matrix) {

	int order = min(matrix.rows, matrix.columns);
	BdMatrixD result = {
		matrix.rows >= matrix.columns ? Bidiagonal::UPPER : Bidiagonal::LOWER,
		order,
		std::vector<double>(order),
		std::vector<double>(order - 1)
	};

	int layout = matrix.layout == MatrixLayout::ROW_MAJOR ? LAPACK_ROW_MAJOR : LAPACK_COL_MAJOR;
	int leading_dimension = matrix.layout == MatrixLayout::ROW_MAJOR ? matrix.columns : matrix.rows;


	MKL_Complex16* tauq = new MKL_Complex16[order];
	MKL_Complex16* taup = new MKL_Complex16[order];

	int info = LAPACKE_zgebrd(layout, matrix.rows, matrix.columns, (MKL_Complex16*)matrix.matrix.data(), leading_dimension, 
		result.diagonal.data(), result.superdiagonal.data(), tauq, taup);

	delete[] tauq;
	delete[] taup;

	return result;
}