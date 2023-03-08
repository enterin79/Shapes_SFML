#include "Rectangle.h"

Rectangle::Rectangle(sf::RenderWindow* window):Shape(window) {
	rect = new sf::RectangleShape();
	m_shape = rect;
}
Rectangle::~Rectangle() {
	if (rect != nullptr) {
		delete rect;
	}
}
void Rectangle::setSize(const sf::Vector2f params) {
	m_size_x = params.x;
	m_size_y = params.y;

	rect->setSize({ m_size_x, m_size_y });
}