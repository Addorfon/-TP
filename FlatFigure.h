//
// Created by 89026 on 11.10.2024.
//

#ifndef TP1_FLATFIGURE_H
#define TP1_FLATFIGURE_H

#include "Figure.h"

class FlatFigure : public Figure {
private:
    double area;
public:
    FlatFigure();
    FlatFigure(const std::string& type, double size, double area);
    ~FlatFigure();

    void draw() const override;
    double getArea() const override;
    void setArea(double area);

};

#endif //TP1_FLATFIGURE_H
