//
// Created by Edward Eckelberry on 11/30/22.
//

#include "Images.h"
std::map<ImageNames, sf::Texture> Images::images;
std::string Images::getImagePath(ImageNames name)
{
    switch(name)
    {
        case bulbasaur: return "pokemon/bulbasaur.png";
        case ivysaur: return "pokemon/ivysaur.png";
        case venosaur: return "pokemon/venosaur.png";
        case snorlax: return "pokemon/snorlax.png";
        case rhydon: return "pokemon/rhydon.png";
        case rhyhorn: return "pokemon/rhyhorn.png";
        case magikarp: return "pokemon/magikarp.png";
        case gyrados: return "pokemon/gyrados.png";
        case pikachu: return "pokemon/pikachu.png";

    }
    return std::string();
}

void Images::loadImage(ImageNames name)
{
    images[name].loadFromFile(getImagePath(name));
}

sf::Texture &Images::getImage(ImageNames name)
{
    loadImage(name);
    return images[name];
}

Images::Images()
{
    backgroundTexture.loadFromFile("pokemon/background.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(70.0, 60.0);

    sidebar1.loadFromFile("pokemon/sibebar.png");
    sidebar1Sprite.setTexture(sidebar1);
    sidebar1Sprite.setScale(50.0, 1.0);
    sidebar1Sprite.setPosition(0,0);

    sidebar2.loadFromFile("pokemon/sibebar.png");
    sidebar2Sprite.setTexture(sidebar2);
    sidebar2Sprite.setScale(50.0, 1.5);
    sidebar2Sprite.setPosition(0,770);

    texture_bulbasaur.loadFromFile("pokemon/bulbasaur.png");
    sprite_bulbasaur.setTexture(texture_bulbasaur);
    sprite_bulbasaur.setScale(0.30, 0.30);
    sprite_bulbasaur.setPosition(20, 310);

    texture_ivysaur.loadFromFile("pokemon/ivysaur.png");
    sprite_ivysaur.setTexture(texture_ivysaur);
    sprite_ivysaur.setScale(0.2, 0.2);
    sprite_ivysaur.setPosition(300, 310);

    texture_venosaur.loadFromFile("pokemon/venosaur.png");
    sprite_venosaur.setTexture(texture_venosaur);
    sprite_venosaur.setScale(0.25, 0.3);
    sprite_venosaur.setPosition(580, 310);

    texture_snorlax.loadFromFile("pokemon/snorlax.png");
    sprite_snorlax.setTexture(texture_snorlax);
    sprite_snorlax.setScale(0.16, 0.17);
    sprite_snorlax.setPosition(860, 330);

    texture_rhydon.loadFromFile("pokemon/rhydon.png");
    sprite_rhydon.setTexture(texture_rhydon);
    sprite_rhydon.setScale(0.3, 0.3);
    sprite_rhydon.setPosition(20, 630);

    texture_rhyhorn.loadFromFile("pokemon/rhyhorn.png");
    sprite_rhyhorn.setTexture(texture_rhyhorn);
    sprite_rhyhorn.setScale(0.3, 0.3);
    sprite_rhyhorn.setPosition(300, 630);

    texture_magikarp.loadFromFile("pokemon/magikarp.png");
    sprite_magikarp.setTexture(texture_magikarp);
    sprite_magikarp.setScale(0.25, 0.25);
    sprite_magikarp.setPosition(580, 630);

    texture_gyrados.loadFromFile("pokemon/gyrados.png");
    sprite_gyrados.setTexture(texture_gyrados);
    sprite_gyrados.setScale(0.35, 0.3);
    sprite_gyrados.setPosition(860, 630);

    texture_pikachu.loadFromFile("pokemon/pikachu.png");
    sprite_pikachu.setTexture(texture_pikachu);
    sprite_pikachu.setScale(0.6, 0.6);
    sprite_pikachu.setPosition(1020, 610);
}

void Images::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(backgroundSprite);
    window.draw(sidebar1Sprite);
    window.draw(sidebar2Sprite);
    window.draw(sprite_bulbasaur);
    window.draw(sprite_ivysaur);
    window.draw(sprite_venosaur);
    window.draw(sprite_rhyhorn);
    window.draw(sprite_rhydon);
    window.draw(sprite_snorlax);
    window.draw(sprite_magikarp);
    window.draw(sprite_gyrados);
    window.draw(sprite_pikachu);
}

sf::FloatRect Images::getGlobalBounds() const
{
    return sprite_bulbasaur.getGlobalBounds(),
    sprite_ivysaur.getGlobalBounds(),
    sprite_venosaur.getGlobalBounds(),
    sprite_rhyhorn.getGlobalBounds(),
    sprite_rhydon.getGlobalBounds(),
    sprite_snorlax.getGlobalBounds(),
    sprite_magikarp.getGlobalBounds(),
    sprite_gyrados.getGlobalBounds();
    sprite_pikachu.getGlobalBounds();
}
