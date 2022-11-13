#include "floor.h"

Floor::Floor(float x, float y, float z, float length, float width, float squareSize) : Object(x, y, z, "Floor") {
    this->length = length;
    this->width = width;
    this->squareSize = squareSize;
}

Floor::Floor(float x, float y, float z, float length, float width, float squareSize, Color color) : Object(x, y, z, "Floor", color) {
    this->length = length;
    this->width = width;
    this->squareSize = squareSize;
    this-> color = color;
}

bool Floor::hit(const Ray &ray) const {
    Vec3D hitPoint = this->hitPoint(ray);

    // Check if the ray travels backwards and if the ray hits the floor within the floor's dimensions
    if (((center.y - ray.support.y) / ray.direction.y) < 0 ||
        std::abs(hitPoint.x) > width / 2 ||
        std::abs(hitPoint.z) > length / 2) {
        return false;
    }

    //Check if hitPoint is on a white square
    return (int) (std::abs(hitPoint.x - (float) (hitPoint.x < 0) * squareSize) / squareSize) % 2 ==
           (int) (std::abs(hitPoint.z - (float) (hitPoint.z < 0) * squareSize) / squareSize) % 2;
}

Vec3D Floor::normal(Ray const &ray) const {
    return Vec3D{0, 1, 0};
}

Vec3D Floor::hitPoint(Ray const &ray) const {
    // First calculate the distance the ray has to travel to hit the floor
    float rayDistance = (center.y - ray.support.y) / ray.direction.y;
    // Then use the vector line equation to find the hitPoint
    return ray.support + ray.direction * rayDistance;
}