#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <iostream>
#include <cmath>
#include <vector>
#include "object.h"
#include "ray.h"
#include "image.h"

class Sphere : public Object {
protected:
    Vec3D center;
    float radius;

public:
    Color color;

    Sphere(float x, float y, float z, float radius);

    Sphere(float x, float y, float z, float radius, Color color);

    void show(std::string label);

    float distFromRay(Ray const &ray) const;

    bool hit(Ray const &ray) const;

    Vec3D hitPoint(Ray const &ray) const;

    Vec3D normal(Ray const &ray) const;
};

#endif //RAYTRACER_SPHERE_H
