#include "rayScanner.h"

RayScanner::RayScanner(VPO &objects, float xRes, float yRes) {
    this->objects = objects;
    this->xResolution = xRes;
    this->yResolution = yRes;
}

float RayScanner::normalizeXValue(float xValue) {
    // Scale the x value to the resolution
    return (xValue * 1.5 / xResolution) - 0.75;
}

float RayScanner::normalizeYValue(float yValue) {
    // Scale the y value to the resolution
    return yValue / yResolution - 0.5;
}

void RayScanner::renderGrayscale(Image image) {
    for (int y = 0; y < yResolution; ++y) {
        for (int x = 0; x < xResolution; ++x) {
            // Create rays that shoot through the screen
            Ray currentRay(normalizeXValue(x), normalizeYValue(y), 0, objects);
            currentRay.scan();
            image.setGrayscale((float) currentRay.brightness / 9, x, y);
        }
    }

    image.exportImage("image.bmp");
}

void RayScanner::renderColor(Image image) {
    for (int y = 0; y < yResolution; ++y) {
        for (int x = 0; x < xResolution; ++x) {
            // Create rays that shoot through the screen
            Ray currentRay(normalizeXValue(x), normalizeYValue(y), 0, objects);
            currentRay.scanColor();
            image.setColor(currentRay.color, x, y);
        }
    }

    image.exportImage("imageColor.bmp");
}