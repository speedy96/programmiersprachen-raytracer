//
// Created by SYSTEM on 24.06.2018.
//

#include "sphere.h"
#include <glm/vec3.hpp>
#include <cmath>

Sphere::Sphere( glm::vec3 const& mid, double const& &radius):
    radius_{radius},
    mid_{mid}
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
    double volume = 4/3 * M_PI* pow(radius_,3);
}