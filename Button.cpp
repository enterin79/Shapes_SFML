#include "Button.h"
#include "iostream"
Button::Button(sf::RenderWindow* window) {
	parent_window = window;
	button = new sf::RectangleShape();
	text_button = new sf::Text();
}

Button::~Button() {

}

Button::Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor, sf::RenderWindow* window) {
	button = new sf::RectangleShape();
	text_button = new sf::Text();

	button->setSize(buttonSize);
	button->setFillColor(bgColor);

	// Get these for later use:
	btnWidth = buttonSize.x;
	btnHeight = buttonSize.y;

	text_button->setString(btnText);
	text_button->setCharacterSize(charSize);
	text_button->setFillColor(textColor);

	parent_window = window;
}

// Pass font by reference:
void Button::setFont(sf::Font& fonts) {
	text_button->setFont(fonts);
}

void Button::setBackColor(sf::Color color) {
	button->setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	text_button->setFillColor(color);
}

void Button::setPosition(sf::Vector2f point) {
	button->setPosition(point);

	// Center text on button:
	float xPos = (point.x + btnWidth / 2) - (text_button->getLocalBounds().width / 2);
	float yPos = (point.y + btnHeight / 2.2) - (text_button->getLocalBounds().height / 2);
	text_button->setPosition(xPos, yPos);
}

void Button::drawTo() {
	parent_window->draw(*button);
	parent_window->draw(*text_button);
}

void Button::setOutline(float thickness, sf::Color color) {
	outline_thickness = thickness;
	outline_color = color;
}

void Button::drawOutline() {
	
	button->setOutlineThickness(outline_thickness);
	button->setOutlineColor(outline_color);
}

void Button::eraseOutline() {
	button->setOutlineThickness(0);
}

void Button::checkOutline() {
	//std::cout << this << "|" << std::endl;
	if (isMouseOver()) {
		drawOutline();
	}
	else {
		eraseOutline();
	}
}

// Check if the mouse is within the bounds of the button:
bool Button::isMouseOver() {
	int mouseX = sf::Mouse::getPosition(*parent_window).x;
	int mouseY = sf::Mouse::getPosition(*parent_window).y;

	int btnPosX = button->getPosition().x;
	int btnPosY = button->getPosition().y;

	int btnxPosWidth = button->getPosition().x + btnWidth;
	int btnyPosHeight = button->getPosition().y + btnHeight;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
		return true;
	}
	else {
		return false;
	}
}