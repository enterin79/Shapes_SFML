#include "RandomShape.h"
#include "Circle.h"
RandomShape::RandomShape(sf::RenderWindow* window, int angles) :Shape(window) {
	convex = new sf::ConvexShape();
	m_shape = convex;
	m_count_angles = angles;
	convex->setPointCount(angles);
}
RandomShape::~RandomShape() {
	if (convex != nullptr) {
		delete convex;
	}
}
void RandomShape::setSize(const sf::Vector2f params) {
	float x, y;
	m_size_x = params.x;
	m_size_y = params.y;
	
	convex->setPoint(0, { 0.0,   m_size_y });
	for (int i = 1; i < m_count_angles-1; i++) {
		x = float(rand() % (int)m_size_x + 10);
		y = float(rand() % (int)m_size_y + 10);
		convex->setPoint(i, { x,  y});
	}
	convex->setPoint((m_count_angles-1), { m_size_x,   m_size_y });
}