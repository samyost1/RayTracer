#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include <iostream>
#include <cmath>
#include <vector>
#include "vec3D.h"
#include "image.h"


class Object {
protected:
    Vec3D center;
    std::string type;

    friend class Ray;

    friend class RayScanner;

public:
    Color color;

    Object(float x, float y, float z, std::string type);

    Object(float x, float y, float z, std::string type, Color color);

    virtual bool hit(class Ray const &ray) const = 0;

    virtual Vec3D hitPoint(class Ray const &ray) const = 0;

    virtual Vec3D normal(class Ray const &ray) const = 0;

};

#endif //RAYTRACER_OBJECT_H
