//
// Created by Edward Eckelberry on 12/11/22.
//
#ifndef DROPDOWNMENU_RECORDINGINPUTS_CPP
#define DROPDOWNMENU_RECORDINGINPUTS_CPP
#include "InputRecord.h"

template<typename Data>
InputRecord<Data>::InputRecord() = default;

template<typename Data>
void InputRecord<Data>::updateData(const Data& item)
{
    this->data = item;
}

template<typename Data>
Data InputRecord<Data>::getData() const
{
    return this->data;
}

template<typename Data>
InputRecord<Data>::InputRecord(const Data &item)
{
    this->updateData(item);
}

#endif