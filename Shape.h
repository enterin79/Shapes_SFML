#pragma once
#include <SFML/Graphics.hpp>

class Shape
{
public:

	Shape(sf::RenderWindow* window = nullptr);
	~Shape();

	void drawShape();
	void setColor(sf::Color color);
	void setOutline(float thickness = 0.0, sf::Color outline_color = sf::Color::Black);
	void setPosition(const sf::Vector2f point);
	void setRotation(float rotation);
	virtual void setSize(const sf::Vector2f params = sf::Vector2f(0.f, 0.f)) = 0;
	const sf::Vector2f getSize();

protected:
	sf::Shape* m_shape;

	sf::Color m_color = sf::Color::Black;
	float m_thickness = 0.0;
	sf::Color m_outline_color = sf::Color::Black;
	float m_pos_x = 0.0;
	float m_pos_y = 0.0;
	float m_size_x = 0.0;
	float m_size_y = 0.0;
	float m_rotation = 0.0;
	sf::RenderWindow* parent_window;
};

