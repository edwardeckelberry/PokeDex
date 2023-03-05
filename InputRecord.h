//
// Created by Edward Eckelberry on 12/11/22.
//

#ifndef DROPDOWNMENU_INPUTRECORD_H
#define DROPDOWNMENU_INPUTRECORD_H

#include "SFML/Graphics.hpp"

template<typename Data>
class InputRecord
{
private:
    Data data;

public:
    InputRecord();
    explicit InputRecord(const Data& item);

    void updateData(const Data& item);
    Data getData() const;
};

#include "InputRecord.cpp"

#endif //DROPDOWNMENU_INPUTRECORD_H
