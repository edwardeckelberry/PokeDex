//
// Created by Edward Eckelberry on 12/13/22.
//

#include "ImageClass.h"
std::map<menuNames, sf::Texture> ImageClass::images;

ImageClass::ImageClass()
{
    texture_menubackground.loadFromFile("menu/menubackground.jpeg");
    sprite_menubackground.setTexture(texture_menubackground);

    texture_pokedexlogo.loadFromFile("menu/pokedexlogo.png");
    sprite_pokedexlogo.setTexture(texture_pokedexlogo);
    sprite_pokedexlogo.setPosition({675.5, 188});
    sprite_pokedexlogo.setScale(1.5, 1.5);

    font.loadFromFile("fonts/OpenSans-Regular.ttf");

    menuText.setString("Type \"Enter\" then press\n Enter to continue");
    menuText.setCharacterSize(52);
    menuText.setFont(font);
    menuText.setPosition({675.5, 438});
    menuText.setFillColor(sf::Color::White);
    menuText.setOutlineThickness(3);
    menuText.setOutlineColor(sf::Color::Blue);

}

void ImageClass::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(sprite_menubackground);
    window.draw(sprite_pokedexlogo);
    window.draw(menuText);
}

sf::FloatRect ImageClass::getGlobalBounds() const
{
    return sprite_menubackground.getGlobalBounds(),
    sprite_pokedexlogo.getGlobalBounds(),
    menuText.getGlobalBounds();
}

std::string ImageClass::getImagePath(menuNames name)
{
    switch(name)
    {
        case menubackground : return "menu/menubackground.jpeg";
        case pokedexlogo : return "menu/pokedexlogo.png";
    }
    return std::string();
}

void ImageClass::loadImage(menuNames name)
{
    images[name].loadFromFile(getImagePath(name));
}

sf::Texture &ImageClass::getImage(menuNames name)
{
    loadImage(name);
    return images[name];
}
