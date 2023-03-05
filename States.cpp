//
// Created by Edward Eckelberry on 12/11/22.
//

#include "States.h"

States::States()
{
    for (int i = 0; i < LAST_STATE; ++i)
        states.insert({static_cast<StatesEnum>(i), false});
}

bool States::checkState(StatesEnum state)
{
    return states.at(state);
}

void States::switchState(StatesEnum state)
{
    states.at(state) ^= 1;
}

void States::setTrue(StatesEnum state)
{
    states.at(state) = true;
}

void States::setFalse(StatesEnum state)
{
    states.at(state) = false;
}
