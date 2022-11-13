#include "sphere.h"

Sphere::Sphere(float x, float y, float z, float radius) : Object(x, y, z, "Sphere") {
    center = Vec3D(x, y, z);
    this->radius = radius;
}

Sphere::Sphere(float x, float y, float z, float radius, Color color) : Object(x, y, z, "Sphere", color) {
    center = Vec3D(x, y, z);
    this->radius = radius;
    this->color = color;
}

void Sphere::show(std::string label) {
    std::cout << label << ": ";
    std::cout << "Center: (";
    std::cout << center.x << ",";
    std::cout << center.y << ",";
    std::cout << center.z << ") ";
    std::cout << "Radius: " << radius << "\n";
}

float Sphere::distFromRay(Ray const &ray) const {
    // ||(support - center) x direction||  /  ||direction||
    return (ray.support - center).cross(ray.direction).norm() / ray.direction.norm();
}

bool Sphere::hit(Ray const &ray) const {
    // First check if the ray points in the direction of the sphere
    if ((ray.support - center).norm() < (center - (ray.support + ray.direction)).norm()) {
        return false;
    }

    // Check if the ray hits the sphere
    return distFromRay(ray) <= radius;
}

Vec3D Sphere::hitPoint(Ray const &ray) const {
    // Calculate the distance from center to ray
    float q = distFromRay(ray);
    // Use pythagoras theorem to calculate the length between the hit-point and the ray's closest point to the center
    float PA = sqrtf(powf(radius, 2) - powf(q, 2));

    // Calculate the length of the line between center and support
    float L = (ray.support - center).norm();
    // Use pythagoras theorem to calculate the length between support and the ray's closest point to the center
    float AS = sqrtf(powf(L, 2) - powf(q, 2));

    // Calculate how far ray has to travel from support to the hit-point
    float PS = AS - PA;
    // Use the vector line equation to get the hit-point
    return Vec3D{ray.support + ray.direction.unit() * PS};
}

Vec3D Sphere::normal(Ray const &ray) const {
    return (hitPoint(ray) - center).unit();
}
