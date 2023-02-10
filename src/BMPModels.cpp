// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include "headers/BMPModels.h"

int Models::BMPModels::_sizeOfBMP(int height, int width) {
    return height * width;
}

Models::BMPModels::BMPModels(std::string &_file) {
    this->_file = _file;
}

Models::BMPModels::~BMPModels() {
    delete[] _pData;
}

bool Models::BMPModels::isFile() {
    std::ifstream input(_file, std::ios::binary);

    if (!input.is_open()) {
        std::cout << "File can not be opened!" << std::endl;
        return false;
    }

    input.read(header, STREAM_SIZE);

    _height = *(int *) &header[HEIGHT_BUFFER];
    _width = *(int *) &header[WIDTH_BUFFER];

    _size = _sizeOfBMP(_height, _width);

    _pData = new unsigned char[_size];

    input.read((char *) _pData, _size);

    input.close();

    return true;
}

void Models::BMPModels::convertFrom8To1Bit() {
    for (int i = 0; i < _size; i++) {
        *(_pData + i) = (*(_pData + i) & CV_8S_MAX) ? CV_8U_MAX : CV_8U_MIN;
    }
}

void Models::BMPModels::writeToOutputFile() {
    std::ofstream output("output.bmp", std::ios::binary);

    output.write(header, STREAM_SIZE);
    output.write((char *) _pData, _size);

    output.close();
}