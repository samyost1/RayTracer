#include "rayScanner.h"
#include "floor.h"
#include "sphere.h"

int main() {
    VPO objects(4);

    Sphere spheres[3] = {Sphere(-0.4, 0.23, -1, 0.4, Color(0.4, 0, 0)),
                         Sphere(0.4, 0.4, -1.2, 0.3, Color(0, 0.4, 0)),
                         Sphere(0.7, -0.15, -1.5, 0.2, Color(0, 0, 0.1))};
    Floor floor = Floor(0, 1, -1, 8, 12, 0.5, Color(1, 1, 1));

    objects = {&spheres[0], &spheres[1], &spheres[2], &floor};

    const int width = 1920;
    const int height = 1200;

    Image image(width, height);

    RayScanner rayscanner(objects, width, height);

    rayscanner.renderGrayscale(image);
    rayscanner.renderColor(image);

    return 0;
}