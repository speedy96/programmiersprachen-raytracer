//
// Created by SYSTEM on 24.06.2018.
//

#ifndef PROJECT_SHAPE_H
#define PROJECT_SHAPE_H

#include "color.hpp"
#include <string>
#include <iostream>

class Shape{
public:

    Shape(std::string const& name, Color const& color);
    ~Shape();

    virtual double area()const;
    virtual double volume()const;
    std::string name()const;
    Color color()const;
    virtual std::ostream& print(std::ostream& os);

private:
    std::string name_;
    Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif //PROJECT_SHAPE_H
