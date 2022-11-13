#ifndef RAYTRACER_FLOOR_H
#define RAYTRACER_FLOOR_H

#include <iostream>
#include <cmath>
#include <vector>
#include "object.h"
#include "ray.h"
#include "image.h"

class Floor : public Object {
protected:
    float length;
    float width;
    float squareSize;


public:
    Color color;

    Floor(float x, float y, float z, float length, float width, float squareSize);

    Floor(float x, float y, float z, float length, float width, float squareSize, Color color);

    bool hit(const Ray &ray) const;

    Vec3D normal(Ray const &ray) const;

    Vec3D hitPoint(Ray const &ray) const;
};

#endif //RAYTRACER_FLOOR_H
