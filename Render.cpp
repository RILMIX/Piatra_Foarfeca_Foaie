#pragma once

class Renderable {
public:
    virtual void draw() const = 0;

    virtual ~Renderable() = default;
};