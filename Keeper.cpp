#include "Keeper.h"
#include "FlatFigure.h"
#include "VolumeFigure.h"
#include <fstream>
#include <iostream>

Keeper::Keeper() {
    std::cout << "Keeper constructor called" << std::endl;
}

Keeper::~Keeper() {
    for (Figure* figure : figures) {
        delete figure;
    }
    std::cout << "Keeper destructor called" << std::endl;
}

void Keeper::addFigure(Figure* figure) {
    figures.push_back(figure);
}

void Keeper::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void Keeper::setSizeFlat(int index, double x, double y) {
    if (index >= 0 && index < figures.size()) {
        FlatFigure* flatFigure = dynamic_cast<FlatFigure*>(figures[index]);
        if (flatFigure) {
            flatFigure->setSize(x, y);
        } else {
            std::cout << "Invalid figure type" << std::endl;
        }
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void Keeper::setSizeVolume(int index, double x, double y, double z) {
    if (index >= 0 && index < figures.size()) {
        VolumeFigure* volumeFigure = dynamic_cast<VolumeFigure*>(figures[index]);
        if (volumeFigure) {
            volumeFigure->setSize(x, y, z);
        } else {
            std::cout << "Invalid figure type" << std::endl;
        }
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

std::string Keeper::returnType(int index) {
    if (index >= 0 && index < figures.size()) {
        return figures[index]->getType();
    } else {
        std::cout << "Invalid index" << std::endl;
        return "";
    }
}

void Keeper::displayFigures() const {
    for (const Figure* figure : figures) {
        figure->draw();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Figure* figure : figures) {
            if (dynamic_cast<const FlatFigure*>(figure)) {
                file << "Flat " << dynamic_cast<const FlatFigure*>(figure)->getType() << " "
                     << dynamic_cast<const FlatFigure*>(figure)->getX() << " "
                     << dynamic_cast<const FlatFigure*>(figure)->getY() << std::endl;
            } else if (dynamic_cast<const VolumeFigure*>(figure)) {
                file << "Volume " << dynamic_cast<const VolumeFigure*>(figure)->getType() << " "
                     << dynamic_cast<const VolumeFigure*>(figure)->getX() << " "
                     << dynamic_cast<const VolumeFigure*>(figure)->getY() << " "
                     << dynamic_cast<const VolumeFigure*>(figure)->getZ() << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for writing" << std::endl;
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string type;
        double x, y, z;
        while (file >> type) {
            std::string figureType;
            file >> figureType;
            if (type == "Flat") {
                file >> x >> y;
                addFigure(new FlatFigure(figureType, x, y));
            } else if (type == "Volume") {
                file >> x >> y >> z;
                addFigure(new VolumeFigure(figureType, x, y, z));
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading" << std::endl;
    }
}
