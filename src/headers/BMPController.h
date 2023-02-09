// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#ifndef BMP_CONVERTER_BMPCONTROLLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include "BMPModels.h"
#include "BMPViews.h"

namespace Controller {
    class BMPController {
    private:
        Models::BMPModels bmpModels;
        View::BMPViews bmpViews;

    public:
        explicit BMPController(std::string _file);

        void run();
    };
}

#endif
