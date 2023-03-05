//
// Created by Edward Eckelberry on 12/11/22.
//

#include "MouseEvents.h"

bool MouseEvents::is_hovered(const sf::FloatRect& object, sf::RenderWindow& window)
{
    sf::Vector2f mouse_position = (sf::Vector2f) sf::Mouse::getPosition(window);

    return object.contains(mouse_position);
}

bool MouseEvents::is_clicked(const sf::FloatRect &object, sf::RenderWindow &window)
{
    return is_hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
