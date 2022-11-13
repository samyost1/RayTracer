#include "object.h"

Object::Object(float x, float y, float z, std::string type) : center(x, y, z), type(type) {}

Object::Object(float x, float y, float z, std::string type, Color color) : center(x, y, z), type(type), color(color) {}
