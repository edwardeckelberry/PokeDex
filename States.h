//
// Created by Edward Eckelberry on 12/11/22.
//

#ifndef DROPDOWNMENU_STATES_H
#define DROPDOWNMENU_STATES_H

#include "SFML/Graphics.hpp"
#include <map>
#include "StatesEnum.h"

class States
{
private:
    std::map<StatesEnum, bool> states;

public:
    States();

    bool checkState(StatesEnum state);
    void switchState(StatesEnum state);
    void setTrue(StatesEnum state);
    void setFalse(StatesEnum state);

};


#endif //DROPDOWNMENU_STATES_H
