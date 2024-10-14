//
// Created by 89026 on 14.10.2024.
//
#include "Keeper.h"
#include "FlatFigure.h"
#include "VolumeFigure.h"
#include "Keeper.h"
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

void Keeper::displayFigures() const {
    for (const Figure* figure : figures) {
        figure->draw();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Figure* figure : figures) {
            file << figure->getType() << " " << figure->getSize() << " ";
            if (dynamic_cast<const FlatFigure*>(figure)) {
                file << "Flat " << dynamic_cast<const FlatFigure*>(figure)->getArea() << std::endl;
            } else if (dynamic_cast<const VolumeFigure*>(figure)) {
                file << "Volume " << dynamic_cast<const VolumeFigure*>(figure)->getVolume() << std::endl;
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
        double size, value;
        while (file >> type >> size) {
            std::string figureType;
            file >> figureType;
            if (figureType == "Flat") {
                file >> value;
                addFigure(new FlatFigure(type, size, value));
            } else if (figureType == "Volume") {
                file >> value;
                addFigure(new VolumeFigure(type, size, value));
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading" << std::endl;
    }
}
