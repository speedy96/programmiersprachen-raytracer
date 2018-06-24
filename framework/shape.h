//
// Created by SYSTEM on 24.06.2018.
//

#ifndef PROJECT_SHAPE_H
#define PROJECT_SHAPE_H

#include "color.hpp"
#include <string>

class Shape{
public:

    Shape(std::string const& name, Color const& color):
            name_{name},
            color_{color} {};

    Shape () :
            name_{"unnamed"},
            color_{0.0,0.0,0.0} {};

    virtual double area()const = 0;
    virtual double volume()const = 0;
    std::string name()const {
        return name_;
    }
    Color color()const {
        return color_;
    }

private:
    std::string name_;
    Color color_;
};

#endif //PROJECT_SHAPE_H
