#include "vec3D.h"

Vec3D::Vec3D() = default;

Vec3D::Vec3D(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}


Vec3D Vec3D::operator+(const Vec3D &other) const {
    return Vec3D{x + other.x, y + other.y, z + other.z};
}

Vec3D Vec3D::operator-(const Vec3D &other) const {
    return Vec3D{x - other.x, y - other.y, z - other.z};
}

Vec3D Vec3D::operator*(float scalar) const {
    return Vec3D{x * scalar, y * scalar, z * scalar};
}

Vec3D Vec3D::operator/(float scalar) const {
    return Vec3D{x / scalar, y / scalar, z / scalar};
}

void Vec3D::show(std::string label) {
    std::cout << label << ": ";
    std::cout << x << ",";
    std::cout << y << ",";
    std::cout << z << "\n";
}

void Vec3D::show(std::string label, float scalar) {
    std::cout << label << ": " << scalar << "\n";
}

Vec3D Vec3D::minus() const {
    return Vec3D{x * -1, y * -1, z * -1};
}

float Vec3D::norm() const {
    return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

Vec3D Vec3D::unit() const {
    return *this / norm();
}

float Vec3D::dot(Vec3D const &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vec3D Vec3D::cross(Vec3D const &other) const {
    return Vec3D{
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
    };
}
