#include "FlatFigure.h"

FlatFigure::FlatFigure() : Figure(), area(0) {
    std::cout << "FlatFigure default constructor called" << std::endl;
    int x1, y1;
    std::cout << "Enter x y: ";
    std::cin >> x1 >> y1;
    setX(x1);
    setY(y1);
    if (type == "Square" || type == "Rectangle" || type == "Parallelepiped") {
        area = x * y;
    } else if (type == "Triangle") {
        area = 0.5 * x * y;
    }
}

FlatFigure::FlatFigure(const std::string& type, double x, double y)
        : Figure(type), x(x), y(y) {
    std::cout << "FlatFigure parameterized constructor called" << std::endl;
    if (x < 0) {
        throw std::invalid_argument("Y cannot be negative");
    }
    else if (y < 0) {
        throw std::invalid_argument("Y cannot be negative");
    }
    if (type != "Square" && type != "Rectangle" && type != "Parallelepiped" && type != "Triangle"){
        throw std::invalid_argument("Sorry, but idk this type Figure");
    }
    if (type == "Square" || type == "Rectangle" || type == "Parallelepiped") {
        area = x * y;
    } else if (type == "Triangle") {
        area = 0.5 * x * y;
    }
}

FlatFigure::~FlatFigure() {
    std::cout << "FlatFigure destructor called" << std::endl;
}

void FlatFigure::draw() const {
    std::cout << "Drawing FlatFigure: " << type << ", Size: x - " << x << " y - " << y << ", Area: " << area << std::endl;
}

double FlatFigure::getArea() const {
    return area;
}

double FlatFigure::getVolume() const {
    return 0; // Flat figures have no volume
}

void FlatFigure::setX(double x) {
    if (x < 0) {
        throw std::invalid_argument("X cannot be negative");
    }
    this->x = x;
}

void FlatFigure::setY(double y) {
    if (y < 0) {
        throw std::invalid_argument("Y cannot be negative");
    }
    this->y = y;
}

void FlatFigure::setSize(double x, double y) {
    setX(x);
    setY(y);
    if (type == "Square" || type == "Rectangle" || type == "Parallelepiped") {
        area = x * y;
    } else if (type == "Triangle") {
        area = 0.5 * x * y;
    }
}

double FlatFigure::getX() const {
    return x;
}

double FlatFigure::getY() const {
    return y;
}
