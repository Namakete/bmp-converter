// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#ifndef BMP_CONVERTER_BMPMODELS_H

#define STREAM_SIZE 54
#define HEIGHT_BUFFER 22
#define WIDTH_BUFFER 18
#define CV_8S_MAX 0x80
#define CV_8U_MAX 0xFF
#define CV_8U_MIN 0x00

#include <iostream>
#include <fstream>
#include <string>

namespace Models {
    class BMPModels {
    private:
        std::string _file;
        int _height{};
        int _width{};
        int _size{};
        unsigned char *_pData = nullptr;
        char header[STREAM_SIZE]{};

        static int _sizeOfBMP(int height, int WIDTH);

    public:
        explicit BMPModels(std::string &_file);

        ~BMPModels();

        bool isFile();

        void convertFrom8To1Bit();

        void writeToOutputFile();
    };
}

#endif
