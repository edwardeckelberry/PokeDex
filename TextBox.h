//
// Created by Edward Eckelberry on 12/11/22.
//

#ifndef DROPDOWNMENU_TEXTBOX_H
#define DROPDOWNMENU_TEXTBOX_H

#include "SFML/Graphics.hpp"

#include "MouseEvents.h"
#include "KeyboardEvents.h"
#include "InputRecord.h"
#include "History.h"
#include "SnapShot.h"

#include <iostream>

class TextBox : public sf::Drawable, public History, public SnapShot<std::string>
{
private:
    sf::Font font;
    std::string string;
    sf::Text text1, text2;
    sf::RectangleShape background, cursor1, cursor2;

    unsigned int textSize;
    bool isHovered, isClicked;
    int counter1 = 0, counter2 = 0;

    void keyboardInputs(sf::Event &event);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

public:
    // Single parameter constructor
    explicit TextBox(unsigned int max_size = 40);

    // Setters
    void setPosition(const sf::Vector2f &position);
    void setSize(const sf::Vector2f &size_of_input_box);

    // Getters
    std::string getText() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2<float> getPosition() const;

    // This function handles all the functionality of TextBox
    void textHandler(sf::Event& event, sf::Vector2f& mouse_position);

    // Virtual function being implementing here for TextBox
    InputRecord<std::string> doSnapshot() override;
};


#endif //DROPDOWNMENU_TEXTBOX_H
