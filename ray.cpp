#include "ray.h"

typedef std::vector<Object *> VPO;

Ray::Ray(Vec3D support, Vec3D direction, int brightness, VPO &objects) {
    this->support = support;
    this->direction = direction;
    this->brightness = brightness;
    this->objects = objects;
}


Ray::Ray(float xStart, float yStart, int brightness, VPO &objects) {
    // Eye (0 0 -4.5)
    support = Vec3D(0, 0, -4.5);
    // Screen (x y -3.0)
    direction = (Vec3D(xStart, yStart, -3.0) - support).unit();
    this->brightness = brightness;
    this->objects = objects;
}

int Ray::trace(int currentBrightness) {
    // First check if ray has already reflected 4 times
    if (currentBrightness == 4) {
        return currentBrightness;
    }

    // Check for each object if the ray hits
    for (Object *object: objects) {
        if (object->hit(*this) && object->type == "Sphere") {
            // Trace a new reflecting ray to see if it also hits an object
            return Ray(object->hitPoint(*this),
                       reflect(object->normal(*this)),
                       currentBrightness + 1,
                       objects)
                    .trace(currentBrightness + 1);
        } else if (object->hit(*this) && object->type == "Floor") {
            return 6;
        }
    }
    return 1;
}

Color Ray::traceColor(int currentBrightness, Color currentColor) {
    // First check if ray has already reflected 4 times
    if (currentBrightness == 4) {
        return Color(currentColor.r * ((float) (9 - currentBrightness) / 9),
                     currentColor.g * ((float) (9 - currentBrightness) / 9),
                     currentColor.b * ((float) (9 - currentBrightness) / 9));
    }

    // Check for each object if the ray hits
    for (Object *object: objects) {
        if (object->hit(*this) && object->type == "Sphere") {
            // Trace a new reflecting ray to see if it also hits an object
            return Ray(object->hitPoint(*this),
                       reflect(object->normal(*this)),
                       currentBrightness + 1,
                       objects)
                    .traceColor(currentBrightness + 1, object->color);
        } else if (object->hit(*this) && object->type == "Floor") {
            return Color(object->color.r * ((float) 6 / 9),
                         object->color.g * ((float) 6 / 9),
                         object->color.b * ((float) 6 / 9));
        }
    }
    return currentColor;
}

Vec3D Ray::reflect(Vec3D normal) const {
    // https://www.sciencedirect.com/topics/computer-science/reflection-vector
    return direction - (normal * (float) 2 * direction.dot(normal));
}

bool Ray::scan() {
    for (Object *object: objects) {
        if (object->hit(*this) && object->type == "Sphere") {
            brightness = trace(0);  // Trace the ray
            return true;
        } else if (object->hit(*this) && object->type == "Floor") {
            brightness = 9;
            return true;
        }
    }
    brightness = 0;
    return false;
}

bool Ray::scanColor() {
    for (Object *object: objects) {
        if (object->hit(*this) && object->type == "Sphere") {
            color = traceColor(0, object->color);  // Trace the ray
            return true;
        } else if (object->hit(*this) && object->type == "Floor") {
            color = Color(object->color.r,
                          object->color.g,
                          object->color.b);
            return true;
        }
    }
    return false;
}