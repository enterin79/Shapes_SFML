#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "Button.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "RandomShape.h"
#include "RandomAngle.h"

using namespace std;

sf::Color getRandomColor() {
    return sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

sf::Vector2f getRandomSize() {
    return { (float)(rand() % 200 + 50), (float)(rand() % 200 + 50) };
}

bool onAnyButtonOver(list<Button>* buts) {
    list<Button>::iterator i;
    for (i = buts->begin(); i != buts->end(); i++) {
        if (i->isMouseOver()) {
            return true;
        }
    }
    return false;
}

int main()
{
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(520, 600), "SFML Shapes", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "Font not found!\n";

    //Объявления кнопок для выбора фигур
    Button btn_circle("Circle", { 80, 50 }, 20, sf::Color::White, sf::Color::Black, &window);
    btn_circle.setFont(font);
    btn_circle.setPosition({ 20, 20 });
    btn_circle.setOutline(2.f, sf::Color::Green);

    Button btn_rectangle("Rect", { 80, 50 }, 20, sf::Color::White, sf::Color::Black, &window);
    btn_rectangle.setFont(font);
    btn_rectangle.setPosition({ 120, 20 });
    btn_rectangle.setOutline(2.f, sf::Color::Green);

    Button btn_triangle("Triangle", { 80, 50 }, 20, sf::Color::White, sf::Color::Black, &window);
    btn_triangle.setFont(font);
    btn_triangle.setPosition({ 220, 20 });
    btn_triangle.setOutline(2.f, sf::Color::Green);


    Button btn_polygon("Polygon", { 80, 50 }, 20, sf::Color::White, sf::Color::Black, &window);
    btn_polygon.setFont(font);
    btn_polygon.setPosition({ 320, 20 });
    btn_polygon.setOutline(2.f, sf::Color::Green);

    Button btn_randomshape("Random\nShape", { 80, 50 }, 20, sf::Color::White, sf::Color::Black, &window);
    btn_randomshape.setFont(font);
    btn_randomshape.setPosition({ 420, 20 });
    btn_randomshape.setOutline(2.f, sf::Color::Green);

    list<Button> buttons = { btn_circle, btn_rectangle, btn_triangle, btn_polygon, btn_randomshape };
    list<Button>::iterator ib;

    Shape *curr_shape = nullptr;

    bool shape_changed = true;
    
    while (window.isOpen())
    {
        window.clear();

        sf::Event event;

        while (window.pollEvent(event))
        {

            switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::MouseButtonPressed: {
                //Очистка данных предыдущей фигуры при нажатии кнопки
                if (onAnyButtonOver(&buttons) && curr_shape != nullptr) 
                {
                    delete curr_shape;
                    curr_shape = nullptr;
                    shape_changed = true;
                }

                //Выбор новой фигуры в зависимости от нажатой кнопки
                if (btn_circle.isMouseOver()) {
                    std::cout << "circle " << "\n";
                    curr_shape = new Circle(&window);
                }
                else if (btn_rectangle.isMouseOver()) {
                    std::cout << "rectangle " << "\n";
                    curr_shape = new Rectangle(&window);
                }
                else if (btn_triangle.isMouseOver()) {
                    std::cout << "triangle " << "\n";
                    curr_shape = new RandomShape(&window, 3);
                }
                else if (btn_randomshape.isMouseOver()) {
                    std::cout << "randomshape " << "\n";
                    curr_shape = new RandomShape(&window, rand()%5+4);
                }
                else if (btn_polygon.isMouseOver()) {
                    std::cout << "polygon " << "\n";
                    curr_shape = new RandomAngle(&window, rand() % 7 + 3);
                }
                else {
                    shape_changed = false;
                }

                //Задание параметров новой фигуры
                if (shape_changed) {
                    curr_shape->setColor(getRandomColor());
                    curr_shape->setOutline((float)(rand() % 10 + 1), getRandomColor());
                    curr_shape->setSize(getRandomSize());
                    curr_shape->setPosition({ 120, 150 });

                    shape_changed = false;
                }

                break;
            }
            case sf::Event::MouseMoved: {
                //Выделение кнопки при наведении на нее
                for (ib = buttons.begin(); ib != buttons.end(); ib++)
                {
                    ib->checkOutline();
                }

                break;
            }

            }

        }

        for (ib = buttons.begin(); ib != buttons.end(); ib++)
        {
            ib->drawTo();
        }

        if (curr_shape != nullptr) {
            curr_shape->drawShape();
        }

        window.display();
    }

    return 0;
}