#include "cinder/Color.h"
#include "cinder/gl/gl.h"

#pragma once

using namespace ci;

class Dot {
    public:
        void draw();
        Dot();
        Dot(float x, float y, Colorf color);

    private:
        float x_, y_;
        Colorf color_;
};

Dot::Dot() {}

Dot::Dot(float x, float y, Colorf color): 
    x_(x), y_(y), color_(color) {}

void Dot::draw() {
    gl::color(color_[0], color_[1], color_[2]);
    gl::drawSolidCircle(vec2(x_, y_), 30);
}
