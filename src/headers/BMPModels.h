// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#ifndef BMP_CONVERTER_BMPMODELS_H

#define STREAM_SIZE 54

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

        static int sizeOfBMP(int height, int WIDTH);

    public:
        explicit BMPModels(std::string &_file);

        ~BMPModels();

        bool isFile();

        void convertFrom8To1Bit();

        void writeToOutputFile();
    };
}

#endif
