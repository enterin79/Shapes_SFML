#pragma once
#include "Shape.h"
class RandomAngle :
    public Shape
{
public:
    explicit RandomAngle(sf::RenderWindow* window, int angles);
    ~RandomAngle();

    void setSize(const sf::Vector2f params = sf::Vector2f(0.f, 0.f)) override;

private:
    sf::CircleShape* polygon;
    int m_count_angles = 3;
};

