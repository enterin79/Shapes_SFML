#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle(sf::RenderWindow* window);
    ~Circle();

    void setSize(const sf::Vector2f params = sf::Vector2f(0.f, 0.f)) override;

private:
    sf::CircleShape* circle;
};

