#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
public:
    explicit Rectangle(sf::RenderWindow* window);
    ~Rectangle();

    void setSize(const sf::Vector2f params = sf::Vector2f(0.f, 0.f)) override;

private:
    sf::RectangleShape* rect;
};

