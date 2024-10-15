#ifndef TP1_VOLUMEFIGURE_H
#define TP1_VOLUMEFIGURE_H

#include "Figure.h"

class VolumeFigure : public Figure {
private:
    double x;
    double y;
    double z;
    double volume;
public:
    VolumeFigure();
    VolumeFigure(const std::string& type, double x, double y, double z);
    ~VolumeFigure();

    void draw() const override;
    double getVolume() const override;
    double getArea() const override;
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setSize(double x, double y, double z);
    double getX() const;
    double getY() const;
    double getZ() const;
};

#endif //TP1_VOLUMEFIGURE_H
