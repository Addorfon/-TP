//
// Created by 89026 on 11.10.2024.
//

#ifndef TP1_VOLUMEFIGURE_H
#define TP1_VOLUMEFIGURE_H

#include "Figure.h"

class VolumeFigure : public Figure {
private:
    double volume;
public:
    VolumeFigure();
    VolumeFigure(const std::string& type, double size, double area);
    ~VolumeFigure();

    void draw() const override;
    double getVolume() const override;
    void setVolume(double area);

};


#endif //TP1_VOLUMEFIGURE_H
