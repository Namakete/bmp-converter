// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include "headers/BMPController.h"

Controller::BMPController::BMPController(std::string _file) : bmpModels(_file) {}

void Controller::BMPController::run() {
    if (bmpModels.isFile()) {
        bmpModels.convertFrom8To1Bit();
        bmpModels.writeToOutputFile();
        View::BMPViews::message();
    }
}
