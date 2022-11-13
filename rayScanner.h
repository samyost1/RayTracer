#ifndef RAYTRACER_RAYSCANNER_H
#define RAYTRACER_RAYSCANNER_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "object.h"
#include "ray.h"
#include "vec3D.h"
#include "image.h"

class RayScanner {
protected:
    VPO objects;
    float xResolution;
    float yResolution;

public:
    RayScanner(VPO &objects, float xRes, float yRes);

    float normalizeXValue(float xValue);

    float normalizeYValue(float yValue);

    void renderGrayscale(Image image);
    void renderColor(Image image);
};

#endif //RAYTRACER_RAYSCANNER_H
