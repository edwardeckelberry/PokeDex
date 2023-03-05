//
// Created by Edward Eckelberry on 12/11/22.
//

#ifndef DROPDOWNMENU_HISTORY_H
#define DROPDOWNMENU_HISTORY_H
#include <stack>
#include "InputRecord.h"

struct HistoryNode
{
    InputRecord<std::string> memorySlot;

    explicit HistoryNode(const std::string& item)
    {
        memorySlot.updateData(item);
    }
};

class History
{
private:
    static std::stack<HistoryNode> stack;

public:
    static void push(const HistoryNode& historyNode);
    static void pop();
    static unsigned int getSize();
    static HistoryNode& top();
};

#endif //DROPDOWNMENU_HISTORY_H
