//
// Created by 89026 on 14.10.2024.
//

#include "FlatFigure.h"

FlatFigure::FlatFigure() : Figure(), area(0) {
    std::cout << "FlatFigure default constructor called" << std::endl;
}

FlatFigure::FlatFigure(const std::string& type, double size, double area)
        : Figure(type, size), area(area) {
    std::cout << "FlatFigure parameterized constructor called" << std::endl;
}

FlatFigure::~FlatFigure() {
    std::cout << "FlatFigure destructor called" << std::endl;
}

void FlatFigure::draw() const {
    std::cout << "Drawing FlatFigure: " << type << ", Size: " << size << ", Area: " << area << std::endl;
}

double FlatFigure::getArea() const {
    return area;
}

double FlatFigure::getVolume() const {
    return 0; // Flat figures have no volume
}

void FlatFigure::setArea(double area) {
    this->area = area;
}

