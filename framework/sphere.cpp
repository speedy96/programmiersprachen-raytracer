

#include "sphere.h"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>
#include "ray.h"
#include <glm/gtx/intersect.hpp>
#include "shape.h"



Sphere::Sphere(glm::vec3 const& mid, double const&radius, std::string const& name, Color const &color):
        mid_{mid},
        radius_{radius},
        Shape{name, color}

{std::cout<< "child constructor "<< '\n';};

Sphere::~Sphere()
{std::cout << "child destructor" << '\n';};

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

bool Sphere::intersect(Ray const& ray, float& distance) const{
    return glm::intersectRaySphere(ray.origin,ray.direction,mid_,radius_*radius_,distance);
}