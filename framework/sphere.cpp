//
// Created by SYSTEM on 24.06.2018.
//

#include "sphere.h"
#include "shape.h
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>

Sphere::Sphere( glm::vec3 const& mid, double const& &radius):

    radius_{radius},
    mid_{mid},
    Shape{}
{};

Sphere::Sphere(glm::vec2 const& mid, double const&radius, std::string const& name, Color const &color):
        mid_{mid},
        radius_{radius},
        Shape{name, color}

{};

double Sphere::radius() const {
    return radius_;
}

glm::vec3 Sphere::mid() const {
    return mid_;
}

double Sphere::area() const {
    double area = 4* M_PI* pow(radius_,2);
    return area;
}

double Sphere::volume() const {
    double volume = (4.0/3.0) * M_PI* pow(radius_,3);
}

std::ostream& Sphere::print(std::ostream &os) const {
    Shape::print(os);
    os<<"Area: " <<area()<<'\n';
    os<<"Volume: "<<volume()<<'\n';
    os<<"Radius: " <<radius()<<'\n';
    os<<"Center: (" <<mid_.x<<","<<mid_.y<<")"<<'\n';
    return os;
}