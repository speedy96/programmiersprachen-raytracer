//
// Created by SYSTEM on 24.06.2018.
//

#include "box.h"
#include <glm/vec3.hpp>
#include <cmath>

Box::Box(glm::ve3 const& min,glm::vec3 const& max) :
    min_{min},
    max_{max}
{};

glm::vec3 Box::min() const {
    return min_;
}

glm::vec3 Box::max() const {
    return max_;
}

double Box::area() const {

    double x{abs(max_.x - min_.x)}; //länge
    double y{abs(max_.y - min_y)};  //breite
    double z{abs(max_.z- min_.z)};  //höhe
    double area = 2*(x*y)+2*(x*z)+2*(y*z);
    return area;
}

double Box::volume() const {
    double x{abs(max_.x - min_.x)}; //länge
    double y{abs(max_.y - min_y)};  //breite
    double z{abs(max_.z- min_.z)};  //höhe
    double volume = x*y*z;
    return volume;
}