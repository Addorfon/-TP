//
// Created by 89026 on 14.10.2024.
//

#include "VolumeFigure.h"

VolumeFigure::VolumeFigure() : Figure(), volume(0) {
    std::cout << "VolumeFigure default constructor called" << std::endl;
}

VolumeFigure::VolumeFigure(const std::string& type, double size, double volume)
        : Figure(type, size), volume(volume) {
    std::cout << "VolumeFigure parameterized constructor called" << std::endl;
}

VolumeFigure::~VolumeFigure() {
    std::cout << "VolumeFigure destructor called" << std::endl;
}

void VolumeFigure::draw() const {
    std::cout << "Drawing VolumeFigure: " << type << ", Size: " << size << ", Volume: " << volume << std::endl;
}

double VolumeFigure::getVolume() const {
    return volume;
}

double VolumeFigure::getArea() const {
    return 0; // Volume figures do not have a defined area
}

void VolumeFigure::setVolume(double volume) {
    this->volume = volume;
}
