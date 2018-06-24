//
// Created by SYSTEM on 24.06.2018.
//

#ifndef PROJECT_RAY_H
#define PROJECT_RAY_H

#include <glm/vec3.hpp>

struct Ray {
    glm :: vec3 origin = {0.0f, 0.0f, 0.0f};
    glm :: vec3 direction = {0.0f, 0.0f, -1.0f};
};

#endif //PROJECT_RAY_H
