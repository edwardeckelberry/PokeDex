//
// Created by Edward Eckelberry on 11/28/22.
//

#ifndef DROPDOWNMENU_DROPDOWNMENU_H
#define DROPDOWNMENU_DROPDOWNMENU_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <algorithm>
class DropDownMenu : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;

    std::vector<sf::Text> dropDownText;
    std::vector<std::string> fields;
    std::vector<sf::RectangleShape> dropDownRect;
    std::vector<bool> tracker;

    bool clickedOn = false;
    bool clickedOnIt = false;
    void draw(sf::RenderTarget& window,
              sf::RenderStates states) const override;
public:
    DropDownMenu(const sf::Vector2f& sizeOfRect,
                 const std::string& header,
                 const int& numOfBoxes);

    void setRectThickness(const float& value);
    void setRectFillColor(const sf::Color& color);
    void setRectInnerColor(const sf::Color& color);
    void setPosition(sf::Vector2f position);
    void setNumOfBoxes(const int& value);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2<float> getPosition() const;

    void handleInput(sf::Event& event, sf::Vector2f& mpos);
    void addFields(const std::vector<std::string>& list);
};

#endif //DROPDOWNMENU_DROPDOWNMENU_H
