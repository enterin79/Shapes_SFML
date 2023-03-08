#include "Circle.h"
Circle::Circle(sf::RenderWindow* window) :Shape(window) {
	circle = new sf::CircleShape();
	m_shape = circle;
}
Circle::~Circle() {
	if (circle != nullptr) {
		delete circle;
	}
}
void Circle::setSize(const sf::Vector2f params) {
	m_size_x = params.x/2;
	circle->setRadius(m_size_x);
}