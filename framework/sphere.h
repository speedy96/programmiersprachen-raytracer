

#ifndef PROJECT_SPHERE_H
#define PROJECT_SPHERE_H

#include <glm/vec3.hpp>
#include <iostream>
#include "color.hpp"
#include <string>
#include "ray.h"
#include "shape.h"


class Sphere : public Shape 
{
public:

  
    Sphere(glm::vec3 const& mid, double const& rad, std::string const& name, Color const& color);
    ~Sphere ();
    glm::vec3 mid() const;
    double radius() const;
    double area() const override;
    double volume() const override;
    std::ostream& print (std::ostream& os)const override;
    bool intersect(Ray const& ray, float& distance) const;



private:
    double radius_;
    glm::vec3 mid_;
};


#endif //PROJECT_SPHERE_H
