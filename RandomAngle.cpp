#include "RandomAngle.h"
RandomAngle::RandomAngle(sf::RenderWindow* window, int angles) :Shape(window) {
	polygon = new sf::CircleShape();
	m_shape = polygon;
	m_count_angles = angles;
	polygon->setPointCount(angles);
}
RandomAngle::~RandomAngle() {
	if (polygon != nullptr) {
		delete polygon;
	}
}
void RandomAngle::setSize(const sf::Vector2f params) {
	m_size_x = params.x / 2;
	polygon->setRadius(m_size_x);
}