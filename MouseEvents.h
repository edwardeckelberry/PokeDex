//
// Created by Edward Eckelberry on 12/11/22.
//

#ifndef DROPDOWNMENU_MOUSEEVENTS_H
#define DROPDOWNMENU_MOUSEEVENTS_H

#include "SFML/Graphics.hpp"

class MouseEvents
{
public:
    static bool is_hovered(const sf::FloatRect& object, sf::RenderWindow& window);
    static bool is_clicked(const sf::FloatRect& object, sf::RenderWindow& window);
};


#endif //DROPDOWNMENU_MOUSEEVENTS_H
