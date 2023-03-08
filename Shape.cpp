#include "Shape.h"

Shape::Shape(sf::RenderWindow* window) {
	parent_window = window;
}

Shape::~Shape() {
	parent_window = nullptr;
	m_shape = nullptr;
}

void Shape::drawShape() {
	parent_window->draw(*m_shape);
}

void Shape::setColor(sf::Color color) {
	m_color = color;

	m_shape->setFillColor(m_color);
}

void Shape::setOutline(float thickness, sf::Color outline_color) {
	m_thickness = thickness;
	m_outline_color = outline_color;

	m_shape->setOutlineThickness(m_thickness);
	m_shape->setOutlineColor(m_outline_color);
}

void Shape::setPosition(const sf::Vector2f point) {
	m_pos_x = point.x;
	m_pos_y = point.y;

	m_shape->setPosition({m_pos_x, m_pos_y});
}

void Shape::setSize(const sf::Vector2f params) {
	m_size_x = params.x;
	m_size_y = params.y;
}

void Shape::setRotation(float rotation) {
	m_rotation = rotation;

	m_shape->setRotation(m_rotation);
}

const sf::Vector2f Shape::getSize() {
	return { m_size_x, m_size_y };
}