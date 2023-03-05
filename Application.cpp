//
// Created by Edward Eckelberry on 11/28/22.
//

#include "Application.h"
#include "DropDownMenu.h"
#include "Images.h"
#include <vector>
#include "SoundEffects.h"

void Application::run()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Pokedex");
    window.setFramerateLimit(120);

    Images m;
    Music music(MUSIC);
    SoundEffects sound(CLICK);

    DropDownMenu menu_0({300, 60}, "Menu Order", 5);
    DropDownMenu menu_1({250, 50}, "Bulbasaur", 5);
    DropDownMenu menu_6({250, 50}, "Rhydon", 5);
    DropDownMenu menu_2({250, 50}, "Ivysaur", 5);
    DropDownMenu menu_7({250, 50}, "Rhyhorn", 5);
    DropDownMenu menu_3({250, 50}, "Venusaur", 5);
    DropDownMenu menu_8({250, 50}, "Magikarp", 5);
    DropDownMenu menu_4({250, 50}, "Snorlax", 5);
    DropDownMenu menu_9({250, 50}, "Gyarados", 5);
    DropDownMenu menu_5({250, 50}, "Pikachu", 5);
    menu_0.addFields({"1st Box: Name", "2nd Box: Type", "3rd box: Species","4th box: Height", "5th box: Weight"}),
    menu_1.addFields({"Bulbasaur", "Grass, Poison", "Seed Pokemon","2'4\"", "15.2 lbs"}),
    menu_6.addFields({"Rhydon", "Ground, Rock", "Drill ", "6'3\"","264.6 lbs"}),
    menu_2.addFields({"Ivysaur", "Grass, Poison", "Seed","3'03\"", "28.7 lbs"}),
    menu_7.addFields({"Rhyhorn", "Ground, Rock", "Spikes","3'03\"", "253.3 lbs"}),
    menu_3.addFields({"Venusaur", "Grass, Poison", "Seed","6'07\"", "220.5 lbs"}),
    menu_8.addFields({"Magikarp", "Water", "Fish","2'11\"", "22.0 lbs"}),
    menu_4.addFields({"Snorlax", "Normal", "Sleeping","6'11\"", "1014.1 lbs"}),
    menu_9.addFields({"Gyarados", "Water, Flying", "Atrocious","21'04\"", "518.1 lbs"});
    menu_5.addFields({"Pikachu", "Electric", "Mouse", "1'04\"", "13.2 lbs"});

    std::vector<DropDownMenu> manyBoxes;

    menu_0.setPosition({1290, 3}),
    menu_1.setPosition({20, 250}),
    menu_2.setPosition({300, 250}),
    menu_3.setPosition({580, 250}),
    menu_4.setPosition({860, 250}),
    menu_6.setPosition({20, 570}),
    menu_7.setPosition({300, 570}),
    menu_8.setPosition({580, 570}),
    menu_9.setPosition({860, 570}),
    menu_5.setPosition({1140, 570});

    manyBoxes.push_back(menu_0);
    manyBoxes.push_back(menu_1);
    manyBoxes.push_back(menu_2);
    manyBoxes.push_back(menu_3);
    manyBoxes.push_back(menu_4);
    manyBoxes.push_back(menu_5);
    manyBoxes.push_back(menu_6);
    manyBoxes.push_back(menu_7);
    manyBoxes.push_back(menu_8);
    manyBoxes.push_back(menu_9);

    music.playAudio();
    music.setAudioVolume(20);
    music.setLoopOn(true);

    while (window.isOpen())
    {
        sf::Event event{};

        sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)
            || sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                sound.playAudio();
                sound.setAudioVolume(30);
                sound.setLoopOn(false);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        for (auto&i : manyBoxes)
        {
            i.handleInput(event, mouse_position);
        }

        window.clear();
        window.draw(m);

        for (const auto&i: manyBoxes)
        {
            window.draw(i);
        }

        window.display();
    }
}