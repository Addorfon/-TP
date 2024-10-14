//
// Created by 89026 on 14.10.2024.
//

#ifndef TP1_KEEPER_H
#define TP1_KEEPER_H

#include "Figure.h"
#include <vector>

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addFigure(Figure* figure);
    void removeFigure(int index);
    void displayFigures() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Figure*> figures;
};

#endif //TP1_KEEPER_H
