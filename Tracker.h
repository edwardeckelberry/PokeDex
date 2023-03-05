//
// Created by Edward Eckelberry on 12/8/22.
//

#ifndef DROPDOWNMENU_TRACKER_H
#define DROPDOWNMENU_TRACKER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "TrackerEnum.h"
#include "DropDownMenu.h"

class Tracker
{
private:

public:
    Tracker();
    template<class T>
    void print_values(const std::vector<T>& values);
    template<class T, class S>
    void print_values(const std::vector<std::pair<T, S>>& values);
    template<class T>
    void sort_values(std::vector<T>& values, const TrackerEnum& opr);

};


#endif //DROPDOWNMENU_TRACKER_H
