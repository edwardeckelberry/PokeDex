//
// Created by Edward Eckelberry on 12/11/22.
//

#include "App.h"
#include "TextBox.h"
#include "Music.h"

void App::run()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "TextBox");
    window.setFramerateLimit(120);

    Music music(MENU);
    ImageClass menu;
    TextBox textInputBox(45);

    textInputBox.setPosition({675.5, 688});

    music.playAudio();
    music.setAudioVolume(20);
    music.setLoopOn(true);
    while (window.isOpen())
    {
        sf::Event event{};

        sf::Vector2f mouse_position = (sf::Vector2f)sf::Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            window.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        textInputBox.textHandler(event, mouse_position);


        window.clear();
        window.draw(menu);
        window.draw(textInputBox);
        window.display();
    }
}
