//
// Created by Edward Eckelberry on 11/28/22.
//

#include "DropDownMenu.h"

void DropDownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(rect);
    window.draw(text);
    //std::make_heap(tracker.begin(), tracker.end());

    if (clickedOn)
    {
        for (auto& i : dropDownRect)
        {
            window.draw(i);
        }

        for (auto& i : dropDownText)
        {
            window.draw(i);
        }
    }
}

DropDownMenu::DropDownMenu(const sf::Vector2f &sizeOfRect, const std::string &header, const int& numOfBoxes)
{
    this->font.loadFromFile("fonts/OpenSans-Regular.ttf");

    this->text.setFont(font);
    this->text.setString(header);

    this->rect.setFillColor(sf::Color::Black);
    this->rect.setSize(sizeOfRect);
    this->rect.setOutlineThickness(2);

    float newWidth = rect.getGlobalBounds().width / 2;
    float newHeight = rect.getGlobalBounds().height / 2;

    float x = text.getGlobalBounds().width / 2;
    float y = text.getGlobalBounds().height / 2;

    text.setOrigin(x, y);

    text.setPosition(newWidth, newHeight);

    dropDownRect.insert(dropDownRect.begin(), numOfBoxes, rect);

    dropDownText.insert(dropDownText.begin(), numOfBoxes, text);

    //idk why this is unnecessary
    for ( auto &i : dropDownRect)
    {
        i.setFillColor(sf::Color::Black);
        i.setSize(sizeOfRect);
    }

    //puts the color of font and what it says
    for ( auto &i  : dropDownText)
    {
        i.setFont(font);
        i.setFillColor(sf::Color::White);
    }
}

void DropDownMenu::setRectThickness(const float &value)
{
    rect.setOutlineThickness(value);
}

void DropDownMenu::setRectFillColor(const sf::Color &color)
{
    rect.setOutlineColor(color);
}

void DropDownMenu::setRectInnerColor(const sf::Color &color)
{
    rect.setFillColor(color);
}

void DropDownMenu::handleInput(sf::Event& event, sf::Vector2f& mpos)
{
    //if the top menu has the mouse hovering over it and clicks it
    //change color of box and text
    if (rect.getGlobalBounds().contains(mpos))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            //color of box
            rect.setFillColor(sf::Color::Blue);
            rect.setOutlineColor(sf::Color::White);
            //color of text
            text.setFillColor(sf::Color::White);
            clickedOn = true;
        }
    }

    //if the other boxes aren't clicked make them this color
    //is necessary to getGlobalBounds rid of drop down menu when other boxes
    //are clicked
    if (!rect.getGlobalBounds().contains(mpos) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        rect.setFillColor(sf::Color::Black);
        rect.setOutlineColor(sf::Color::White);
        text.setFillColor(sf::Color::White);
        clickedOn = false;
    }

    float height1 = rect.getGlobalBounds().height;
    sf::Vector2f first_position_background_frame = rect.getPosition();

    //places the boxes under the top box
    for (auto & i : dropDownRect)
    {
        i.setPosition(first_position_background_frame.x, first_position_background_frame.y + height1);
        height1 += rect.getGlobalBounds().height;
    }

    float height2 = text.getGlobalBounds().height;
    float setHeight = rect.getGlobalBounds().height / 2;
    sf::Vector2f firstTextPos = text.getPosition();

    //drops the text into the boxes with them
    for (int i = 0; i < dropDownRect.size(); ++i)
    {
        float x = dropDownRect.at(i).getGlobalBounds().width;
        float y = dropDownRect.at(i).getGlobalBounds().height;

        x /= 2;
        y /= 2;
        //changes position of text in the drop down boxes
        dropDownText.at(i).setPosition(dropDownRect.at(i).getPosition().x + x-60,
                                          dropDownRect.at(i).getPosition().y + y);
    }

    //creates the colors for the boxes and text
    for (auto & i : dropDownRect)
    {
        if(i.getGlobalBounds().contains(mpos))
        {
            i.setOutlineColor(sf::Color::Black);
            i.setFillColor(sf::Color::Blue);
        }
        else
        {
            i.setOutlineColor(sf::Color::White);
            i.setFillColor(sf::Color::Blue);
        }
    }

    //changes color of drop down boxes when hovering/ not hovering
    for (int i = 0; i < dropDownRect.size(); ++i)
    {
        if ( dropDownRect.at(i).getGlobalBounds().contains(mpos))
        {
            dropDownRect.at(i).setOutlineColor(sf::Color::Black);
            dropDownRect.at(i).setFillColor(sf::Color::Blue);
            dropDownText.at(i).setFillColor(sf::Color::White);
        }
        else
        {
            dropDownRect.at(i).setOutlineColor(sf::Color::White);
            dropDownRect.at(i).setFillColor(sf::Color::Black);
            dropDownText.at(i).setFillColor(sf::Color::White);
        }
    }

    //so for each text in each drop down box
    //if its hovered and clicked, replace the box text on top
    //with the text in the box that was clicked
    //theres a bug here when you click the area where the
    //texts should be, it replaces it even if the top box wasn't clicked
    //the fix for this bug would be in this for loop
    for (int i = 0; i < dropDownText.size(); ++i)
    {
        if(dropDownRect[i].getGlobalBounds().contains(mpos)
           && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
            clickedOnIt = true;
        }
        else
        {
            clickedOnIt = false;
        }

        if (clickedOnIt)
        {
            this->text.setString(dropDownText[i].getString());
        }
    }

}

void DropDownMenu::setPosition(sf::Vector2f position)
{
    rect.setPosition(position);

    float x = text.getGlobalBounds().width / 2;
    float y = text.getGlobalBounds().height / 2;
    text.setOrigin(x, y);

    float new_width = rect.getGlobalBounds().width / 2;
    float new_height = rect.getGlobalBounds().height / 2;

    //sets position of text on top box
    text.setPosition(rect.getPosition().x + new_width,rect.getPosition().y + new_height);

}

void DropDownMenu::setNumOfBoxes(const int &value)
{
    dropDownRect.insert(dropDownRect.begin(), value, rect);
}

sf::FloatRect DropDownMenu::getGlobalBounds() const
{
    return rect.getGlobalBounds();
}

sf::Vector2<float> DropDownMenu::getPosition() const
{
    //was originally: this->rect.getPosition();
    return rect.getPosition();
}

void DropDownMenu::addFields(const std::vector<std::string>& list)
{
    //for x amount of boxes, set the string in each one
    for (int i = 0; i < dropDownText.size(); ++i)
    {
        dropDownText[i].setString(list[i]);
    }

}
