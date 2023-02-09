// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include "src/headers/BMPController.h"

int main() {
    std::string file = "input.bmp";

    Controller::BMPController bmpController(file);

    bmpController.run();

    return 0;
}
