//
// Created by Edward Eckelberry on 12/8/22.
//

#include "Tracker.h"

Tracker::Tracker()
{
    std::vector<DropDownMenu> order;


    std::cout << "Values in random order" << std::endl;
    print_values(order);

    std::vector<std::pair<int, std::string>> tracker;

    tracker.push_back({0, "Bulbasaur"});
    tracker.push_back({1, "Ivysaur"});
    tracker.push_back({2, "Venosaur"});
    tracker.push_back({3, "Snorlax"});
    tracker.push_back({4, "Rhydon"});
    tracker.push_back({5, "Rhyhorn"});
    tracker.push_back({6, "Magikarp"});
    tracker.push_back({7, "Gyrados"});

    std::cout << std::endl;

}
template<class T>
void Tracker::print_values(const std::vector<T> &values)
{
    for (const auto & i : values)
        //std::cout << i << " ";

    std::cout << std::endl;
}

template<class T, class S>
void Tracker::print_values(const std::vector<std::pair<T, S>> &values)
{
    std::cout << "------------Stats------------" << std::endl;
    for (const auto & i : values)
    {
        std::cout << "Name: ";
        std::cout << i << std::endl;
        std::cout << std::endl;
        std::cout << "Type: ";
        std::cout << i << std::endl;
        std::cout << "Species: ";
        std::cout << i << std::endl;
        std::cout << "Height: ";
        std::cout << i << std::endl;
        std::cout << "Weight: ";
        std::cout << std::endl;
    }
}

template<class T>
void Tracker::sort_values(std::vector<T> &values, const TrackerEnum &opr)
{
    if (opr == BULBASAUR)
    {
        std::sort(values.begin(), values.end(), std::greater<T>());
    }
    else if (opr == IVYSAUR)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
    else if (opr == VENOSAUR)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
    else if (opr == SNORLAX)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
    else if (opr == RHYHORN)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
    else if (opr == RHYHORN)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
    else if (opr == MAGIKARP)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
    else if (opr == GYRADOS)
    {
        std::sort(values.begin(), values.end(), std::less<T>());
    }
}