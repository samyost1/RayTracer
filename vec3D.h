#ifndef RAYTRACER_VEC3D_H
#define RAYTRACER_VEC3D_H

#include <iostream>
#include <cmath>
#include <vector>

class Vec3D {
protected:
    float x;
    float y;
    float z;

    friend class Sphere;

    friend class Floor;

public:
    Vec3D(float x, float y, float z);

    Vec3D();

    Vec3D operator+(Vec3D const &other) const;

    Vec3D operator-(Vec3D const &other) const;

    Vec3D operator*(float scalar) const;

    Vec3D operator/(float scalar) const;

    void show(std::string label);

    void show(std::string label, float scalar);

    Vec3D minus() const;

    float norm() const;

    Vec3D unit() const;

    float dot(Vec3D const &other) const;

    Vec3D cross(Vec3D const &other) const;

};

#endif //RAYTRACER_VEC3D_H
