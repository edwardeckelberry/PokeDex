//
// Created by Edward Eckelberry on 12/11/22.
//

#include "TextBox.h"

TextBox::TextBox(unsigned int max_size)
        : textSize(max_size), isHovered(false), isClicked(false)
{
    this->font.loadFromFile("fonts/OpenSans-Regular.ttf");

    this->text1.setFont(font);
    this->text1.setFillColor(sf::Color::Black);

    this->text2.setFont(font);
    this->text2.setFillColor(sf::Color::Black);
//    this->text2.setString("Type Enter");

    this->background.setSize({static_cast<float>(13 * textSize), 40});
    this->background.setOutlineThickness(4);
    this->background.setFillColor(sf::Color::White);
    this->background.setOutlineColor((sf::Color::Red));

    this->cursor1.setSize({5, 30});

    this->cursor2.setSize({5, 30});
    this->cursor2.setFillColor(sf::Color::Black);
}

void TextBox::setPosition(const sf::Vector2f &position)
{
    cursor1.setPosition({position.x + 5, position.y + 10});
    cursor2.setPosition({position.x + 5, position.y + 10});

    text1.setPosition({position.x, position.y});
    text2.setPosition({position.x, position.y});

    background.setPosition(position);
}

void TextBox::keyboardInputs(sf::Event& event)
{
    if (!isHovered || event.type != sf::Event::TextEntered)
    {
        return;
    }

    if (event.text.unicode == 8)
    {
        if (string.size() == 1)
        {
            string = string.substr(0, string.size() - 1);
            text1.setString(string);
        }
        else if (string.size() >= 2)
        {
            History::pop();
            string = string.substr(0, string.size() - 1);
            text1.setString(string);
        }
    }
    else if ( (string.size() < textSize)
              // This condition is for when the user enters Control + Z
              // a square character gets entered and display on the SFML window.
              // So this condition takes care of the character input
              && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
                   && sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ))
    {
        // Updating the std::string as the user enters different keys.
        string += event.text.unicode;

        // Applying the std::string to the font.
        text1.setString(string);

        // Applying the History stack and converting the object
        History::push(static_cast<HistoryNode>(string));
    }
}

sf::FloatRect TextBox::getGlobalBounds() const
{
    return background.getGlobalBounds();
}

std::string TextBox::getText() const
{
    return string;
}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background);

    window.draw(cursor1);
    window.draw(cursor2);

    window.draw(text1);
    window.draw(text2);
}

void TextBox::setSize(const sf::Vector2f &size_of_input_box)
{
    background.setSize({size_of_input_box.x + 800, size_of_input_box.y});

    cursor1.setSize({5, background.getGlobalBounds().height - 15});
    cursor2.setSize({5, background.getGlobalBounds().height - 15});

    text1.setCharacterSize(static_cast<unsigned int>(size_of_input_box.y - 10));
    text2.setCharacterSize(static_cast<unsigned int>(size_of_input_box.y - 10));
}

sf::Vector2<float> TextBox::getPosition() const
{
    return background.getPosition();
}

void TextBox::textHandler(sf::Event &event, sf::Vector2f &mouse_position)
{
    // This function handles keyboard inputs
    this->keyboardInputs(event);

    // When the user hits the keys
    if (KeyboardEvents::isUndo())
    {
        if (string.size() == 1)
        {
            string = string.substr(0, string.size() - 1);
            text1.setString(string);
        }
        else if (string.size() >= 2)
        {
            History::pop();

            string = this->doSnapshot().getData();
            text1.setString(string);
        }
    }

    float width_1 = text2.getGlobalBounds().width;

    if (string.empty())
    {
        text2.setFillColor(sf::Color::Transparent);
        cursor2.setFillColor(sf::Color::Transparent);
//        text2.setFillColor(sf::Color::Black);
//        cursor2.setPosition((text2.getPosition().x + width_1) + 10,
//                                      text2.getPosition().y + 5);
//        counter2++;
//
//        if (counter2 <= 25)
//            this->cursor2.setFillColor(sf::Color::Black);
//        else
//            this->cursor2.setFillColor(sf::Color::Transparent);
//
//        if (counter2 == 75)
//            counter2 = 0;
    }
    else
    {
        text2.setFillColor(sf::Color::Transparent);
        cursor2.setFillColor(sf::Color::Transparent);
    }

    if (background.getGlobalBounds().contains(mouse_position))
    {
        isHovered = true;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            isClicked = true;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && !background.getGlobalBounds().contains(mouse_position))
    {
        isClicked = false;
        isHovered = false;
    }

    if (isHovered && isClicked)
    {
        text2.setFillColor(sf::Color::Transparent);
        cursor2.setFillColor(sf::Color::Transparent);
        background.setOutlineColor(sf::Color::Blue);
        counter1++;

        if (counter1 <= 25)
            this->cursor1.setFillColor(sf::Color::Black);
        else
            this->cursor1.setFillColor(sf::Color::Transparent);

        if (counter1 == 75)
            counter1 = 0;
    }
    else
    {
        this->cursor1.setFillColor(sf::Color::Transparent);
    }

    float width_2 = text1.getGlobalBounds().width;

    if (text1.getCharacterSize() > 0)
    {
        cursor1.setPosition((text1.getPosition().x + width_2) + 10,
                                      text1.getPosition().y + 5);
    }
}

InputRecord<std::string> TextBox::doSnapshot()
{
    return History::top().memorySlot;
}

