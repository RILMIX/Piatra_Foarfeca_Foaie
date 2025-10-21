#pragma once

class Renderable {
public:
    virtual ~Renderable() {}
    virtual void draw() const = 0;
};
