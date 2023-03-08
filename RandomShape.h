#pragma once
#include "Shape.h"
class RandomShape :
    public Shape
{
public:
    explicit RandomShape(sf::RenderWindow* window, int angles);
    ~RandomShape();

    void setSize(const sf::Vector2f params = sf::Vector2f(0.f, 0.f)) override;
private:
    sf::ConvexShape* convex;
    int m_count_angles = 3;
};

