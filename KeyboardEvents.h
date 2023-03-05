//
// Created by Edward Eckelberry on 12/11/22.
//

#ifndef DROPDOWNMENU_KEYBOARDEVENTS_H
#define DROPDOWNMENU_KEYBOARDEVENTS_H

#include "SFML/Graphics.hpp"

class KeyboardEvents
{
public:
    static bool isSave();
    static bool isControl();

    static bool isUndo();
    static bool isRedo();

    static bool checkKeys(sf::Event& event);
    static int numKeyPress(sf::Event& event);
};


#endif //DROPDOWNMENU_KEYBOARDEVENTS_H
