#include <fstream>

#include "TextFileReader.h"



TextFileReader::TextFileReader(std::string path): _path(path) {}

MatrixD TextFileReader::ReadD() {

	MatrixD result;
	result.layout = MatrixLayout::ROW_MAJOR;

	std::ifstream fin(_path);
	fin >> result.rows >> result.columns;
	long long size = (long long)result.rows * result.columns;
	result.matrix = std::vector<double>(size);
	
	for (long long i = 0; i < size; ++i) {
		fin >> result.matrix[i];
	}

	fin.close();

	return result;
}

MatrixZ TextFileReader::ReadZ() {

	MatrixZ result;
	result.layout = MatrixLayout::ROW_MAJOR;

	std::ifstream fin(_path);
	fin >> result.rows >> result.columns;
	long long size = (long long)result.rows * result.columns;
	result.matrix = std::vector<std::complex<double>>(size);

	for (long long i = 0; i < size; ++i) {
		double real, imag;
		fin >> real >> imag;
		result.matrix[i] = { real, imag };
	}

	fin.close();

	return result;
}