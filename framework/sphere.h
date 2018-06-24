//
// Created by SYSTEM on 24.06.2018.
//

#ifndef PROJECT_SPHERE_H
#define PROJECT_SPHERE_H

#include <glm/vec3.hpp>
#include "shape.h"

class Sphere : Shape
{
public:

    Sphere(glm::vec3 const& mid, double const& rad);
    glm::vec3 mid() const;
    double radius() const;
    double area() const override;
    double volume() const override;


private:
    double radius_;
    glm::vec3 mid_;
};


#endif //PROJECT_SPHERE_H
