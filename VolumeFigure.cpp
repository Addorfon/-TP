#include "VolumeFigure.h"

VolumeFigure::VolumeFigure() : Figure(), volume(0) {
    std::cout << "VolumeFigure default constructor called" << std::endl;
    int x1, y1, z1;
    std::cout << "Enter x y z: ";
    std::cin >> x1 >> y1 >> z1;
    setX(x1);
    setY(y1);
    setZ(z1);
    if (type == "Cube" || type == "Parallelogram") {
        volume = x * y * z;
    } else if (type == "Pyramid") {
        volume = 0.333 * x * y * z;
    }
}

VolumeFigure::VolumeFigure(const std::string& type, double x, double y, double z)
        : Figure(type), x(x), y(y), z(z) {
    if (x < 0) {
        throw std::invalid_argument("Y cannot be negative");
    }
    else if (y < 0) {
        throw std::invalid_argument("Y cannot be negative");
    }
    else if(z < 0){
        throw std::invalid_argument("Z cannot be negative");
    }
    std::cout << "VolumeFigure parameterized constructor called" << std::endl;
    if (type != "Cube" && type != "Parallelogram" && type != "Pyramid"){
        throw std::invalid_argument("Sorry, but idk this type Figure");
    }
    if (type == "Cube" || type == "Parallelogram") {
        volume = x * y * z;
    } else if (type == "Pyramid") {
        volume = 0.333 * x * y * z;
    }
}

VolumeFigure::~VolumeFigure() {
    std::cout << "VolumeFigure destructor called" << std::endl;
}

void VolumeFigure::draw() const {
    std::cout << "Drawing VolumeFigure: " << type << ", Size: x - " << x << " y - " << y << " z - " << z << ", Volume: " << volume << std::endl;
}

double VolumeFigure::getArea() const {
    return 0; // Volume figures do not have a defined area
}

void VolumeFigure::setX(double x) {
    if (x < 0) {
        throw std::invalid_argument("X cannot be negative");
    }
    this->x = x;
}

void VolumeFigure::setY(double y) {
    if (y < 0) {
        throw std::invalid_argument("Y cannot be negative");
    }
    this->y = y;
}

void VolumeFigure::setZ(double z) {
    if (z < 0) {
        throw std::invalid_argument("Z cannot be negative");
    }
    this->z = z;
}

void VolumeFigure::setSize(double x, double y, double z) {
    setX(x);
    setY(y);
    setZ(z);
    if (type == "Cube" || type == "Parallelogram") {
        volume = x * y * z;
    } else if (type == "Pyramid") {
        volume = 0.333 * x * y * z;
    }
}

double VolumeFigure::getX() const {
    return x;
}

double VolumeFigure::getY() const {
    return y;
}

double VolumeFigure::getZ() const {
    return z;
}

double VolumeFigure::getVolume() const {
    return volume;
}
