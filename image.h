#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <vector>

struct Color {
    float r, g ,b;

    Color();

    Color(float r, float g, float b);

    ~Color();
};

class Image{
public:
    Image(int width, int height);

    ~Image();

    Color getColor(int x, int y) const;

    void setColor(const Color &color, int x, int y);

    void setGrayscale(float brightness, int x, int y);

    void exportImage(const char *path) const;
private:
    int m_width;
    int m_height;
    std::vector <Color> m_colors;
};




#endif //RAYTRACER_IMAGE_H
