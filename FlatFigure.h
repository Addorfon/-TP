#ifndef TP1_FLATFIGURE_H
#define TP1_FLATFIGURE_H

#include "Figure.h"

class FlatFigure : public Figure {
private:
    double x;
    double y;
    double area;
public:
    FlatFigure();
    FlatFigure(const std::string& type, double x, double y);
    ~FlatFigure();

    void draw() const override;
    double getArea() const override;
    double getVolume() const override;

    void setX(double x);
    void setY(double y);
    void setSize(double x, double y);

    double getX() const;
    double getY() const;
};

#endif //TP1_FLATFIGURE_H
