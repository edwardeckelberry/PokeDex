//
// Created by Edward Eckelberry on 12/13/22.
//

#ifndef DROPDOWNMENU_IMAGECLASS_H
#define DROPDOWNMENU_IMAGECLASS_H
#include "SFML/Graphics.hpp"
#include <map>
#include "menuNames.h"

struct ImageClass : sf::Drawable
{
    sf::Sprite sprite_menubackground;
    sf::Sprite sprite_pokedexlogo;

    sf::Texture texture_menubackground;
    sf::Texture texture_pokedexlogo;

    sf::Text menuText;
    sf::Font font;
    ImageClass();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds() const;

    static std::map<menuNames, sf::Texture> images;
    static std::string getImagePath(menuNames name);
    static void loadImage(menuNames name);

    static sf::Texture& getImage(menuNames name);
};


#endif //DROPDOWNMENU_IMAGECLASS_H
