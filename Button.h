#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
	Button(sf::RenderWindow* window);

	Button(std::string btn_text, sf::Vector2f button_size, int char_size, sf::Color bg_color, sf::Color text_color, sf::RenderWindow* window);

	~Button();

	void setFont(sf::Font& fonts);

	void setBackColor(sf::Color color);

	void setTextColor(sf::Color color);

	void setPosition(sf::Vector2f point);

	void drawTo();

	void setOutline(float thickness, sf::Color outline_color);

	void checkOutline();

	bool isMouseOver();


private:
	sf::RectangleShape* button;
	sf::Text* text_button;
	sf::RenderWindow* parent_window;

	int btnWidth;
	int btnHeight;

	void drawOutline();
	void eraseOutline();
	sf::Color outline_color = sf::Color::Black;
	int outline_thickness = 0;
};

