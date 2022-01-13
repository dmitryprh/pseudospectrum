#pragma once

#include <string>

#include "IReader.h"


class TextFileReader : IReader {

	std::string _path;
public:

	TextFileReader(std::string path);
	MatrixD ReadD();
	MatrixZ ReadZ();

};
