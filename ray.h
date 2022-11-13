#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include <iostream>
#include <cmath>
#include <vector>
#include "object.h"
#include "vec3D.h"
#include "image.h"

typedef std::vector<Object *> VPO;

class Ray {
protected:
    Vec3D support;
    Vec3D direction;
    VPO objects;
    char brightnessChars[11] = " .:-=+*#%@";
    int brightness;

    friend class RayScanner;

    friend class Sphere;

    friend class Floor;

public:
    Color color;

    Ray(Vec3D support, Vec3D direction, int brightness, VPO &objects);

    Ray(float xStart, float yStart, int brightness, VPO &objects);

    int trace(int currentBrightness);

    Color traceColor(int currentBrightness, Color currentColor);

    Vec3D reflect(Vec3D normal) const;

    bool scan();
    bool scanColor();
};

#endif //RAYTRACER_RAY_H