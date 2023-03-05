//
// Created by Edward Eckelberry on 12/11/22.
//

#include "KeyboardEvents.h"
#include <iostream>

bool KeyboardEvents::isSave()
{
    return isControl() && sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

bool KeyboardEvents::isControl()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem)  ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem);
}

bool KeyboardEvents::isUndo()
{
    static unsigned int counter = 0;

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
         || sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )
        counter++;
    else
        counter = 0;

    if (counter == 1)
        return true;

    return false;
}

bool KeyboardEvents::isRedo()
{
    static int counter = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
        && sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        counter++;
    else
        counter = 0;

    if (counter == 1)
        return true;

    return false;
}

int KeyboardEvents::numKeyPress(sf::Event &event)
{
    static int numKeyHits = 0;

    if (KeyboardEvents::checkKeys(event))
    {
        numKeyHits++;
    }

    return numKeyHits;
}

bool KeyboardEvents::checkKeys(sf::Event &event)
{
    static bool hitOnce = false;

    if (event.type == sf::Event::TextEntered && !hitOnce)
    {
        hitOnce = true;
        return true;
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        hitOnce = false;
        return false;
    }

    return false;
}