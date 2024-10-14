//
// Created by 89026 on 14.10.2024.
//

#include "Figure.h"

Figure::Figure() {
    std::cout << "Figure default constructor called" << std::endl;
}

Figure::Figure(const std::string& type, double size) : type(type), size(size) {
    std::cout << "Figure parameterized constructor called" << std::endl;
}

Figure::~Figure() {
    std::cout << "Figure destructor called" << std::endl;
}

std::string Figure::getType() const {
    return type;
}

double Figure::getSize() const {
    return size;
}

void Figure::setType(const std::string& type) {
    this->type = type;
}

void Figure::setSize(double size) {
    this->size = size;
}
