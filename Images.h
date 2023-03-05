//
// Created by Edward Eckelberry on 11/30/22.
//

#ifndef DROPDOWNMENU_IMAGES_H
#define DROPDOWNMENU_IMAGES_H
#include "SFML/Graphics.hpp"
#include <map>
#include "ImageNames.h"

struct Images : sf::Drawable
{
sf::Sprite sprite_bulbasaur;
sf::Sprite sprite_ivysaur;
sf::Sprite sprite_venosaur;
sf::Sprite sprite_rhyhorn;
sf::Sprite sprite_rhydon;
sf::Sprite sprite_snorlax;
sf::Sprite sprite_magikarp;
sf::Sprite sprite_gyrados;
sf::Sprite sprite_pikachu;

sf::Texture texture_bulbasaur;
sf::Texture texture_ivysaur;
sf::Texture texture_venosaur;
sf::Texture texture_rhyhorn;
sf::Texture texture_rhydon;
sf::Texture texture_snorlax;
sf::Texture texture_magikarp;
sf::Texture texture_gyrados;
sf::Texture texture_pikachu;

sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;
sf::Texture sidebar1;
sf::Sprite sidebar1Sprite;
sf::Texture sidebar2;
sf::Sprite sidebar2Sprite;

Images();
virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
sf::FloatRect getGlobalBounds() const;

static std::map<ImageNames, sf::Texture> images;
static std::string getImagePath(ImageNames name);
static void loadImage(ImageNames name);

static sf::Texture& getImage(ImageNames name);

};


#endif //DROPDOWNMENU_IMAGES_H
