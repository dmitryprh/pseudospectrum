#pragma once

#include <complex>
#include <vector>

enum class MatrixLayout {
	ROW_MAJOR = 0,
	COLUMN_MAJOR = 1
};

enum class Bidiagonal {
	UPPER = 0,
	LOWER = 1
};


struct MatrixD {
	MatrixLayout layout;
	int rows;
	int columns;
	std::vector<double> matrix;
};

struct MatrixZ {
	MatrixLayout layout;
	int rows;
	int columns;
	std::vector<std::complex<double>> matrix;
};

struct BdMatrixD {
	Bidiagonal bidiagonal;
	int order;
	std::vector<double> diagonal;
	std::vector<double> superdiagonal;
};
