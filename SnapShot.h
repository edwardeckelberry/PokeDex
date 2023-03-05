//
// Created by Edward Eckelberry on 12/11/22.
//

#ifndef DROPDOWNMENU_SNAPSHOT_H
#define DROPDOWNMENU_SNAPSHOT_H

#include "SFML/Graphics.hpp"

#include "History.h"


template<typename Data>
class SnapShot
{
public:
    virtual InputRecord<Data> doSnapshot() = 0;
};


#endif //DROPDOWNMENU_SNAPSHOT_H
