//
// Created by SYSTEM on 24.06.2018.
//

#ifndef PROJECT_BOX_H
#define PROJECT_BOX_H

#include "shape.h"
#include <glm/vec3.hpp>

class Box : Shape {
public:
    Box(glm::ve3 const& min, glm::vec3 const& max);
    glm::vec3 min()const;
    glm::vec3 max()const;
    double area()const override;
    double area()const override;

private:
    glm::vec3 min_;
    glm::vec3 max_;
};

#endif //PROJECT_BOX_H
