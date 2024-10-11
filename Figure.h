//
// Created by 89026 on 11.10.2024.
//

#ifndef TP1_FIGURE_H
#define TP1_FIGURE_H

#include <iostream>
#include <string>

class Figure {
protected:
    std::string type;
    double size;
public:
    Figure();
    Figure(const std::string& type, double size);
    virtual ~Figure();

    std::string getType() const;
    double getSize() const;

    virtual void draw() const = 0;
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;

    void setType(const std::string& type);
    void setSize(double size);

};

#endif //TP1_FIGURE_H
